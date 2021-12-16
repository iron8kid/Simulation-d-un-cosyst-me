#include <iostream>
#include "Peureuse.h"
#include "Visiteur.h"
// #include "Milieu.h"
// #include "Bestiole.h"

//! Le Constructeur par defaut
Peureuse::Peureuse(int nbVoisins)
{
    nbVoisinsMax=nbVoisins;
    couleur[ 0 ] = static_cast<int>( static_cast<double>(230.));
    couleur[ 1 ] = static_cast<int>( static_cast<double>(0.));
    couleur[ 2 ] = static_cast<int>( static_cast<double>(0.));
}
/*!
 * \param b: pointer vers la bestoile qui a le comportement Peureuse
 * \return (bool): retourne si le nombre de voisines depasse nbVoisinsMax
 */
bool Peureuse::checkNeighbours(const Bestiole & b) const//, const int maxnb)
{
    return b.getMilieu().nbVoisins(b) >= nbVoisinsMax;
}

//! Le Distructeur
Peureuse::~Peureuse( void )
{
    cout << "dest Peureuse" << endl;

}

void Peureuse::accept(Visiteur *v, Bestiole *b) const 
{
    // std::cout<<"Peureuse Element accepted Visitor" << std::endl;
    v->visitPeureuse(this, b);
}
