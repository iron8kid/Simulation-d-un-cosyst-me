/*! \file Peureuse.h
 *  implementation of class Peureuse headers
 */
#ifndef _PEUREUSE
#define _PEUREUSE

#include "Comportement.h"
#include "Milieu.h"
// #include "Bestiole.h"
#include <iostream>

/*!
 *  \class Peureuse
 *  \brief  orsque le nombre de bestioles autour d’une bestiole dite peureuse
devient trop important, celle-ci fuit `a vive allure dans la direction oppos´ee avant de reprendre sa
vitesse de croisière.
 */
class Peureuse : public Comportement {
private :
    int nbVoisinsMax;//!< Le nombre max des bestoiles voisines pour declancher le comportoment Peureuse
public :
	Peureuse(int nbVoisins);//!< Le Constructeur par defaut
    ~Peureuse( void );//!< Le Distructeur
    bool checkNeighbours(const Bestiole & b) const;//!< retourne si le nombre de voisines depasse nbVoisinsMax
    void accept(Visiteur *v, Bestiole *b) const override; 
};
#endif