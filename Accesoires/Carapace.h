#ifndef _CARAPACE
#define _CARAPACE

class Carapace
{

private :
   static const double     MAX_PROTECTION;
   static const double     MAX_RALENTISSEMENT;
   double            ralentissement;
   double            protection;


public :
	double getRalentissement( void );
	double getProtection( void );

};

#endif