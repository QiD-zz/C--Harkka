/* 
 * File:   Tyyppi.h
 * Author: Kuisma
 *
 * Created on December 12, 2012, 11:00 AM
 */

#ifndef TYYPPI_H
#define	TYYPPI_H
#include <exception>
using namespace std;

class Virhekomento: public exception
{
    string viesti;
public:
    Virhekomento(string msg) throw(): viesti(msg){}
    ~Virhekomento() throw() {}
    
    const char * what() const throw()
    {
      /* Palautetaan poikkeusta kuvaava viesti. */

        string paluu("Illegal command: ");
        paluu.append(viesti);
        cout << paluu << endl;
        return paluu.c_str();
    }
};

#endif	/* TYYPPI_H */

