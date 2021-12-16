#include "Oreille.h"
#include <iostream>
#include <random>

const double	Oreille::MAX_DISTANCE = 1000.;
const double	Oreille::MAX_DETECTION = 1.;
const double	Oreille::MIN_DISTANCE = 10.;
const double	Oreille::MIN_DETECTION = 0.;

// INITIALISATION ET DESTRUCTION

Oreille::Oreille()
{	
	// Initialisation :  génération aléatoire des paramètres selon les maxima et minima définis
	distance = MIN_DISTANCE + ((double) rand()) / RAND_MAX * MAX_DISTANCE;		// distance d'écoute
	detection = MIN_DETECTION + ((double) rand()) / RAND_MAX * MAX_DETECTION;	// comparaison avec le camouflage
}

// GETTERS
double Oreille::getDistance ( void ) const
{
	return distance;
}

// CONDITIONS ET OPERATEURS
bool Oreille::detecte( double distance_autre, double camouflage) const
{
	bool dist_cond = distance_autre < distance; 	// Condition de distance plus petite
	bool detect_cond = detection > camouflage;	// Comparaison avec le camouflage
	return (dist_cond && detect_cond);
}

Oreille& Oreille::operator=( const Oreille& other ) // Opérateur d'égalite pour la consturction par copie de Bestiole
{
   // Guard self assignment
    if (this == &other)
        return *this;
    distance = other.distance;
    detection = other.detection;
	return *this;
}