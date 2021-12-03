#include <iostream>
#include "Gregaire.h"
#include "Visitor.h"



Gregaire::Gregaire( )
{
    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( static_cast<double>(0.);
    couleur[ 1 ] = static_cast<int>( static_cast<double>(0.);
    couleur[ 2 ] = static_cast<int>( static_cast<double>(230.);
}

void Gregaire::accept(Visitor *v) const 
{
    std::cout<<"Gregaire Element accepted Visitor" << std::endl;
    v->visitGregaire(this);
}
