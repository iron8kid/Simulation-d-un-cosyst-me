/*! \file Bestiole.h
 *  implementation of class Bestiole headers
 */

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
/*!
 *  \class Bestiole
 */
class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     SPEED_FACTOR;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;
   static const int        AGE_MAX;
   static const double     DEATH_PROB;
   static const double     CLONE_PROB;




   static int              next;

private :
   bool              collisionState;
   int               identite;
   int               x, y;
   bool              mustDie;
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
   Bestiole( Milieu & milieu);                      // Constructeur par defaut
   Bestiole( Milieu & milieu, int c );              //Constructeur avec choix du comportement
   Bestiole(const Bestiole & b);                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );
   void initCoords( int xLim, int yLim );
   void collision();                            //!< Modifie collisionState et l'oriention si la bestiole est en collision
   // CONDITIONS
   bool jeTeVois( const Bestiole & b ) const;  //!< verifie si deux bestioles se voient
   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
   bool estTropVieux( void ) const;             //!< Vérifie si l'age de la bestiole a depassé l'age max
   // SETTERS
   void setcollisionState(bool newState);     //!< setter de collisionState
   void setOrientation(double newOrientation);//!< setter de Orientation
   void setEscape(bool new_state);            //!< setter de escape
   void accelerer(bool boost);                //!< boost la vitesse de la bestiole
   // GETTERS
   bool getcollisionState() const;
   double getAFF_SIZE() const;
   bool getEscape() const;
   double getVitesse() const;
   int getY() const;
   bool getMustDie() const;
   void setMustDie(bool new_state);
   int getX() const;
   double getCumulX() const;
   double getCumulY() const;
   int getID( ) const;
   double getProtection() const;
   double getOrientation( ) const ;
   Milieu& getMilieu( ) const;
   double getCamouflage( ) const ;
   // OPERATORS, COMPARISONS
   double distance( const Bestiole & b ) const;
   double angle( const Bestiole & b ) const;
   Bestiole& operator=( const Bestiole & other);


};


#endif
