#ifndef _PEUREUSE
#define _PEUREUSE

#include "Comportement.h"
#include "Milieu.h"
// #include "Bestiole.h"
#include <iostream>


class Peureuse : public Comportement {
private :
    int nbVoisinsMax;
public :
	Peureuse(int nbVoisins);
    ~Peureuse( void );
    bool checkNeighbours(const Bestiole & b) const;//, const int maxnb);
    void accept(Visiteur *v, Bestiole *b) const override; 
};
#endif