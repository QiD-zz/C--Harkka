/* 
 * File:   Otsake.h
 * Author: Kuisma
 *
 * Created on December 12, 2012, 12:29 PM
 */

#ifndef OTSAKE_H
#define	OTSAKE_H
#include <typeinfo>
using namespace std;

class Otsake
{
   
public:
    std::string nimi;
    Otsake()
    {
        
    }
    
    ~Otsake()
    {
        
    }
    
    Otsake(std::string name): nimi(name)
    {   

    }
    virtual const char * kerroTyyppi() const
        {

        }
    
    virtual string tulosta() const
    {
        
    }
    virtual bool tutkiTyyppi(const char * toinen) const
        {

        }
};

#endif	/* OTSAKE_H */

