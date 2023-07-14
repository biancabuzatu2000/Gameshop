#include <iostream>
#include <fstream>
#include "../comun/joc.cpp"
#include <stdlib.h>
#include <vector>

vector<Joc> lista_jocuri;

using namespace std;


void citire_jocuri()
{
    ifstream fis("../comun/stoc.txt", ios::in);
    while(!fis.eof())
    {
        string cod, nume, categorie, sub_categorie;
        double pret;
        fis>>cod; fis.ignore();
        getline(fis, nume);
        getline(fis, categorie);
        getline(fis, sub_categorie);
        fis>>pret;
        if(fis.eof())break;
        lista_jocuri.push_back(Joc(cod,nume,categorie,sub_categorie,pret));
    }
    fis.close();
}

void afisare_jocuri()
{
  cout<<"Afisare lista jocuri \n\n";
  for(auto& element:lista_jocuri)
  {
    cout<<"Cod joc : "<<element.getCod()<<"\n";
    cout<<"Nume joc : "<<element.getNume()<<"\n";
    cout<<"Categorie joc : "<<element.getCategorie()<<"\n";
    cout<<"Subcategorie joc : "<<element.getSubCategorie()<<"\n";
    cout<<"Pret joc : "<<element.getPret()<<"\n\n";
  }

}



int main()
{
    citire_jocuri();
    afisare_jocuri();
   return 0;
}
