#include <iostream>
#include "Kamikaze.h"
#include "../Visiteur.h"



Kamikaze::Kamikaze( )
{
    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( static_cast<double>(0.);
    couleur[ 1 ] = static_cast<int>( static_cast<double>(230.);
    couleur[ 2 ] = static_cast<int>( static_cast<double>(0.);
}

void Kamikaze::accept(Visiteur *v) const 
{
    std::cout<<"Kamikaze Element accepted Visitor" << std::endl;
    v->visitKamikaze(this);
}
