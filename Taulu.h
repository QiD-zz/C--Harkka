/* 
 * File:   Taulu.h
 * Author: Kuisma
 *
 * Created on December 5, 2012, 2:12 PM
 */
#include <vector>
#include "otsake.h"
#include "Sarake.h"
#include <list>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <typeinfo>

#ifndef TAULU_H
#define	TAULU_H
using namespace std;

static const int SARAKKEENLEVEYS = 8;

class Taulu
{
    vector <Otsake *> sarakkeet;
    list < vector <Otsake *> >  rivit;
    string nimi;
    int koko;
    int sarakkeita;
    
    public:
    Taulu()
    {
        koko = 0;
    }
    Taulu(string name): nimi(name)
    {
        koko = 0;
    }
    
     Taulu(string name, vector<Otsake *> sarkat, int leveys): nimi(name), koko(0), sarakkeita(leveys)
    {

        sarakkeet = sarkat;
    }
     
     Taulu(const Taulu &toinen): nimi(toinen.nimi), koko(toinen.koko), sarakkeita(toinen.sarakkeita), sarakkeet(toinen.sarakkeet), rivit(toinen.rivit)
     {
         
     }
     
  /*  Taulu(string name, Otsake *sarkat, int leveys): nimi(name), sarakkeet(sarkat)
    {
        cout << "KONSTRUKTORUI222222\n";
        koko = 0;
        sarakkeita = leveys;
        
      //  Otsake o = *sarakkeet;
       //  o.tulosta();
       /* for (int i = 0; i < sarakkeita; i++) {
            cout << i << endl;
                Otsake o = *(sarakkeet+i);
                o.tulosta();
            }
    }*/
    
    void lisaaRivi(vector <Otsake *> rivi)
    {
        cout << "TÄÄLLÄKÖ KUSEE??\n";
        rivit.push_back(rivi);
        koko++;
        cout << "mitk KUSEE??\n";
     /*   if (koko > 0)
        {
            Otsake **temp = rivit;
            delete [] rivit;
            rivit[koko+1][sarakkeita];
            for (int i = 0; i < koko; i++) {
            rivit[i] = temp[i];

            }

            rivit[koko] = rivi;
            koko++;
        } else {
            rivit[1][sarakkeita];
            rivit[0] = rivi;
            koko++;
        }*/
        
        
    }
    
    void poistaRivi(int rivi)
    {

    }
    
    Otsake * haeSarake(string nimi)
    {
        for (vector< Otsake * >::iterator it = sarakkeet.begin(); it != sarakkeet.end(); it++) {
            Otsake *sar = *it;
            if (nimi == sar->nimi)
            {
                return sar;
            }
        }
    }
    
     vector<Otsake *> kerroSarakkeet()
     {
         return sarakkeet;
     }
    
    string kerroNimi()
    {
        return nimi;
    }
    
    string tulostaSisalto()
    {
        stringstream ss;
        for (list< vector<Otsake *> >::iterator it = rivit.begin(); it != rivit.end(); it++) {
            vector<Otsake *> rivi = *it;
            for (int i = 0; i < sarakkeita; i++) {
                string sarka = rivi.at(i)->tulosta();
                int pit = sarka.length();
                int kerrat = 1;
                while (pit > SARAKKEENLEVEYS)
                {
                    kerrat++;
                    pit -= SARAKKEENLEVEYS;
                }
                ss << setw(kerrat * SARAKKEENLEVEYS) << sarka;               
            }
            ss << endl;
        }

        return ss.str();
    }
    
    int kerrosarakkeidenlkm()
    {
        return sarakkeita;
    }
    int kerroRivienLkm()
    {
        return koko;
    }
    
    bool compare(Taulu t)
    {
        if (t == *this)
        {
            return true;
        } else
        {
            return false;
        }
    }
    
    friend bool operator==(const Taulu &a, const Taulu &b);
};

bool operator==(const Taulu &a, const Taulu &b)
{
    if (a.nimi == b.nimi)
    {
        return true;
    } else
    {
        return false;
    }
        
}

#endif	/* TAULU_H */

