#include <iostream>
#include "Peureuse.h"
#include "../Visiteur.h"
#include "Milieu.h"
#include "Bestiole.h"


Peureuse::Peureuse( int nbVoisins )
{
    nbVoisinsMax=nbVoisins;
    couleur[ 0 ] = static_cast<int>( static_cast<double>(230.));
    couleur[ 1 ] = static_cast<int>( static_cast<double>(0.));
    couleur[ 2 ] = static_cast<int>( static_cast<double>(0.));
}
bool Peureuse::checkNeighbours(const Milieu & monMilieu,const Bestiole & b, const int maxnb)
{
    return monMilieu.nbVoisins(b)>= maxnb;
}


Peureuse::~Peureuse( void )
{
    cout << "dest Peureuse" << endl;

}

void Peureuse::accept(Visiteur *v, Bestiole *b) const 
{
    std::cout<<"Peureuse Element accepted Visitor" << std::endl;
    v->visitPeureuse(this, b);
}
