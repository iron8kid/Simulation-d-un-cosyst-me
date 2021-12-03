#include <iostream>
#include "VisiteurDeplacement.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Prevoyante.h"
#include "Kamikaze.h"


void VisiteurDeplacement::visitGregaire(Gregaire *c, Bestiole *b) 
{
    std::cout << "Visiting " << std::endl;
}

void VisiteurDeplacement::visitPeureuse(Peureuse *c, Bestiole *b)
{
    std::cout << "Visiting " << std::endl;
}


void VisiteurDeplacement::visitKamikaze(Kamikaze *c, Bestiole *b)
{
    std::cout << "Visiting " << std::endl;
}

void VisiteurDeplacement::visitPrevoyante(Prevoyante *c, Bestiole *b)
{
    std::cout << "Visiting " << std::endl;
}