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
   Oeil( );
	double getDistance ( void ) const;
	double getAngle( void ) const;
	bool detecte( double distance_autre, double angle_res ) const;

};

#endif