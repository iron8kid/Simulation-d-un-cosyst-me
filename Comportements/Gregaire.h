/*! \file Gregaire.h
 *  implementation of class Gregaire headers
 */

#ifndef _GREGAIRE
#define _GREGAIRE

#include "Comportement.h"

#include <iostream>
/*!
 *  \class Gregaire
 *  \brief  une bestiole dite grégaire ajuste sa direction sur la direction moyenne
des bestioles environnantes.
 */
class Gregaire : public Comportement {
private :
public :
	Gregaire( void ); //!< Le Constructeur par defaut
    ~Gregaire(void) ; //!< Le Distructeur
    double meanOrientation(Milieu & monMilieu,Bestiole & b) const; //!< retourne la direction moyenne des bestioles environnantes.
    void accept(Visiteur *v, Bestiole *b) const override;
};
#endif