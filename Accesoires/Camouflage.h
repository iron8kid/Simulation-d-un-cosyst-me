#ifndef _CAMOUFLAGE
#define _CAMOUFLAGE

/*!
 *  \class Camouflage
 *  \brief Classe qui détérmine la capacité d'une bestiole de ne pas être détectée par les autres.
 */
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