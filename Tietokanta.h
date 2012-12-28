/* 
 * File:   Tietokanta.h
 * Author: Kuisma
 *
 * Created on December 5, 2012, 5:23 PM
 */

#ifndef TIETOKANTA_H
#define	TIETOKANTA_H
#include <iostream>
#include <list>
#include "Taulu.h"

using namespace std;

class Tietokanta
{
    list<Taulu> taulut;   
    list<string> nimet;
public:
    Tietokanta(): taulut(), nimet()
    {
        
    }
    
    void lisaaTaulu(Taulu t)
    {
        bool onkoJo = false;
        for (list<Taulu>::iterator it = taulut.begin() ; it != taulut.end(); it++) {
            Taulu i = it.operator *();
            if (i.kerroNimi() == t.kerroNimi())
            {
                onkoJo = true;
            }
        }
        if (onkoJo)
        {
            taulut.remove(t);
            nimet.remove(t.kerroNimi());
            taulut.push_back(t);
            nimet.push_back(t.kerroNimi());
        }
        else
        {
            taulut.push_back(t);
            nimet.push_back(t.kerroNimi());
        }
        
    }
    
    void poistaTaulu(string nimi)
    {
        for (list<Taulu>::iterator it = taulut.begin() ; it != taulut.end(); it++) {
            Taulu i = it.operator *();
            if (i.kerroNimi() == nimi)
            {
              //  Taulu poistettava = taulut[i];
                taulut.remove(i);
            }
        }
    }
    
    int montakoTaulua()
    {
        return taulut.size();
    }
    
    void muutaTaulua(Taulu t)
    {
        taulut.remove(t);
        taulut.push_back(t);

    }
    
    bool onkoTaulua(string nimi)
    {
        for (list<string>::iterator it = nimet.begin() ; it != nimet.end(); it++) {
            if (nimi == *it)
            { 
                return true;
            }
        }
        return false;
    }
    
    Taulu haeTaulu(string nimi)
    {
        if (onkoTaulua(nimi))
        {
            for (list<Taulu>::iterator it = taulut.begin() ; it != taulut.end(); it++) {
                Taulu i = it.operator *();
                if (i.kerroNimi() == nimi)
                {
                    return i;
                }
            }
        }
        
    }
    string tulostaTaulunNimi(int i)
    {
        if (i < nimet.size())
        {
            list<string>::iterator it = nimet.begin();
            for (int j = 0; j < i; j++, it++) {        }
            string paluu = *it;
            return paluu;
        }
        
    }
};

#endif	/* TIETOKANTA_H */

