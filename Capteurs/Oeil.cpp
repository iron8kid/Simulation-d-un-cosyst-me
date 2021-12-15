#include "Oeil.h"
#include <iostream>
#include <random>

const double	Oeil::MAX_DISTANCE = 100.;
const double	Oeil::MAX_ANGLE = M_PI/2.;
const double	Oeil::MAX_DETECTION = 1.;
const double	Oeil::MIN_DISTANCE = 0.;
const double	Oeil::MIN_ANGLE = 0.;
const double	Oeil::MIN_DETECTION = 0.;

Oeil::Oeil()
{
	distance = MIN_DISTANCE + ((double) rand()) / RAND_MAX * MAX_DISTANCE;
	angle = MIN_ANGLE + ((double) rand()) / RAND_MAX * MAX_ANGLE;
	detection = MIN_DETECTION + ((double) rand()) / RAND_MAX * MAX_DETECTION;
}

double Oeil::getDistance ( void ) const
{
	return distance;
}
double Oeil::getAngle( void ) const
{
	return angle;
}
bool Oeil::detecte( void )
{
	return true;
}