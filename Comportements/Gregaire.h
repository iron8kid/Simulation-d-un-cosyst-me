#ifndef _GREGAIRE
#define _GREGAIRE

#include "Comportement.h"
#include <iostream>


class Gregaire : public Comportement {
private :
public :
	Gregaire( void );
    void accept(Visitor *v) const override; 
};
#endif