//
// Created by MSI on 26/04/2022.
//

#ifndef UNTITLED7_UI_H
#define UNTITLED7_UI_H

#include "Service.h"
class Ui {
private:
    Service &service;
public:
    Ui(Service &service);
    ~Ui();
    void run_menu();
private:

    void displayMenu();
    vector<string> desparteComanda(string linie);
    void add_product(PrType tip,int cod,char *nume,float pret);
    void update_product(PrType tip,int cod,char *nume,float pret);
    void del_product(PrType tip,int cod,char *nume,float pret);
    void show_all();
};


#endif //UNTITLED7_UI_H
