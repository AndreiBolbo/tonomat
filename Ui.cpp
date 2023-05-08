//
// Created by MSI on 26/04/2022.
//
#include "sstream"
#include "Ui.h"
#include "cstring"
Ui::Ui(Service &s) :service(s){

}
vector<string> Ui::desparteComanda(string linie)
{
    vector<string> rezultat;
    stringstream ss(linie);
    string token;
    while (getline(ss, token, ' '))
    {
        rezultat.push_back(token);
    }
    return rezultat;
}
Ui::~Ui()=default;

void Ui::del_product(PrType tip, int cod, char *nume, float pret) {
    service.del_product(tip,cod,nume,pret);
}

void Ui::update_product(PrType tip, int cod, char *nume, float pret) {
    service.update_product(tip,cod,nume,pret);
}

void Ui::add_product(PrType tip, int cod, char *nume, float pret) {
    service.add_product(tip,cod,nume,pret);
}

void Ui::run_menu() {
    string cmd;
    bool optiuneGresita;
    while (true) {
        this->displayMenu();
        getline(cin, cmd);
        vector<string> parametriCmd = desparteComanda(cmd);
        optiuneGresita = true;
        if (parametriCmd[0] == "adauga") {
            if (parametriCmd.size() != 8) {
                cout << "Format comanda gresita!";
            } else {
                PrType t;
                if( parametriCmd[4] =="suc")
                    t = suc;
                if( parametriCmd[4] =="cioco")
                    t = cioco;
                if(parametriCmd[4] == "croisant")
                    t = croisant;
                if(parametriCmd[4] == "notype")
                    t= no_type;
                this->add_product(t, stoi(parametriCmd[5]), const_cast<char *>(parametriCmd[6].c_str()), stoi(parametriCmd[7]));
                optiuneGresita = false;
            }
        }
        if (parametriCmd[0] == "eliminare") {
            if (parametriCmd.size() != 8) {
                cout << "Format comanda gresita!";
            } else {
                PrType t;
                if( parametriCmd[4] =="suc")
                    t = suc;
                if( parametriCmd[4] =="cioco")
                    t = cioco;
                if(parametriCmd[4] == "croisant")
                    t = croisant;
                if(parametriCmd[4] == "notype")
                    t= no_type;
                this->del_product(t,stoi(parametriCmd[5]), const_cast<char *>(parametriCmd[6].c_str()), stoi(parametriCmd[7]));
                optiuneGresita = false;
            }
        }
        if (parametriCmd[0] == "inlocuire") {
            if (parametriCmd.size() != 11) {
                cout << "Format comanda gresita!";
            } else {
                PrType t;
                if( parametriCmd[4] =="suc")
                    t = suc;
                if( parametriCmd[4] =="cioco")
                    t = cioco;
                if(parametriCmd[4] == "croisant")
                    t = croisant;
                if(parametriCmd[4] == "notype")
                    t= no_type;
                this->update_product(t,stoi(parametriCmd[5]), const_cast<char *>(parametriCmd[6].c_str()), stoi(parametriCmd[7]));
                optiuneGresita = false;
            }
        }


        if (parametriCmd[0] == "listeaza" ) {
            this->show_all();
            optiuneGresita = false;
        }

            if (parametriCmd[0] == "iesire") {
                break;
            }

            if (optiuneGresita) {
                cout << "Optiune gresita! Reincercati: ";
            }
        }
    }
void Ui::show_all() {
    vector <Produs> v = service.read();
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
}
void Ui::displayMenu()
{
    cout << " adauga produs in tonomat {tip:croisant ,cioco, suc,no_type} {cod} {nume} {pret}"<< endl;
    cout << " Tastati codul produsului dorit {cod} Note:aparatul nu dispune mereu de rest  "<< endl;
    cout << " eliminare produs din tonomat {tip:croisant ,cioco, suc,no_type} {cod} {nume} {pret} " << endl;
    cout<<"inlocuire produs tonomat cu {tip:croisant ,cioco, suc,no_type} {cod} {nume} {pret} dupa codul tastat"<<endl;
    cout<<"listeaza - show_all"<<endl;
    cout << " iesire" << endl;
}
