#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

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


   T               * couleur;
   bool             escaping=false;

private :
   void increment_age ( );
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( Milieu & milieu );                               // Constructeur par defaut
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
   void accelerate(bool boost);
   // GETTERS
   bool getEscape() const;
   double getVitesse() const;
   int getID( ) const;
   double getOrientation( ) const ;
   double getDistance( const Bestiole & b ) const;
   Milieu& getMilieu( ) const;
 

   Bestiole& operator=( const Bestiole & other);


};


#endif
