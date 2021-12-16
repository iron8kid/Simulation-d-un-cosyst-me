#include <iostream>
#include "Prevoyante.h"
#include "../Visiteur.h"
#include <cmath>


//! Le Constructeur par defaut
Prevoyante::Prevoyante( )
{
    couleur[ 0 ] = static_cast<int>( static_cast<double>(239.));
    couleur[ 1 ] = static_cast<int>( static_cast<double>(110.));
    couleur[ 2 ] = static_cast<int>( static_cast<double>(0.));
}

//! Le Distructeur
Prevoyante::~Prevoyante( void )
{
    cout << "dest Prevoyante" << endl;

}

/*!
 * \param b: pointer vers une bestoile
 * \param k: nombre de pas
 * \return double: retourne la prédiction de la position/orientation d'une bestiole aprés k pas.
 */
Point Prevoyante::PosAtK(int k,Bestiole *b) const
{
    int            xLim=(b->getMilieu()).getWidth();
    int            yLim=(b->getMilieu()).getHeight();
    Point          tmp;
    double         nx, ny;
    double         dx;
    double         dy;
    double         cx=b->getCumulX();
    double         cy=b->getCumulY();
    tmp.x=b->getX();
    tmp.y=b->getY();
    tmp.angle=b->getOrientation();
    for(int i=1; i<=k; ++i)
    {

        dx = cos( tmp.angle)*b->getVitesse();
        dy = -sin( tmp.angle)*b->getVitesse();
        nx = tmp.x+dx+cx;
        ny = tmp.y+dy+cy;
        if ( (nx < 0) || (nx > xLim - 1) ) {
            tmp.angle = M_PI - tmp.angle;
            cx = 0.;
        }
        else {
            tmp.x = static_cast<int>( nx );
            cx += nx - tmp.x;
        }

        if ( (ny < 0) || (ny > yLim - 1) ) {
            tmp.angle = -tmp.angle;
            cy = 0.;
        }
        else {
            tmp.y = static_cast<int>( ny );
            cy += ny - tmp.y;
        }

    }
    return tmp;

}

/*!
 * \param b: pointer vers une bestoile
 * \return (double): retourne la nouvelle orientation pour eviter les collisions.
 */
double Prevoyante::escapeDirection(Bestiole & b) const
{
    int k=2;
    double aff_size=b.getAFF_SIZE();
    Point bPos=PosAtK(k,&b);
    Point tmpPos;
    double mean_angle=0;
    int nbVoisins=0;

    for ( auto it = b.getMilieu().getListeBestioles().begin() ; it != b.getMilieu().getListeBestioles().end() ; ++it )
    {
        if (((*it).getID() != b.getID()) && (b.jeTeVois(*it)))
        {
            nbVoisins +=1;
            tmpPos=PosAtK(k,&(*it));
            if(sqrt(pow(tmpPos.x-bPos.x,2)+pow(tmpPos.y-bPos.y,2))<=aff_size*2)
            {
                mean_angle+=(*it).getOrientation();
            }

        }
    }
    return (nbVoisins)? M_PI+(mean_angle/nbVoisins) : -1;



}

void Prevoyante::accept(Visiteur *v, Bestiole *b) const 
{
    // std::cout<<"Prevoyante Element accepted Visitor" << std::endl;
    v->visitPrevoyante(this, b);
}
