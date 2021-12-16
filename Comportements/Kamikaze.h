/*! \file Kamikaze.h
 *  implementation of class Kamikaze headers
 */
#ifndef _KAMIKAZE
#define _KAMIKAZE

#include "Comportement.h"
#include "Milieu.h"
#include <iostream>

/*!
 *  \class Kamikaze
 *  \brief  une bestiole dite kamikaze est attirée par la bestiole la plus proche et
tente de l’attaquer en cherchant `a provoquer une collision.
 */
class Kamikaze : public Comportement {
private :
public :
    Kamikaze( void );//!< Le Constructeur par defaut
    ~Kamikaze( void ); //!< Le Destructeur
    double orientationPlusProche(Bestiole & b) const;//!< retourne l'orientation vers la bestiole la plus proche
    void accept(Visiteur *v, Bestiole *b) const override; 
};
#endif