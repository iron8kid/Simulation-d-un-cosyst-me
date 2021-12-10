#ifndef _VISITEUR_DEPLACEMENT_
#define _VISITEUR_DEPLACEMENT_

#include "Visiteur.h"

class VisiteurDeplacement: public Visiteur {
   void visitPeureuse(Peureuse *c, Bestiole *b);
   void visitGregaire(Gregaire *c, Bestiole *b);
   void visitKamikaze(Kamikaze *c, Bestiole *b);
   void visitPrevoyante(Prevoyante *c, Bestiole *b);
};


#endif
