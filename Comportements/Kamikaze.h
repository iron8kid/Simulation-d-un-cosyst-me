#ifndef _KAMIKAZE
#define _KAMIKAZE

#include "Comportement.h"
#include <iostream>


class Kamikaze : public Comportement {
private :
public :
    Kamikaze( void );
    Bestiole * getClosetB(Milieu & monMilieu, Bestiole & b);
    ~Kamikaze( void );
    void accept(Visiteur *v, Bestiole *b) const override; 
};
#endif