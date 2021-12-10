#include <iostream>
#include "Kamikaze.h"
#include "../Visiteur.h"
#include <limits>


Kamikaze::Kamikaze( )
{
    couleur[ 0 ] = static_cast<int>( static_cast<double>(0.));
    couleur[ 1 ] = static_cast<int>( static_cast<double>(230.));
    couleur[ 2 ] = static_cast<int>( static_cast<double>(0.));
}
Bestiole * Kamikaze::getClosetB(Milieu & monMilieu, Bestiole & b)
{
    if(monMilieu.getListeBestioles().size()==1)
    {
        return nullptr;
    }
    double dist=numeric_limits<double>::max();
    double tmp;
    Bestiole * cb;
    for ( auto it = monMilieu.getListeBestioles().begin() ; it != monMilieu.getListeBestioles().end() ; ++it ){
        if ((*it).getID() != b.getID()){
            tmp = b.getDistance(*it);
            if (tmp<dist)
            {
                dist=tmp;
                cb=&(*it);
            }
        }
    }
    return cb;
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
