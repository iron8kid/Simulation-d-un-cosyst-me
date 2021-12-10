#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include "Comportements/Comportement.h"
#include "Comportements/Gregaire.h"
#include "Comportements/Kamikaze.h"
#include "Comportements/Peureuse.h"
#include "Comportements/Prevoyante.h"



#include <iostream>
#include <vector>
#include <array>

using namespace std;

bool getProba(int seuil);

class Milieu : public UImg
{

private :
   static const T          white[];
   std::array<Comportement *, 4> comportements;
   int                     width, height;
   std::vector<Bestiole>   listeBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( const Bestiole & b ) { listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); }
   int nbVoisins( const Bestiole & b );
   void mortVieillissement( void );
   void naissance(void);
   std::vector<Bestiole>& getListeBestioles ( void );
};


#endif
