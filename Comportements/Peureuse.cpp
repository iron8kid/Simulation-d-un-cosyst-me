#include <iostream>
#include "Peureuse.h"
#include "Visitor.h"



Peureuse::Peureuse( )
{
    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( static_cast<double>(230.);
    couleur[ 1 ] = static_cast<int>( static_cast<double>(0.);
    couleur[ 2 ] = static_cast<int>( static_cast<double>(0.);
}

void Peureuse::accept(Visitor *v) const 
{
    std::cout<<"Peureuse Element accepted Visitor" << std::endl;
    v->visitPeureuse(this);
}
