#include <iostream>
#include "VisiteurDeplacement.h"
#include <limits>

void VisiteurDeplacement::visitGregaire(const Gregaire *c, Bestiole *b)
{
    // std::cout << "Visiting Gregaire" << std::endl;
    b->setOrientation(c->meanOrientation(b->getMilieu(),*b));
}

void VisiteurDeplacement::visitPeureuse(const Peureuse *c, Bestiole *b)
{
    // std::cout << "Visiting Peureuse " << std::endl;
    if (b->getEscape() && !(c->checkNeighbours(*b)))
    {
        b->setEscape(false);
        b->accelerer(false);
    }
    else if(c->checkNeighbours(*b) && !(b->getEscape()))
    {
        b->setOrientation(-b->getOrientation());
        b->setEscape(true);
        b->accelerer(true);
    }


}


void VisiteurDeplacement::visitKamikaze(const Kamikaze *c, Bestiole *b)
{
    // std::cout << "Visiting Kamikaze" << std::endl;
    double angle=c->orientationPlusProche(*b);
    if(angle!=numeric_limits<double>::max())
    {
        b->setOrientation(angle);
    }
}

void VisiteurDeplacement::visitPrevoyante(const Prevoyante *c, Bestiole *b)
{
    // std::cout << "Visiting Prevoyante" << std::endl;
    double angle=c->escapeDirection(*b);
    if(angle!=-1)
    {
        b->setOrientation(angle);
    }

}
void VisiteurDeplacement::visitMultiComportement(const MultiComportement *c, Bestiole *b)
{

    // std::cout << "Visiting MultiComportement" << std::endl;
    int tmp=c->getComportement();
    if (tmp!=-1)
    {
        b->getMilieu().comportements[tmp]->accept(b->getMilieu().visiteurDeplacement, b);
    }
}