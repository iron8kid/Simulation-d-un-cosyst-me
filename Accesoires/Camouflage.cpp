/*! \file Camouflage.h
 *  implementation de classe Camouflage
 */
#include "Camouflage.h"
#include <random>

const double      Camouflage::MAX_CAMOUFLAGE = 0.5;
const double      Camouflage::MIN_CAMOUFLAGE = 0.1;

Camouflage::Camouflage( void ) // Initialisation aléatoire.
{
	camouflage = MIN_CAMOUFLAGE + (double)(rand()) / ((double)(RAND_MAX/(MAX_CAMOUFLAGE - MIN_CAMOUFLAGE)));
}


Camouflage::Camouflage( double temp ) // Initialisation nulle
{
	camouflage = 0.;
}


double Camouflage::getCamouflage( void ) const
{
	return camouflage; // Ce chiffre sera comparé avec la détection d'une bestiole pour si elle détecte la bestiole camouflée ou pas.
}