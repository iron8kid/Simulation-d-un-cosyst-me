#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"
#include "Capteurs/Oeil.h"
#include "Capteurs/Oreille.h"
#include "Accesoires/Camouflage.h"
#include "Accesoires/Carapace.h"
#include "Accesoires/Nageoire.h"

#include <iostream>

using namespace std;


class Milieu;
class Comportement;

class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     SPEED_FACTOR;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;
   static const int        AGE_MAX;


   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   int               age_actuel;
   int               age_limit;

   Milieu          * monMilieu;
   Comportement    * comportement;

   Camouflage        camouflage;
   Carapace          carapace;
   Nageoire          nageoire;

   Oeil              oeil;
   Oreille           oreille;

   T               * couleur;
   bool             escaping=false;

private :
   void increment_age ( );
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( Milieu & milieu);                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );
   void initCoords( int xLim, int yLim );

   // CONDITIONS
   bool jeTeVois( const Bestiole & b ) const;
   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
   bool estTropVieux( void ) const;
   // SETTERS
   void setOrientation(double newOrientation);
   void setEscape(bool new_state);
   void accelerer(bool boost);
   // GETTERS
   double getAFF_SIZE() const;
   bool getEscape() const;
   double getVitesse() const;
   int getY() const;
   int getX() const;
   double getCumulX() const;
   double getCumulY() const;
   int getID( ) const;
   double getOrientation( ) const ;
   Milieu& getMilieu( ) const;
   // OPERATORS, COMPARISONS
   double distance( const Bestiole & b ) const;
   double angle( const Bestiole & b ) const;
   Bestiole& operator=( const Bestiole & other);


};


#endif
