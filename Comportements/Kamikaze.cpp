#include <iostream>
#include "Kamikaze.h"
#include "../Visiteur.h"
#include <limits>


Kamikaze::Kamikaze( )
{
    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( static_cast<double>(0.));
    couleur[ 1 ] = static_cast<int>( static_cast<double>(230.));
    couleur[ 2 ] = static_cast<int>( static_cast<double>(0.));
}
Bestiole * Kamikaze::getClosetB(const Milieu & monMilieu, const Bestiole & b)
{
    if(monMilieu.getBestiolesList().size()==1)
    {
        return nullptr;
    }
    double dist=numeric_limits<double>::max();
    double tmp;
    Bestiole * cb;
    for ( std::vector<shared_ptr<Bestiole>>::iterator it = monMilieu.getBestiolesList().begin() ; it != monMilieu.getBestiolesList().end() ; ++it ){
        if ((*it).getID() != b.getID()){
            tmp = b.getDistance(*it);
            if (tmp<dist)
            {
                dist=tmp;
                cb=it
            }
        }
    }
    return cb;
}

Kamikaze::~Kamikaze( void )
{
    delete[] couleur;
    cout << "dest Kamikaze" << endl;

}

void Kamikaze::accept(Visiteur *v, Bestiole *b) const 
{
    std::cout<<"Kamikaze Element accepted Visitor" << std::endl;
    v->visitKamikaze(this, b);
}
