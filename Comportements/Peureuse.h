#ifndef _PEUREUSE
#define _PEUREUSE

#include "Comportement.h"
#include <iostream>


class Peureuse : public Comportement {
private :
    int nbVoisinsMax;
public :
	Peureuse(int nbVoisins);
    void accept(Visitor *v) const override; 
};
#endif