#include "Gregaire.h"
#include "Visiteur.h"
//#include "../Milieu.h"
//#include "../Bestiole.h"
//#include "Comportement.h"

//! Le Constructeur par defaut
Gregaire::Gregaire( )
{
    couleur[ 0 ] = static_cast<int>( static_cast<double>(0.));
    couleur[ 1 ] = static_cast<int>( static_cast<double>(0.));
    couleur[ 2 ] = static_cast<int>( static_cast<double>(230.));
}

//! Le Destructeur
Gregaire::~Gregaire( void )
{
    cout << "dest Gregaire" << endl;

}

/*!
 * \param b: pointer vers la bestoile qui a le comportement Gregaire
 * \return (double): retourne la direction moyenne des bestioles environnantes.
 */
double Gregaire::meanOrientation(Milieu & monMilieu,Bestiole & b) const
{
    double orientation;
    int nb=0;

    for ( auto it = monMilieu.getListeBestioles().begin() ; it != monMilieu.getListeBestioles().end() ; ++it ){
        if ((*it).getID() != b.getID()){
            if(b.jeTeVois(*it)){
                orientation+= (*it).getOrientation();
                nb += 1;
            }
        }
    }
    if(nb==0){
         return b.getOrientation();
    }else{
        // cout << orientation/nb << endl;
        return orientation/nb;
    }
}
void Gregaire::accept(Visiteur *v, Bestiole *b) const 
{
    // std::cout<<"Gregaire Element accepted Visitor" << std::endl;
    v->visitGregaire(this, b);
}