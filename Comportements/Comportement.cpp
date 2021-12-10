#include <iostream>
#include "Comportement.h"

T* Comportement::getCouleur() const
{
	return couleur;
}


Comportement::Comportement( )
{
    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( static_cast<double>(0.));
    couleur[ 1 ] = static_cast<int>( static_cast<double>(0.));
    couleur[ 2 ] = static_cast<int>( static_cast<double>(0.));
}

Comportement::~Comportement( void )
{
    delete[] couleur;
    cout << "dest Comportement" << endl;

}
