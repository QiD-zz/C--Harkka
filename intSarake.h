/* 
 * File:   intSarake.h
 * Author: Kuisma
 *
 * Created on December 12, 2012, 11:08 AM
 */

#ifndef INTSARAKE_H
#define	INTSARAKE_H
using namespace std;

class IntSarake: public Sarake
{
    public:
        IntSarake(string namen, Taulu taulunnimi): Sarake(namen, taulunnimi)
        {
            
        }
};

#endif	/* INTSARAKE_H */

