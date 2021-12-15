#include "Nageoire.h"
#include <random>

const double      Nageoire::MAX_VITESSE_NAGEOIRE = 1.2;
Nageoire::Nageoire( void )
{
	vitesseNageoire = (double)(rand()) / (1+(double)(RAND_MAX/(MAX_VITESSE_NAGEOIRE-1)));

}

Nageoire::Nageoire( double temp )
{
	vitesseNageoire = 1.;

}


double Nageoire::getVitesseNageoire( void ) const
{
	return vitesseNageoire;
}
