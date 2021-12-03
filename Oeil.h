#ifndef _OEIL
#define _OEIL

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
	double getDistance ( void );
	double getAngle( void );
	bool detecte( void );

};

#endif