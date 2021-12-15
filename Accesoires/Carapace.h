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
   Carapace( void );
   Carapace( double temp );
	double getRalentissement( void ) const;
	double getProtection( void ) const;

};

#endif