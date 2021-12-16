/*! \file Milieu .h
 *  implementation of class Milieu headers
 */

#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
class VisiteurDeplacement;

#include <iostream>
#include <vector>
#include <array>

using namespace std;

bool getProba(int seuil);

class Milieu : public UImg
{

private :
    static const T          white[];
    static const int     DEATH_PROB;
    static const int     CLONE_PROB;
    static const int     NAISSANCE_PROB;

   int                     width, height;
   std::vector<Bestiole>   listeBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( const Bestiole & b );
   int nbVoisins( const Bestiole & b ) const;
   void mort( void );
   void naissance(void);
   std::vector<Bestiole>& getListeBestioles ( void );
   std::array<Comportement *, 5> comportements;
   VisiteurDeplacement *visiteurDeplacement;
};


#endif
