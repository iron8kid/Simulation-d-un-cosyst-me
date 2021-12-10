#include "Gregaire.h"
#include "../Visiteur.h"
#include "Milieu.h"
#include "Bestiole.h"

Gregaire::Gregaire( )
{
    couleur = new T[ 3 ];
    couleur[ 0 ] = static_cast<int>( static_cast<double>(0.));
    couleur[ 1 ] = static_cast<int>( static_cast<double>(0.));
    couleur[ 2 ] = static_cast<int>( static_cast<double>(230.));
}
double Gregaire::meanOrientation(Milieu & monMilieu, const Bestiole & b)
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
        return orientation/nb;
    }
}
void Gregaire::accept(Visiteur *v, Bestiole *b) const 
{
    std::cout<<"Gregaire Element accepted Visitor" << std::endl;
    v->visitGregaire(this, b);
}