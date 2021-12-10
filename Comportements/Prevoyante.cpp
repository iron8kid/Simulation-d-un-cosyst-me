#include <iostream>
#include "Prevoyante.h"
#include "../Visiteur.h"



Prevoyante::Prevoyante( )
{
    couleur[ 0 ] = static_cast<int>( static_cast<double>(0.));
    couleur[ 1 ] = static_cast<int>( static_cast<double>(110.));
    couleur[ 2 ] = static_cast<int>( static_cast<double>(110.));
}

Prevoyante::~Prevoyante( void )
{
    cout << "dest Prevoyante" << endl;

}

void Prevoyante::accept(Visiteur *v, Bestiole *b) const 
{
    std::cout<<"Prevoyante Element accepted Visitor" << std::endl;
    v->visitPrevoyante(this, b);
}
