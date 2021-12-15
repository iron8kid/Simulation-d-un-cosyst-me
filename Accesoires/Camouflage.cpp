#include "Camouflage.h"
#include <random>

const double      Camouflage::MAX_CAMOUFLAGE = 1.;
const double      Camouflage::MIN_CAMOUFLAGE = 0.;
Camouflage::Camouflage( void )
{
	camouflage = MIN_CAMOUFLAGE + (double)(rand()) / ((double)(RAND_MAX/(MAX_CAMOUFLAGE - MIN_CAMOUFLAGE)));
}


Camouflage::Camouflage( double temp )
{
	camouflage = 0.;
}


double Camouflage::getCamouflage( void ) const
{
	return camouflage;
}