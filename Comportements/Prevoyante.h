/*! \file Prevoyante.h
 *  implementation of class Prevoyante headers
 */
#ifndef _PREVOYANTE
#define _PREVOYANTE

#include "Comportement.h"
#include "Milieu.h"
#include <iostream>
struct Point{
    int x, y;
    double angle;
};
/*!
 *  \class Prevoyante
 *  \brief  une bestiole dite pr´evoyante estime les trajectoires des bestioles
autour d’elle et ajuste sa trajectoire pour ´eviter d’´eventuelles collisions
 */
class Prevoyante : public Comportement {
private :
public :
    Prevoyante( void );//!< Le Constructeur par defaut
    ~Prevoyante( void );//!< Le Distructeur
    Point PosAtK(int k,Bestiole *b) const;//!< retourne la prédiction de la position/orientation d'une bestiole aprés k pas.
    double escapeDirection(Bestiole & b) const;//!< retourne la nouvelle orientation pour eviter les collisions
    void accept(Visiteur *v, Bestiole *b) const override; 
};
#endif