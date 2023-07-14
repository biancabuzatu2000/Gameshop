#include "joc.h"

Joc::Joc(string cod_joc, string nume_joc, string categorie_joc, string sub_categorie_joc, double pret, int cantitate, int bundle)
{
    cod_joc_=cod_joc;
    nume_joc_=nume_joc;
    categorie_joc_=categorie_joc;
    sub_categorie_joc_=sub_categorie_joc;
    pret_=pret;
    cantitate_=cantitate;
    bundle_=bundle;
}

string Joc::getCod()
{
    return cod_joc_;
}

void Joc::setCod(string cod_joc)
{
    cod_joc_=cod_joc;
}


string Joc::getNume()
{
    return nume_joc_;
}

void Joc::setNume(string nume_joc)
{
    nume_joc_=nume_joc;
}

string Joc::getCategorie()
{
    return categorie_joc_;
}

void Joc::setCategorie(string categorie_joc)
{
    categorie_joc_=categorie_joc;
}

string Joc::getSubCategorie()
{
    return sub_categorie_joc_;
}

void Joc::setSubCategorie(string sub_categorie_joc)
{
    sub_categorie_joc_=sub_categorie_joc;
}


double Joc::getPret()
{
    return pret_;
}

void Joc::setPret(double pret)
{
    pret_=pret;
}


int Joc::getCantitate()
{
    return cantitate_;
}

void Joc::setCantitate(int cantitate)
{
    cantitate_=cantitate;
}

int Joc::getBundle()
{
    return bundle_;
}

void Joc::setBundle(int bundle)
{
    bundle_=bundle;
}

