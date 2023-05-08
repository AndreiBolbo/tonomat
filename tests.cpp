//
// Created by MSI on 20/04/2022.
//
#include "Service.h"
#include "tests.h"
#include "Produs.h"
#include "Repo.h"
#include "cstring"
#include "cassert"
void test_produs()
{
    char *nume = new char[20];
    strcpy(nume, "Pop cola");
    PrType type= suc;
    Produs p(12,nume,4,type);
    assert(p.getPret() ==4);
    assert(p.getCod() ==12);
    assert(strcmp(p.getnume(),nume)==0);
    char *num = new char[20];
    strcpy(num, "Coca cola");
    Produs t(10,num,3, type);
    assert(p.get_prdct()==2);
    assert(strcmp(p.getnume(),nume)==0);
    assert(t.getPret()==3);
    t.setPret(4.5);
    assert(t.getPret()==4.5);
    t.setNume(nume);
    assert(strcmp(t.getnume(),nume)==0);
}
void test_service()
{
    Repo r;
    Service s(r);
    char *num = new char[20];
    strcpy(num, "snickers");
    s.add_product(cioco,12,num,4);
    vector <Produs> p = s.read();

    assert(p.size()==1);
    strcpy(num, "pop cola");
    s.update_product(suc,12,num, 5);
    vector <Produs> t = s.read();
    assert(t.size()==1);
    assert(t[0].getPret()==5);
    assert(t[0].get_prdct()==2);
    char *nume = new char[20];
    strcpy(nume, "schweps");
    s.add_product(cioco,15,nume,3);
    assert(s.read().size()==2);
    s.del_product(cioco,15,nume,3);
    assert(s.read().size()==1);

}
void test_repo()
{
    char *nume = new char[20];
    strcpy(nume, "Pop cola");
    PrType type= suc;
    Produs p(12,nume,4,type);
    char *num = new char[20];
    strcpy(num, "Coca cola");
    Produs t(10,num,3, type);
    Repo repo;
    repo.add_item(p);
    assert(repo.get_size()==1);
    assert(repo.get_item_poz(0).getPret()==4);
    repo.add_item(t);
    assert(repo.get_size()==2);
    assert(strcmp(repo.get_item_poz(1).getnume(),num)==0);
    repo.del(0);
    assert(repo.get_size()==1);
    assert(repo.get_item_poz(0).getPret()==3);
}
void test_all()
{
    test_service();
    test_produs();
    test_repo();
}