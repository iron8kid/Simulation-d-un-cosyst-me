#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
/*#include "Comportements/Comportement.h"
#include "Comportements/Gregaire.h"
#include "Comportements/Kamikaze.h"
#include "Comportements/Peureuse.h"
#include "Comportements/Prevoyante.h"*/
// #include "VisiteurDeplacement.h"
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
   void mortVieillissement( void );
   void naissance(void);
   std::vector<Bestiole>& getListeBestioles ( void );
   std::array<Comportement *, 5> comportements;
   VisiteurDeplacement *visiteurDeplacement;
};


#endif
