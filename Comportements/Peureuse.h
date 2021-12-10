#ifndef _PEUREUSE
#define _PEUREUSE

#include "Comportement.h"
#include <iostream>


class Peureuse : public Comportement {
private :
    int nbVoisinsMax;
public :
	Peureuse(int nbVoisins);
    bool checkNeighbours(const Milieu & monMilieu,const Bestiole & b, const int maxnb);
    void accept(Visiteur *v) const override; 
};
#endif