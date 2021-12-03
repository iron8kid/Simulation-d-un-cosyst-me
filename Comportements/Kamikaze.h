#ifndef _KAMIKAZE
#define _KAMIKAZE

#include "Comportement.h"
#include <iostream>


class Kamikaze : public Comportement {
private :
public :
    Kamikaze( void );
    void accept(Visitor *v) const override; 
};
#endif