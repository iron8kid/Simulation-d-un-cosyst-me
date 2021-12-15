#ifndef _CAMOUFLAGE
#define _CAMOUFLAGE

class Camouflage
{

private :
   static const double     MAX_CAMOUFLAGE;
   static const double     MIN_CAMOUFLAGE;
   double            camouflage;


public :
	Camouflage( void );
	Camouflage( double temp );
	double getCamouflage( void ) const;

};

#endif