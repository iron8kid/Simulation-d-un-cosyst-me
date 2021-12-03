#include <iostream>
#include "Prevoyante.h"
#include "Visitor.h"



Prevoyante::Prevoyante( )
{
    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( static_cast<double>(0.);
    couleur[ 1 ] = static_cast<int>( static_cast<double>(110.);
    couleur[ 2 ] = static_cast<int>( static_cast<double>(110.);
}

void Prevoyante::accept(Visitor *v) const 
{
    std::cout<<"Prevoyante Element accepted Visitor" << std::endl;
    v->visitPrevoyante(this);
}
