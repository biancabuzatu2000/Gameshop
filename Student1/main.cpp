#include <iostream>
#include <fstream>
#include "../comun/joc.cpp"
#include <stdlib.h>
#include <vector>


using namespace std;

vector<Joc> lista_jocuri;


void adaugare_joc(Joc j)
{
    ofstream fis("../comun/stoc.txt", ios::app);

    fis<<j.getCod()<<"\n";
    fis<<j.getNume()<<"\n";
    fis<<j.getCategorie()<<"\n";
    fis<<j.getSubCategorie()<<"\n";
    fis<<j.getPret()<<"\n";
    fis<<j.getCantitate()<<"\n";
    fis<<j.getBundle()<<"\n";
    fis.close();
}


void pauza()
{
        std::cin.ignore(1024, '\n');
        std::cout << "Press enter to continue ...";
        std::cin.get();
}

void salvare_lista_jocuri()
{
    ofstream fiso("../comun/stoc.txt", ios::out);

    for(auto& element:lista_jocuri)
    {
        fiso<<element.getCod()<<"\n";
        fiso<<element.getNume()<<"\n";
        fiso<<element.getCategorie()<<"\n";
        fiso<<element.getSubCategorie()<<"\n";
        fiso<<element.getPret()<<"\n";
        fiso<<element.getCantitate()<<"\n";
        fiso<<element.getBundle()<<"\n\n";
    }
    fiso.close();
}



void afisare_lista_jocuri()
{

    ifstream fis("../comun/stoc.txt", ios::in);
    cout<<endl<<"Lista jocurilor din stocul magazinului : "<<endl;
    while(!fis.eof())
    {
        string cod, nume, categorie, sub_categorie;
        double pret;
        int cantitate, bundle;
        fis>>cod; fis.ignore();
        getline(fis, nume);
        getline(fis, categorie);
        getline(fis, sub_categorie);
        fis>>pret;
        fis>>cantitate;
        fis>>bundle;
        if(fis.eof())break;

        cout<<"Cod joc : "<<cod<<"\n";
        cout<<"Nume joc : "<<nume<<"\n";
        cout<<"Categorie joc : "<<categorie<<"\n";
        cout<<"Subcategorie joc : "<<sub_categorie<<"\n";
        cout<<"Pret joc : "<<pret<<"\n";
        cout<<"Cantitate : "<<cantitate<<"\n";
        cout<<"Bundle : "<<bundle<<"\n\n";
    }
    fis.close();
}


int main()
{
    int iesire=0;
    string cod_joc, nume, categorie, subcategorie, cod;
    double pret;
    int gasit=0;
    int cantitate, bundle;
    ifstream fisi("../comun/stoc.txt", ios::in);

    while(!iesire)
    {
        system("clear");
        cout<<"****************************** Meniul aplicatiei ******************************"<<endl;
        cout<<"========> (a)daugare joc "<<endl;
        cout<<"========> (s)terge joc "<<endl;
        cout<<"========> (m)odifica joc "<<endl;
        cout<<"========> a(d)auga oferte de bundle packs "<<endl;
        cout<<"========> s(t)erge oferte de bundle packs "<<endl;
        cout<<"========> (v)izualizeaza cele mai cumparate jocuri "<<endl;
        cout<<"========> (l)isteaza pe ecran oferta de jocuri "<<endl;

        cout<<"========> (e)xit "<<endl;
        char optiune;
        cout<<endl<<"Precizati optiunea pe care ati ales-o ";
        cin>>optiune;
        switch(optiune)
        {
            case 'a':
                        cout<<"Ati ales operatia de adaugare a unui joc in stocul magazinului "<<endl;
                        cout<<"Dat codul jocului : ";cin>>cod_joc;
                        std::cin.ignore();
                        std::cout<<"Dati numele jocului : "; getline(cin, nume);
                        cout<<"Din ce categorie este jocul : ";getline(cin, categorie);
                        cout<<"Subcategoria jocului : "; getline(cin,subcategorie);
                        cout<<"Pret : ";cin>>pret;
                        cout<<"Cantitate : ";cin>>cantitate;
                        cout<<"Bundle packs (0/1) ";cin>>bundle;
                        adaugare_joc(Joc(cod_joc,nume,categorie,subcategorie,pret, cantitate, bundle));

                        break;
            case 's':

                        cout<<"Stergerea unui joc din stocul magazinului  "<<endl;
                        cout<<"Dat codul jocului : ";cin>>cod_joc;
                        std::cin.ignore();


                        while(!fisi.eof())
                        {

                            fisi>>cod; fisi.ignore();
                            getline(fisi, nume);
                            getline(fisi, categorie);
                            getline(fisi, subcategorie);
                            fisi>>pret;
                            fisi>>cantitate;
                            fisi>>bundle;
                            if(fisi.eof())break;
                            if(cod!=cod_joc)
                                lista_jocuri.push_back(Joc(cod,nume,categorie,subcategorie,pret, cantitate, bundle));
                            else
                                gasit=1;
                        }
                        fisi.close();
                        if(gasit==0)
                            cout<<"Jocul pe care doriti sa-l stergeti nu exista !";
                        else
                            salvare_lista_jocuri();
                        break;
            case 'm':
                        cout<<"Ati ales operatia de modificare a datelor unui joc aflat in stocul magazinului "<<endl;
                        cout<<"Dat codul jocului : ";cin>>cod_joc;
                        std::cin.ignore();
                        gasit=0;
                        while(!fisi.eof())
                        {

                            fisi>>cod; fisi.ignore();
                            getline(fisi, nume);
                            getline(fisi, categorie);
                            getline(fisi, subcategorie);
                            fisi>>pret;
                            fisi>>cantitate;
                            fisi>>bundle;
                            if(fisi.eof())break;
                            if(cod!=cod_joc)
                                    lista_jocuri.push_back(Joc(cod,nume,categorie,subcategorie,pret, cantitate, bundle));
                            else
                            {
                                gasit=1;
                                std::cout<<"Dati numele jocului : "; getline(cin, nume);
                                cout<<"Din ce categorie este jocul : ";getline(cin, categorie);
                                cout<<"Subcategoria jocului : "; getline(cin,subcategorie);
                                cout<<"Pret : ";cin>>pret;
                                cout<<"Cantitatea : "; cin>>cantitate;
                                cout<<"Oferta bundle (0/1) "; cin>>bundle;
                                lista_jocuri.push_back(Joc(cod,nume,categorie,subcategorie,pret, cantitate, bundle));
                            }
                        }
                        fisi.close();
                        if(gasit==0)
                            cout<<"Jocul pe care doriti sa-l modificati nu exista !";
                        else
                            salvare_lista_jocuri();
                        break;
            case 'd':
                        cout<<"Ati ales operatia de adaugare a unui produs in lista bundle packs : "<<endl;
                        cout<<"Dat codul jocului : ";cin>>cod_joc;
                        std::cin.ignore();
                        gasit=0;
                        while(!fisi.eof())
                        {

                            fisi>>cod; fisi.ignore();
                            getline(fisi, nume);
                            getline(fisi, categorie);
                            getline(fisi, subcategorie);
                            fisi>>pret;
                            fisi>>cantitate;
                            fisi>>bundle;
                            if(fisi.eof())break;
                            if(cod!=cod_joc)
                                    lista_jocuri.push_back(Joc(cod,nume,categorie,subcategorie,pret, cantitate, bundle));
                            else
                            {
                                gasit=1;
                                lista_jocuri.push_back(Joc(cod,nume,categorie,subcategorie,pret, cantitate, 1));
                            }
                        }
                        fisi.close();
                        if(gasit==0)
                            cout<<"Jocul pe care doriti sa-l adaugati in lista bundle nu exista !";
                        else
                            salvare_lista_jocuri();
                        fisi.close();
                        break;
            case 't':
                        cout<<"Ati ales operatia de eliminare a unui produs din lista bundle packs : "<<endl;
                        cout<<"Dat codul jocului : ";cin>>cod_joc;
                        std::cin.ignore();
                        gasit=0;
                        while(!fisi.eof())
                        {

                            fisi>>cod; fisi.ignore();
                            getline(fisi, nume);
                            getline(fisi, categorie);
                            getline(fisi, subcategorie);
                            fisi>>pret;
                            fisi>>cantitate;
                            fisi>>bundle;
                            if(fisi.eof())break;
                            if(cod!=cod_joc)
                                    lista_jocuri.push_back(Joc(cod,nume,categorie,subcategorie,pret, cantitate, bundle));
                            else
                            {
                                gasit=1;
                                lista_jocuri.push_back(Joc(cod,nume,categorie,subcategorie,pret, cantitate, 0));
                            }
                        }
                        fisi.close();
                        if(gasit==0)
                            cout<<"Jocul pe care doriti sa-l eliminati din lista bundle nu exista !";
                        else
                            salvare_lista_jocuri();
                        fisi.close();
                        break;
            case 'v':
                        cout<<"vizualizeaza cele mai cumparate jocuri "<<endl;
                        break;
            case 'e':
                        cout<<"exit !"<<endl;
                        iesire=1;
                        break;
            case 'l':

                        afisare_lista_jocuri();
                        break;
            default:
                    cout<<"Alegeti optiunile (a/m/d/t/v/e)"<<endl;
        }
        pauza();
    }
    return 0;
}
