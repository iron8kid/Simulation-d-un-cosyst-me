#ifndef _COMPORTEMENT
#define _COMPORTEMENT

#include <iostream>

class Visiteur

class Comportement 
{
protected :
       T               * couleur;; //!< Name of the MultimediaElement
public:
    virtual void accept(Visitor *v) const=0; //!< Abstract Method to allow any visitor and for the child to implements this method
    T getCouleur() const; //!< Method to get the name of the MultimediaElement
};

#endif