#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <random>


bool testProba(int proba){
   // fonction pour retourner true avec une certaine probabilité
   // on génère un chiffre entre 0 et 99 et on retourne s'il est plus grand que
   // la probabilité moins 100
   // on retournerait vrai le pourcentage de fois indiquée comme paramètre
   return ( (rand() % 100) < proba);
}


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;
   comportements = {new Gregaire(), new Kamikaze(), new Peureuse(int 4), new Prevoyante()}
   std:cout << "comportemnts len" << comportments.size() << std:endl;
   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}

std::vector<Bestiole>& Milieu::getListeBestioles( void )
{
   return listeBestioles;
}

void Milieu::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {

      it->action( *this );
      it->draw( *this );

   } // for
   mortVieillissement( );
   if (testProba(20))
      naissance(); // naissance avec une probabilité de 20%

}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}


void Milieu::mortVieillissement( void )
{
   listeBestioles.erase(
   std::remove_if(listeBestioles.begin(), listeBestioles.end(),
        [](const Bestiole & b) {return b.estTropVieux();}),
   listeBestioles.end());
}

void Milieu::naissance( void ){
   addMember( Bestiole(*this) );
}
