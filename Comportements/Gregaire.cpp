#include "Gregaire.h"

double Gregaire::meanOrientation(Milieu & monMilieu, Bestiole & current)
{
    double orientation;
    int nb=0;

    for ( std::vector<shared_ptr<Bestiole>>::iterator it = monMilieu.getBestiolesList().begin() ; it != monMilieu.getBestiolesList().end() ; ++it ){
        if ((**it).getID() != current->getID()){
            if(current->jeTeVois(**it)){
                orientation+= (**it).getOrientation();
                nb += 1;
            }
        }
    }
    if(nb==0){
         return current->getOrientation();
    }else{
        return orientation/nb;
    }
}