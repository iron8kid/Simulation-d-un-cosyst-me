#ifndef _GREGAIRE
#define _GREGAIRE

#include "Comportement.h"

#include <iostream>

class Gregaire : public Comportement {
private :
public :
	Gregaire( void );
    ~Gregaire(void) ;
    double meanOrientation(Milieu & monMilieu,Bestiole & b) const;
    void accept(Visiteur *v, Bestiole *b) const override;
};
#endif