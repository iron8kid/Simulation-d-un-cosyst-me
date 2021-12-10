#include <iostream>
#include "Peureuse.h"
#include "../Visiteur.h"



Peureuse::Peureuse( int nbVoisins )
{
    nbVoisinsMax=nbVoisins;
    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( static_cast<double>(230.);
    couleur[ 1 ] = static_cast<int>( static_cast<double>(0.);
    couleur[ 2 ] = static_cast<int>( static_cast<double>(0.);
}
bool Peureuse::checkNeighbours(const Milieu & monMilieu,const Bestiole & b, const int maxnb)
{
    return monMilieu.nbVoisins(b)>= maxnb
}

void Peureuse::accept(Visiteur *v) const 
{
    std::cout<<"Peureuse Element accepted Visitor" << std::endl;
    v->visitPeureuse(this);
}
