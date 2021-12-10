#include <iostream>
#include "VisiteurDeplacement.h"

void VisiteurDeplacement::visitGregaire(const Gregaire *c, Bestiole *b) 
{
    std::cout << "Visiting " << std::endl;
}

void VisiteurDeplacement::visitPeureuse(const Peureuse *c, Bestiole *b)
{
    std::cout << "Visiting " << std::endl;
}


void VisiteurDeplacement::visitKamikaze(const Kamikaze *c, Bestiole *b)
{
    std::cout << "Visiting " << std::endl;
}

void VisiteurDeplacement::visitPrevoyante(const Prevoyante *c, Bestiole *b)
{
    std::cout << "Visiting " << std::endl;
}