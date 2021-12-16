#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>
#include <random>
using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );
    int nbr;
    cout<< "=============================="<<endl;
    cout<< "Please enter the number (positive) of Gregaire"<<endl;
    cin >> nbr;
    while (nbr<0) {
        cout<< "the number of Gregaire must positive"<<endl;
        cin >> nbr;
    }
    for ( int i = 1; i <= nbr; ++i )
        ecosysteme.getMilieu().addMember( Bestiole(ecosysteme.getMilieu(),0) );
    cout<< "Please enter the number (positive) of Kamikaze"<<endl;
    cin >> nbr;
    while (nbr<0) {
        cout<< "the number of Kamikaze must positive"<<endl;
        cin >> nbr;
    }
    for ( int i = 1; i <= nbr; ++i )
        ecosysteme.getMilieu().addMember( Bestiole(ecosysteme.getMilieu(),1) );
    cout<< "Please enter the number (positive) of Peureuse"<<endl;
    cin >> nbr;
    while (nbr<0) {
        cout<< "the number of Peureuse must positive"<<endl;
        cin >> nbr;
    }
    for ( int i = 1; i <= nbr; ++i )
        ecosysteme.getMilieu().addMember( Bestiole(ecosysteme.getMilieu(),2) );
    cout<< "Please enter the number (positive) of Prevoyante"<<endl;
    cin >> nbr;
    while (nbr<0) {
        cout<< "the number of Prevoyante must positive"<<endl;
        cin >> nbr;
    }
    for ( int i = 1; i <= nbr; ++i )
        ecosysteme.getMilieu().addMember( Bestiole(ecosysteme.getMilieu(),3) );
    cout<< "Please enter the number (positive) of MultiComportement"<<endl;
    cin >> nbr;
    while (nbr<0) {
        cout<< "the number of MultiComportement must positive"<<endl;
        cin >> nbr;
    }
    for ( int i = 1; i <= nbr; ++i )
        ecosysteme.getMilieu().addMember( Bestiole(ecosysteme.getMilieu(),4) );
   std::cout << "fin du remplissage" << std::endl;
   ecosysteme.run();


   return 0;

}
