#ifndef _GREGAIRE
#define _GREGAIRE

#include "Comportement.h"
#include <iostream>


class Gregaire : public Comportement {
private :
public :
	Gregaire( void )g ;
    double meanOrientation(Milieu & monMilieu);
    void accept(Visitor *v) const override; 
};
#endif