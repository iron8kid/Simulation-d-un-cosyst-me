#ifndef _COMPORTEMENT
#define _COMPORTEMENT

#include <iostream>
#include "UImg.h"
#include "Bestiole.h"

class Visiteur;

class Comportement
{
protected :
    T               * couleur;
public:
    virtual void accept(Visiteur *v, Bestiole *b) const=0;
    ~Comportement(void);
    T* getCouleur() const; 
};

#endif
