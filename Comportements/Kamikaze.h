#ifndef _KAMIKAZE
#define _KAMIKAZE

#include "Comportement.h"
#include "Milieu.h"
#include <iostream>


class Kamikaze : public Comportement {
private :
public :
    Kamikaze( void );
    double orientationPlusProche(Bestiole & b) const;
    ~Kamikaze( void );
    void accept(Visiteur *v, Bestiole *b) const override; 
};
#endif