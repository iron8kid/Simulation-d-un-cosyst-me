#ifndef _OEIL
#define _OEIL

/*!
 *  \class Nageoire
 *  \brief Classe qui implémente le capteur qui permet à une Bestiole de voir son environnement.
 */

class Oeil
{

private :
   static const double     MAX_DISTANCE;
   static const double     MAX_ANGLE;
   static const double     MAX_DETECTION;
   static const double     MIN_DISTANCE;
   static const double     MIN_ANGLE;
   static const double     MIN_DETECTION;
   double            distance;
   double            angle;
   double 			 detection;


public :
   // INITIALISATION ET DESTRUCTION
   Oeil( );
   // GETTERS
	double getDistance ( void ) const;
	double getAngle( void ) const;
   // CONDITIONS ET OPERATEURS
	bool detecte( double distance_autre, double angle_res, double camouflage ) const;
   Oeil& operator=( const Oeil & other);

};

#endif