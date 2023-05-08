//
// Created by MSI on 25/04/2022.
//

#ifndef UNTITLED7_SERVICE_H
#define UNTITLED7_SERVICE_H
#include "vector"
#include "Repo.h"
class Service {
private:
    Repo repository;
public:
    Service(Repo &r);
    ~Service();
    Service(const Service &s);
    void add_product(PrType t, int cod, char *nume, float pret);
    void update_product(PrType t, int cod, char *nume, float pret);
    void del_product(PrType t, int cod, char *nume, float pret);
    vector <Produs> read();

};


#endif //UNTITLED7_SERVICE_H
