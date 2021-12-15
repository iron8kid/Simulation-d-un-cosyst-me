#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>
#include <random>
using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );
   for ( int i = 1; i <= 10; ++i )
      ecosysteme.getMilieu().addMember( Bestiole(ecosysteme.getMilieu()) );
   std::cout << "fin du remplissage" << std::endl;
   ecosysteme.run();


   return 0;

}
