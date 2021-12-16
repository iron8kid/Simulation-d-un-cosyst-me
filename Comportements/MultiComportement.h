/*! \file MultiComportement.h
 *  implementation of class MultiComportement headers
 */
#ifndef _Multicomportement
#define _Multicomportement

#include "Comportement.h"

#include <iostream>
/*!
 *  \class MultiComportement
 *  \brief  une bestiole dite `a personnalit´es multiples adopte
successivement d’autres comportements choisis al´eatoirement au cours du temps. N´eanmoins, elle
reste une bestiole `a personnalit´es multiples.
 */
class MultiComportement: public Comportement {
private :
    static int comp_timer;//!< timeur pour changer le comportement
public :
    MultiComportement( void );//!< Le Constructeur par defaut
    ~MultiComportement(void);//!< Le Destructeur
    static int getTimer();//!< getter de comp_timer
    static void setTimer(int t);//!< setter de comp_timer
    int getComportement() const;//!< retourne l'indice du nouveau comportement
    void accept(Visiteur *v, Bestiole *b) const override;
};
#endif