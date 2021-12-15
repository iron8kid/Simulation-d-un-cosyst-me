#ifndef _VISITEUR_DEPLACEMENT_
#define _VISITEUR_DEPLACEMENT_

#include "Visiteur.h"

class VisiteurDeplacement: public Visiteur {
public:
   VisiteurDeplacement(){};
   void visitPeureuse(const Peureuse *c, Bestiole *b) override;
   void visitGregaire(const Gregaire *c, Bestiole *b) override;
   void visitKamikaze(const Kamikaze *c, Bestiole *b) override;
   void visitPrevoyante(const Prevoyante *c, Bestiole *b) override;
   void visitMultiComportement(const MultiComportement *c, Bestiole *b) override;
};


#endif
