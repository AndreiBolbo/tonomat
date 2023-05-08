//
// Created by MSI on 20/04/2022.
//

#ifndef UNTITLED7_REPO_H
#define UNTITLED7_REPO_H

#include "vector"
#include "Produs.h"
using namespace std;
class Repo {
private:
    //adauga aici atribut de rest monede
    vector<Produs> produse;
public:
    Repo();
    ~Repo();
    void add_item(Produs &p);
    unsigned int get_size();
    Produs get_item_poz(int poz);
    vector<Produs> get_all();
    void del(int poz);
    void update(int poz, Produs &p);
    Repo& operator=(const Repo &r);
};


#endif //UNTITLED7_REPO_H
