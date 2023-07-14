#include<iostream>

using namespace std;

#ifndef __JOC__
#define __JOC__

class Joc
{
    private:
        string cod_joc_;
        string nume_joc_;
        string categorie_joc_;
        string sub_categorie_joc_;
        double pret_;
        int cantitate_;
        int bundle_;

    public:
        Joc(string, string, string, string, double, int, int);

        string getCod();
        void setCod(string);

        string getNume();
        void setNume(string);

        string getCategorie();
        void setCategorie(string);
        string getSubCategorie();
        void setSubCategorie(string);
        double getPret();
        void setPret(double);
        int getCantitate();
        void setCantitate(int);
        int getBundle();
        void setBundle(int);

};
#endif
