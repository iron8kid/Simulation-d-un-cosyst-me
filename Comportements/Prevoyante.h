#ifndef _PREVOYANTE
#define _PREVOYANTE

#include "Comportement.h"
#include "Milieu.h"
#include <iostream>
struct Point{
    int x, y;
    double angle;
};

class Prevoyante : public Comportement {
private :
public :
    Prevoyante( void );
    ~Prevoyante( void );
    Point PosAtK(int k,Bestiole *b) const;
    double escapeDirection(Bestiole & b) const;
    void accept(Visiteur *v, Bestiole *b) const override; 
};
#endif