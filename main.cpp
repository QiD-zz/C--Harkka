
#include <cstdlib>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <typeinfo>

#include "Sarake.h"
#include "Tietokanta.h"
#include "Otsake.h"
#include "Taulu.h"
#include "virhekomento.h"
using namespace std;


string const SELECT = "SELECT";
string const CREATE = "CREATE";
string const DROP = "DROP";
string const TABLE = "TABLE";
string const SHOW = "SHOW";
string const TABLES = "TABLES";
string const INSERT = "INSERT";
string const INTO = "INTO";
string const VALUES = "VALUES";
string const DELETE = "DELETE";
string const FROM = "FROM";
string const WHERE = "WHERE";
string const QUIT = "QUIT";
string const TAHTI = "*";

void pienennaKasky(string &kasky)
{
    for (int i = 0; i < kasky.size(); i++) {            
        kasky[i] = tolower(kasky[i]);       
    }
}

void suurennaKasky(string &kasky)
{
    for (int i = 0; i < kasky.size(); i++) {            
        kasky[i] = toupper(kasky[i]);       
    }
}

string etsiKasky(char rivi[])
{
    int j = 0;
    string paluu("");
    for (int i = 0; i < 255; i++) {
        if (rivi[i] == '(')
        {
            i++;
        }
        if (rivi[i] == ' ' || rivi[i] == ',' || rivi[i] == ')')
        {
            break;
        }
        else
        {
           string a(" ");
            paluu.append(a);
            paluu[j] = rivi[i];
            j++;
        }



    }

}


int main(int argc, char** argv) {
    
    bool lopetus = false;
    string kasky;
    string taulunNimi;
    string sarakeNimi;
    string tyyppi;
    string kokoKasky;
    string rivi;
    Tietokanta db;
    ifstream tiedosto(argv[1]);   
    ofstream tiedostoUlos(argv[2]);
   /* while (tiedosto >> rivi)
    {
        cout << rivi;
    }
    lopetus = true;*/
    
    while (!lopetus)
    {
        tiedosto >> kasky;
      //  suurennaKasky(kasky);
        kokoKasky.append(kasky);
        
        if (kasky == CREATE)
        {
            tiedosto >> kasky;
      //      suurennaKasky(kasky);
            kokoKasky.append(" ");
            kokoKasky.append(kasky);
            
            if (kasky == TABLE)
            {
                vector < Otsake *> sarakkeet;
                bool sarakkeita = true;
                tiedosto >> taulunNimi;
                kokoKasky.append(" ");
                kokoKasky.append(taulunNimi);

                while (sarakkeita == true)
                {                                                    
                    tiedosto >> sarakeNimi;    

                    kokoKasky.append(" ");
                    kokoKasky.append(sarakeNimi);

                    if (sarakeNimi[0] == '(')               
                    {
                    sarakeNimi = sarakeNimi.substr(1, sarakeNimi.size()-1);                               
          
                    }
                    tiedosto >> tyyppi;  
                    kokoKasky.append(" ");
                    kokoKasky.append(tyyppi);
                  
                    if (tyyppi[tyyppi.size()-1] == ',')
                    {
                        tyyppi = tyyppi.substr(0, tyyppi.size()-1);
                    }
                     if (tyyppi[tyyppi.size()-1] == ')')
                    {
                        tyyppi = tyyppi.substr(0, tyyppi.size()-1);
                        sarakkeita = false;
                    }
                    if (tyyppi == INT)
                    {
                        sarakkeet.push_back(new Sarake<int>(sarakeNimi, taulunNimi));
                    }
                    if (tyyppi == FLOAT)
                    {
                        sarakkeet.push_back(new Sarake<float>(sarakeNimi, taulunNimi));
                    }
                    if (tyyppi == CHAR)
                    {
                        sarakkeet.push_back(new Sarake<char *>(sarakeNimi, taulunNimi));
                    }

                }
                Taulu *taulu = new Taulu(taulunNimi,sarakkeet, sarakkeet.size());
                for (int i = 0; i < sarakkeet.size(); i++) {
                    cout << "TÄSSÄ TEHDÄÄN " << sarakkeet[i]->kerroTyyppi() << endl;


                }

                db.lisaaTaulu(*taulu);
                kokoKasky = "";
            }
        }
            
        if (kasky == DROP)
        {              
            tiedosto >> kasky;
         //   suurennaKasky(kasky);
            if (kasky == TABLE)
            {
                tiedosto >> taulunNimi;
                db.poistaTaulu(taulunNimi);
            }   
        }
        
        if (kasky == SHOW)
        {
            tiedosto >> kasky;
        //    suurennaKasky(kasky);
            if (kasky == TABLES)
            {
                for (int i = 0; i < db.montakoTaulua(); i++) {
                    tiedostoUlos << db.tulostaTaulunNimi(i);

                }
                tiedostoUlos << endl << endl;
            }           
        }
            
        if (kasky == INSERT)
        {              
            tiedosto >> kasky;
          //  suurennaKasky(kasky);
             cout << kasky << endl;
            kokoKasky.append(" "); 
            kokoKasky.append(kasky);
               
            try
            {
               if (kasky == INTO)      
               { 
                   tiedosto >> taulunNimi;   
                   kokoKasky.append(" ");
                   kokoKasky.append(taulunNimi);
                   cout << kasky << endl;
                   bool sarakkeita = true;
                   vector <string> sarakkeidenNimet;
                   while (sarakkeita)
                   {                             
                       tiedosto >> sarakeNimi;   
                       cout << sarakeNimi << endl;
                       kokoKasky.append(" ");
                       kokoKasky.append(sarakeNimi);
                       
                       if (sarakeNimi[0] == '(')               
                       {
                       sarakeNimi = sarakeNimi.substr(1, sarakeNimi.size());


                       }
                       if (sarakeNimi[sarakeNimi.length()-1] == ',')               
                       {
                       sarakeNimi = sarakeNimi.substr(0,sarakeNimi.size()-1);                                       
                       }
                       if (sarakeNimi[sarakeNimi.length()-1] == ')')               
                       {
                       sarakeNimi = sarakeNimi.substr(0,sarakeNimi.size()-1);
                       sarakkeita = false;                                 

                       }
                       sarakkeidenNimet.push_back(sarakeNimi);
                   }

                   tiedosto >> kasky;   
                   cout << kasky << endl;
                   kokoKasky.append(" ");
                   kokoKasky.append(kasky);
                   
                //   suurennaKasky(kasky);
                   bool virheHavaittu = false;
                   bool tauluOnOlemassa = true;
                   if (db.onkoTaulua(taulunNimi) == false)
                   {
                       virheHavaittu = true;
                       tauluOnOlemassa = false;
                       cout << "taulua ei ole??????\n";
                   }

                   Taulu taulu;
                   vector <Otsake *> taulunSarakkeet;
                   if (tauluOnOlemassa)
                   {
                      taulu = db.haeTaulu(taulunNimi);
                      taulunSarakkeet = taulu.kerroSarakkeet();
                   }
                   
                   vector <Otsake *> uudetSarakkeet;
                   if (kasky == VALUES)     
                   { 
                           
                       string arvo;
                       int kierros = 0;
                       bool arvojaOn = true;
                       while (arvojaOn == true)
                       {
                           cout << "SARAKKEITA ON " << taulunSarakkeet.size() << endl;
                           tiedosto >> arvo;
                           cout << arvo;
                           kokoKasky.append(" ");
                           kokoKasky.append(arvo);
                             
                           if (arvo[0] == '(')
                           {
                               arvo = arvo.substr(1, arvo.size());
                           }
                           if (arvo[arvo.size()-1] == ',')               
                           {
                               arvo = arvo.substr(0, arvo.size()-1);                             
                           }
                           if (arvo[arvo.size()-1] == ')')
                           {

                               arvo = arvo.substr(0, arvo.size()-1);
                                cout << arvo;
                               arvojaOn = false;

                           }
                           if (arvo[0] == '"' && arvo[1] != '"')
                           {
                               arvo = arvo.substr(1, arvo.size());
                               string mjono;
                               bool jatkuu = true;
        /*                       if (mjono[mjono.size()-1] == ',')               
                                    {
                                        mjono = mjono.substr(0, mjono.size()-1);                             
                                    }*/
                               if (arvo[arvo.size()-1] == '"')
                               {
                                   arvo = arvo.substr(0, arvo.size()-1);
                                   jatkuu = false;
                               }

                               
                               while (jatkuu)
                               {
                                   arvo.append(" ");
                                   tiedosto >> mjono;
                                   kokoKasky.append(" ");
                                   kokoKasky.append(mjono);
                                  if (mjono[mjono.size()-1] == ',')               
                                    {
                                        mjono = mjono.substr(0, mjono.size()-1);                             
                                    }
                                   
                                   if (mjono[mjono.size()-1] == '"')
                                   {
                                       mjono = mjono.substr(0, mjono.size()-1);
                                       jatkuu = false;
                                       cout << mjono << endl;
                                   }

                                   arvo.append(mjono);
                               }
                               cout << arvo << endl;

                           }
                           char *arvoc = const_cast<char *>(arvo.c_str());
                           int luku;
                           float flotu;
                           bool eiInt = false;
                           bool eiFloat = false;
                           cout << "Tähän päästään? " << kierros << endl;
                           for (int i = 0; i < arvo.size(); i++) {
                               if (!isdigit(arvo[i]))
                               {
                                   eiInt = true;
                               }
                               cout << arvo[i] << endl;

                            }
                           cout << "oliko int? " << eiInt << endl;
                           if (eiInt)
                           {
                               for (int i = 0; i < arvo.size(); i++) {
                               if (!isdigit(arvo[i]) || !ispunct(arvo[i]))
                               {
                                   eiFloat = true;
                               }

                            }
                           }

                           if ((kierros < sarakkeidenNimet.size()) && tauluOnOlemassa) {
                                if (!eiFloat && eiInt)
                                {
                                    cout << arvo;
                                    flotu = strtof(arvoc, NULL);
                                    if (taulunSarakkeet[kierros]->tutkiTyyppi(typeid(flotu).name()) != true)
                                    {

                                       virheHavaittu = true;
                                    }
                                    if (virheHavaittu == false)
                                    {
                                        Sarake<float> *a = new Sarake<float>(flotu,sarakkeidenNimet[kierros], taulunNimi);
                                    uudetSarakkeet.push_back(a);     
                                    }

                                } 

                                if (!eiInt)
                                {
                                    int intLuku;
                                    luku = strtol(arvoc, NULL, 10);
                                    intLuku = static_cast<int>(luku);

                                    bool ong = (taulunSarakkeet[kierros]->tutkiTyyppi(typeid(intLuku).name()))? true : false;
                                    cout << "ong " << ong << endl;
                                  //  if (taulunSarakkeet[kierros]->tutkiTyyppi(typeid(intLuku).name())!= true)
                                    if (taulunSarakkeet[kierros]->tutkiTyyppi(typeid(intLuku).name())!= true)
                                    {
                                        cout << "VIRHE INT\n";
                                       virheHavaittu = true;
                                    }
                                    cout << " tässköin ?" << endl;
                                    if (virheHavaittu == false)
                                    {

                                          Sarake<int> *a = new Sarake<int>(intLuku,sarakkeidenNimet[kierros], taulunNimi);

                                    uudetSarakkeet.push_back(a);
                                    }

                                } 
                                if (eiInt && eiFloat)
                                {                             
                                    if (taulunSarakkeet[kierros]->tutkiTyyppi(typeid(arvoc).name()) != true)
                                    {
                                        cout << arvoc << "\n";
                                        cout << "VIRHE CHAR " << typeid(arvoc).name() << " " << taulunSarakkeet[kierros]->kerroTyyppi() << "\n";
                                        virheHavaittu = true;
                                    }
                                    if (virheHavaittu == false)
                                    {
                                        Sarake<char *> *a = new Sarake<char *>(const_cast<char *>(arvoc),sarakkeidenNimet[kierros], taulunNimi);
                                    uudetSarakkeet.push_back(a);
                                    }
                                }
                           }
                           kierros++;
                       }

                       if (virheHavaittu == true)
                       {
                           throw Virhekomento(kokoKasky);
                       }
                       if (!virheHavaittu)
                       {
                           taulu.lisaaRivi(uudetSarakkeet);
                           db.muutaTaulua(taulu);
                       }
                       
                       kokoKasky = "";
                   }
               }
        }
        
            catch (Virhekomento &v)
            {               
                tiedostoUlos << v.what();
                tiedostoUlos << endl << endl;
                kokoKasky = "";
            }
           
        }
        
        if (kasky == DELETE)
        {
            
        }
            
        if (kasky == SELECT)
        {              
            tiedosto >> kasky;
            if (kasky == TAHTI)
            {
                tiedostoUlos << "lol";
            }
        }
        
        if (kasky == QUIT)
        {
            tiedosto.close();
            tiedostoUlos.close();
            lopetus = true;
        }
        
            
    }

    return 0;
}

