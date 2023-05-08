//
// Created by MSI on 25/04/2022.
//

#include "Service.h"
#include "Produs.h"
Service::Service(Repo &r) {
    repository= r;
}
Service::Service(const Service &s) {
    repository = s.repository;
}

void Service::add_product(PrType t, int cod, char *nume, float pret) {
    Produs product(cod,nume,pret,t);
    repository.add_item(product);
}

void Service::update_product(PrType t, int cod, char *nume, float pret) {
    Produs product(cod,nume,pret,t);
    for(int i=0;i<repository.get_size();i++)
        if(repository.get_item_poz(i).getCod()==product.getCod())
            repository.update(i,product);
}

vector<Produs> Service::read() {
    return repository.get_all();
}

void Service::del_product(PrType t, int cod, char *nume, float pret) {
    Produs product(cod,nume,pret,t);
    for(int i=0;i<repository.get_size();i++)
        if(repository.get_item_poz(i)==product)
            repository.del(i);
}
Service::~Service() =default;