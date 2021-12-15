#include "MultiComportement.h"
#include "Visiteur.h"

int MultiComportement::comp_timer=0;

MultiComportement::MultiComportement()
{
    couleur[ 0 ] = static_cast<int>( static_cast<double>(100.));
    couleur[ 1 ] = static_cast<int>( static_cast<double>(100.));
    couleur[ 2 ] = static_cast<int>( static_cast<double>(100.));
}

MultiComportement::~MultiComportement( void )
{
    cout << "dest MultiComportement" << endl;

}

int MultiComportement::getComportement() const
{
    int t=this->getTimer();
    if(t==0)
    {
        t=(t+1)%20;
        this->setTimer(t);
        return rand() % 4;
    }
    else
    {
        t=(t+1)%20;
        this->setTimer(t);
        return -1;
    }
}
int MultiComportement::getTimer()
{
    return comp_timer;
}
void MultiComportement::setTimer(int t)
{
    comp_timer=t;
}
void MultiComportement::accept(Visiteur *v, Bestiole *b) const
{
    v->visitMultiComportement(this, b);
}