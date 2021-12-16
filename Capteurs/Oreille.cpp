#include "Oreille.h"
#include <iostream>
#include <random>

const double	Oreille::MAX_DISTANCE = 100.;
const double	Oreille::MAX_DETECTION = 1.;
const double	Oreille::MIN_DISTANCE = 0.;
const double	Oreille::MIN_DETECTION = 0.;

Oreille::Oreille()
{
	distance = MIN_DISTANCE + ((double) rand()) / RAND_MAX * MAX_DISTANCE;
	detection = MIN_DETECTION + ((double) rand()) / RAND_MAX * MAX_DETECTION;
}

double Oreille::getDistance ( void ) const
{
	return distance;
}

bool Oreille::detecte( double distance_autre, double camouflage) const
{
	bool dist_cond = distance_autre < distance;
	bool detect_cond = detection > camouflage;
	return (dist_cond && detect_cond);
}

Oreille& Oreille::operator=( const Oreille& other )
{
   // Guard self assignment
    if (this == &other)
        return *this;
    distance = other.distance;
    detection = other.detection;
	return *this;
}