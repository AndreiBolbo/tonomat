//
// Created by MSI on 20/04/2022.
//

#include "Produs.h"
#include "cstring";
Produs::Produs() {
    cod = 0;
    nume = nullptr;
    pret = 0;


}
Produs::Produs(int cod, char *nume, float pret, PrType tip) {
    this->cod = cod;
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->pret = pret;
    this->tip = tip;
}
Produs::Produs(const Produs &p) {
    this->cod = p.cod;
    nume = new char [strlen(p.nume)+1];
    strcpy(nume,p.nume);
    pret = p.pret;
    tip = p.tip;
}

Produs &Produs::operator=(const Produs &p) {
    if(this != &p)
    {
        this->cod = p.cod;
        nume = new char [strlen(p.nume)+1];
        strcpy(nume,p.nume);
        pret = p.pret;
        tip = p.tip;
        return *this;
    }

}

int Produs::getCod() const {
    return cod;

}
float Produs::getPret() const {
    return pret;
}

char *Produs::getnume() const {
    return nume;
}

PrType Produs::get_prdct() {
    return tip;
}

void Produs::setCod(int cod) {
    this->cod  = cod;
}

void Produs::setType(PrType t) {
    this->tip = t;
}
Produs::~Produs() {
    delete []nume;
    nume = nullptr;
}
void Produs::setNume(char *nume) {
    this->nume = new char [strlen(nume)+1];
    strcpy(this->nume,nume);
}

void Produs::setPret(float pret) {
    this->pret = pret;
}
bool Produs::operator==(const Produs &p){
    return(cod==p.cod && pret ==p.pret && strcmp(nume,p.nume)==0 && tip ==p.tip);
}
ostream& operator<<(ostream &os, Produs &t){
    os <<"categoria:"<<t.tip<<" nume:"<<t.nume<<" cod:"<<t.cod<<"pret:"<<t.pret;
    return os;
}