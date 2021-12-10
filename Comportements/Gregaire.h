#ifndef _GREGAIRE
#define _GREGAIRE

#include "Comportement.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <iostream>


class Gregaire : public Comportement {
private :
public :
	Gregaire( void );
    double meanOrientation(Milieu & monMilieu,const Bestiole & b);
    void accept(Visiteur *v, Bestiole *b) const override; 
};
#endif