#include <iostream>
#include "Kamikaze.h"
#include "Visiteur.h"
#include <limits>
#include <cmath>


Kamikaze::Kamikaze( )
{
    couleur[ 0 ] = static_cast<int>( static_cast<double>(0.));
    couleur[ 1 ] = static_cast<int>( static_cast<double>(230.));
    couleur[ 2 ] = static_cast<int>( static_cast<double>(0.));
}
double Kamikaze::OrientationToClosetB(Milieu & monMilieu, Bestiole & b) const
{
    double dist=numeric_limits<double>::max();
    double tmp;
    Bestiole * cb=nullptr;
    for ( auto it = monMilieu.getListeBestioles().begin() ; it != monMilieu.getListeBestioles().end() ; ++it ){
        if (((*it).getID() != b.getID()) && (b.jeTeVois(*it)))
        {
            tmp = b.getDistance(*it);
            if (tmp<dist)
            {
                dist=tmp;
                cb=&(*it);
            }
        }
    }
    if(dist!=numeric_limits<double>::max())
    {
        return -atan2(cb->getY()-b.getY(),cb->getX()-b.getX());
    }
    else
    {
        return dist;
    }
}

Kamikaze::~Kamikaze( void )
{
    cout << "dest Kamikaze" << endl;

}

void Kamikaze::accept(Visiteur *v, Bestiole *b) const 
{
    std::cout<<"Kamikaze Element accepted Visitor" << std::endl;
    v->visitKamikaze(this, b);
}
