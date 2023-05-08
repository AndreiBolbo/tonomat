//
// Created by MSI on 20/04/2022.
//

#ifndef UNTITLED7_PRODUS_H
#define UNTITLED7_PRODUS_H
#include "iostream"
using namespace std;
enum PrType{
    croisant ,
    cioco,
    suc,
    no_type
};
class Produs {
private:
    PrType tip;
    int cod;
    char *nume;
    float pret;
public:
    Produs();
    Produs(int cod,char *nume,float pret, PrType tip);
    Produs(const Produs &p);
    ~Produs();
    Produs& operator=(const Produs &p);
    PrType get_prdct();
    int getCod() const;
    float getPret() const;
    char *getnume() const;
    void setCod(int cod);
    void setPret(float pret);
    void setNume(char *nume);
    void setType(PrType t);
    friend ostream& operator<<(ostream &os, Produs &p);
    bool operator==(const Produs &p);

};


#endif //UNTITLED7_PRODUS_H
