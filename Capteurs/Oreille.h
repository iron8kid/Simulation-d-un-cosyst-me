#ifndef _OREILLE
#define _OREILLE

/*!
 *  \class Nageoire
 *  \brief Classe qui implémente le capteur qui permet à une Bestiole d'entendre son environnement.
 */

class Oreille
{

private :
   static const double     MAX_DISTANCE;
   static const double     MAX_DETECTION;
   static const double     MIN_DISTANCE;
   static const double     MIN_DETECTION;
   double            distance;
   double            angle;
   double 			 detection;


public :
   // INITIALISATION ET DESTRUCTION
   Oreille();
   // GETTERS
	double getDistance ( void ) const;
   // CONDITIONS ET OPERATEURS   
	bool detecte( double distance_autre, double camouflage  ) const;
   Oreille& operator=( const Oreille & other);

};

#endif