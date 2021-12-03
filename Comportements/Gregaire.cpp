#include "Gregaire.h"

double Gregaire::meanOrientation(const Milieu & monMilieu, const Bestiole & b)
{
    double orientation;
    int nb=0;

    for ( std::vector<shared_ptr<Bestiole>>::iterator it = monMilieu.getBestiolesList().begin() ; it != monMilieu.getBestiolesList().end() ; ++it ){
        if ((*it).getID() != b.getID()){
            if(b.jeTeVois(*it)){
                orientation+= (*it).getOrientation();
                nb += 1;
            }
        }
    }
    if(nb==0){
         return b->getOrientation();
    }else{
        return orientation/nb;
    }
}