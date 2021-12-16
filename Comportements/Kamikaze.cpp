#include <iostream>
#include "Kamikaze.h"
#include "Visiteur.h"
#include <limits>
#include <cmath>

//! Le Constructeur par defaut
Kamikaze::Kamikaze( )
{
    couleur[ 0 ] = static_cast<int>( static_cast<double>(0.));
    couleur[ 1 ] = static_cast<int>( static_cast<double>(230.));
    couleur[ 2 ] = static_cast<int>( static_cast<double>(0.));
}

/*!
 * \param b: pointer vers la bestoilequi a le comportement kamikaze
 * \return (double): l'orientation vers la bestiole la plus proche
 */

double Kamikaze::orientationPlusProche(Bestiole & b) const
{
    double dist=numeric_limits<double>::max();
    double tmp;
    Bestiole * cb=nullptr;
    for ( auto it = b.getMilieu().getListeBestioles().begin() ; it != b.getMilieu().getListeBestioles().end() ; ++it ){
        if (((*it).getID() != b.getID()) && (b.jeTeVois(*it)))
        {
            tmp = b.distance(*it);
            if (tmp<dist)
            {
                dist=tmp;
                cb=&(*it);
            }
        }
    }
    if(dist!=numeric_limits<double>::max())
    {
        return b.angle(*cb);
    }
    else
    {
        return dist;
    }
}

//! Le Destructeur
Kamikaze::~Kamikaze( void )
{
    cout << "dest Kamikaze" << endl;

}

void Kamikaze::accept(Visiteur *v, Bestiole *b) const 
{
    // std::cout<<"Kamikaze Element accepted Visitor" << std::endl;
    v->visitKamikaze(this, b);
}
