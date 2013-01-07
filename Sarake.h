/* 
 * File:   Sarake.h
 * Author: Kuisma
 *
 * Created on December 5, 2012, 3:53 PM
 */


#ifndef SARAKE_H
#define	SARAKE_H

#include "Taulu.h"
#include "Otsake.h"
#include <sstream>
#include <typeinfo>

using namespace std;
string const INT = "INT";
string const FLOAT = "FLOAT";
string const CHAR = "CHAR";


template <typename T>
class Sarake: public Otsake
{
    T arvo;
    Taulu taulu;
  //  char * tyyppi;
    
    public:
        Sarake(T &arvo, string namen, Taulu &taulunnimi): Otsake(namen), taulu(taulunnimi), arvo(arvo)
        //, tyyppi(typeid(T).name())
        {
            
        }
        
        Sarake (Taulu &taulunnimi, string namen): Otsake(namen), taulu(taulunnimi)
        //, tyyppi(typeid(T).name())
        {
            
        }
        
        Sarake(string namen): Otsake(namen)
        {
            
        }
        const char * kerroTyyppi() const
        {
            return typeid(T).name();
        }
        
        bool tutkiTyyppi(const char * toinen) const
        {
            if (typeid(T).name() == toinen)
            {
                return true;
            }
            else
            {
                return false;
            }

        }
        
        T kerroArvo()
        {
            return arvo;
        }
        
        string tulosta() const
        {
            stringstream ss;
            ss << arvo;
            string paluu = ss.str();
            return paluu;        
        }
        
         bool compare(Sarake s)
    {
        if (s == *this)
        {
            return true;
        } else
        {
            return false;
        }
    }

    bool operator==(const Sarake<T> &b)
{
    if (*this.nimi == b.nimi)
    {
        return true;
    } else
    {
        return false;
    }
        
}
};



#endif	/* SARAKE_H */

