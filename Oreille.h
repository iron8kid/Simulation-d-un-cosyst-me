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
	double getDistance ( void );
	bool detecte( void );

};

#endif