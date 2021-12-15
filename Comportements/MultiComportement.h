#ifndef _Multicomportement
#define _Multicomportement

#include "Comportement.h"

#include <iostream>

class MultiComportement: public Comportement {
private :
    static int comp_timer;
public :
    MultiComportement( void );
    ~MultiComportement(void);
    static int getTimer();
    static void setTimer(int t);
    int getComportement() const;
    void accept(Visiteur *v, Bestiole *b) const override;
};
#endif