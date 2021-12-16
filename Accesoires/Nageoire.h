#ifndef _NAGEOIRE
#define _NAGEOIRE

/*!
 *  \class Nageoire
 *  \brief Classe qui implémente l'accessoire qui augmente la vitesse normale d'une bestiole.
 */

class Nageoire
{

private :
   static const double     MAX_VITESSE_NAGEOIRE;
   double            vitesseNageoire;


public :
	Nageoire( void );
	Nageoire( double temp );
	double getVitesseNageoire( void ) const;

};

#endif