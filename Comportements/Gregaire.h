#ifndef _GREGAIRE
#define _GREGAIRE

#include "Comportement.h"
#include <iostream>


class Gregaire : public Comportement {
private :
public :
	Gregaire( void );
    double meanOrientation(const Milieu & monMilieu,const Bestiole & b);
    void accept(Visiteur *v) const override; 
};
#endif