#ifndef _PREVOYANTE
#define _PREVOYANTE

#include "Comportement.h"
#include <iostream>


class Prevoyante : public Comportement {
private :
public :
    Prevoyante( void );
    void accept(Visitor *v) const override; 
};
#endif