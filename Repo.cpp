//
// Created by MSI on 20/04/2022.
//

#include "Repo.h"
Repo::Repo() = default;

 unsigned int Repo::get_size() {
    return produse.size();
}

vector<Produs> Repo::get_all() {
    return produse;
}

void Repo::add_item(Produs &p) {
    produse.push_back(p);
}

Produs Repo::get_item_poz(int poz) {
    return produse[poz];
}

void Repo::del(int poz) {
    produse.erase(produse.begin()+poz);
 }

void Repo::update(int poz, Produs &p) {
     produse[poz].setNume(p.getnume());
    produse[poz].setPret(p.getPret());
    produse[poz].setCod(p.getCod());
    produse[poz].setType(p.get_prdct());

 }

Repo &Repo::operator=(const Repo &r) {
     produse = r.produse;
 }
Repo::~Repo() =default;
