#ifndef _OREILLE
#define _OREILLE

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
   Oreille();
	double getDistance ( void ) const;
	bool detecte( double distance_autre, double camouflage  ) const;
   Oreille& operator=( const Oreille & other);

};

#endif