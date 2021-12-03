#ifndef _VISITEUR_
#define _VISITEUR_

#include <iostream>

class Visiteur {
public:
   virtual void visitPareseuse(const Pareseuse *c, Bestiole *b)=0;
   virtual void visitGregaire(const Gregaire *c, Bestiole *b)=0;
   virtual void visitKamikaze(const Kamikaze *c, Bestiole *b )=0;
   virtual void visitPrevoyante(const Prevoyante *c, Bestiole *b)=0;
};


#endif
