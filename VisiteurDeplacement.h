/*! \file VisiteurDeplacement.h
 *  implementation of class VisiteurDeplacement headers
 */
#ifndef _VISITEUR_DEPLACEMENT_
#define _VISITEUR_DEPLACEMENT_

#include "Visiteur.h"

/*!
 *  \class VisiteurDeplacement
 *  \brief  LE visiteurDeplamcement permet d'adapter le deplacement de chauqe bestiole en fonction de son comportement
 */
class VisiteurDeplacement: public Visiteur {
public:
   VisiteurDeplacement(){}; //!< Constructeur
   void visitPeureuse(const Peureuse *c, Bestiole *b) override; //!< Methode pour deplacer une Peureuse
   void visitGregaire(const Gregaire *c, Bestiole *b) override; //!< Methode pour deplacer une Gregaire
   void visitKamikaze(const Kamikaze *c, Bestiole *b) override; //!< Methode pour deplacer une Kamikaze
   void visitPrevoyante(const Prevoyante *c, Bestiole *b) override; //!< Methode pour deplacer une Prevoyante
   void visitMultiComportement(const MultiComportement *c, Bestiole *b) override; //!< Methode pour deplacer une MultiComportement
};


#endif
