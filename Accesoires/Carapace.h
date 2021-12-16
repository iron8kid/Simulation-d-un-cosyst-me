#ifndef _CARAPACE
#define _CARAPACE

/*!
 *  \class Carapace
 *  \brief Classe qui implémente l'accessoire qui détérmine la capacité d'une bestiole de
 *   supporter une collision. En revanche, il donne aussi un ralentissement.
 */

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