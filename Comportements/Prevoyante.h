#ifndef _PREVOYANTE
#define _PREVOYANTE

#include "Comportement.h"
#include "Milieu.h"
#include <iostream>


class Prevoyante : public Comportement {
private :
public :
    Prevoyante( void );
    ~Prevoyante( void );
    void accept(Visiteur *v, Bestiole *b) const override; 
};
#endif