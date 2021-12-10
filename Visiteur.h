#ifndef _VISITEUR_
#define _VISITEUR_

#include "Comportements/Kamikaze.h"
#include "Comportements/Gregaire.h"
#include "Comportements/Peureuse.h"
#include "Comportements/Prevoyante.h"
#include "Bestiole.h"

class Visiteur {
public:
   virtual void visitPeureuse(const Peureuse *c, Bestiole *b)=0;
   virtual void visitGregaire(const Gregaire *c, Bestiole *b)=0;
   virtual void visitKamikaze(const Kamikaze *c, Bestiole *b )=0;
   virtual void visitPrevoyante(const Prevoyante *c, Bestiole *b)=0;
};


#endif
