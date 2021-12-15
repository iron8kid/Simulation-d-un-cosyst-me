#include "Bestiole.h"

#include "Milieu.h"
#include "VisiteurDeplacement.h"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <random>

const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::SPEED_FACTOR = 1.5;
const double      Bestiole::LIMITE_VUE = 50.;
const int         Bestiole::AGE_MAX = 100;

int               Bestiole::next = 0;


Bestiole::Bestiole( Milieu & milieu )
{

   identite = ++next;

   // cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y =  0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;
   age_limit = rand() % 100 + 1; // age entre 1 et 100
   age_actuel = 0;
   monMilieu = &milieu;
   comportement = monMilieu->comportements[rand() % 5];
   // couleur = new T[ 3 ];
   couleur = comportement->getCouleur();
   // memcpy(couleur, comportement->getCouleur(), 3*sizeof(T));
/*   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );*/

}


Bestiole::Bestiole( const Bestiole & b )
{

   identite = ++next;

   //cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   monMilieu=b.monMilieu;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   age_limit = b.age_limit;
   age_actuel = b.age_actuel;
   comportement = b.comportement;
   couleur = comportement->getCouleur();
   // couleur = new T[ 3 ];
   // memcpy( couleur, b.couleur, 3*sizeof(T) );

}

Bestiole::~Bestiole( void )
{
   // cout << identite <<" dest Bestiole" << endl;
   //delete[] couleur;


}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}
void Bestiole::bouge( int xLim, int yLim )
{

   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}

void Bestiole::increment_age( void )
{
   age_actuel++;
}


void Bestiole::action( Milieu & monMilieu )
{
   increment_age();
   comportement->accept(monMilieu.visiteurDeplacement, this);
   bouge( monMilieu.getWidth(), monMilieu.getHeight() );

}


void Bestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}

// CONDITIONS

bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}

Bestiole& Bestiole::operator=( const Bestiole& other)
{
   // std::cout <<"operator = called" << std::endl;
   // Guard self assignment
    if (this == &other)
        return *this;



   x = other.x;
   y = other.y;
   cumulX = cumulY = 0.;
   orientation = other.orientation;
   vitesse = other.vitesse;
   age_limit = other.age_limit;
   age_actuel = other.age_actuel;
   monMilieu = other.monMilieu;
   comportement = other.comportement;
   couleur = comportement->getCouleur();
   // delete[] couleur;
   // couleur = new T[3];
   // memcpy( couleur, other.couleur, 3*sizeof(T) );
   return *this;
}


bool Bestiole::jeTeVois( const Bestiole & b ) const
{

   double         dist;


   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= LIMITE_VUE );

}

bool Bestiole::estTropVieux( void ) const
{
   return (age_actuel >= age_limit);
}


// SETTERS
void Bestiole::setOrientation(double newOrientation){
   orientation = newOrientation;
}

// GETTERS
int Bestiole::getID() const
{
   return identite;
}
double Bestiole::getAFF_SIZE() const
{
    return AFF_SIZE;
}
int Bestiole::getX() const
{
    return x;
}
int Bestiole::getY() const
{
    return y;
}
double Bestiole::getCumulY() const
{
    return cumulY;
}
double Bestiole::getCumulX() const
{
    return cumulX;
}
double Bestiole::getOrientation() const
{
    return orientation;
}
bool Bestiole::getEscape() const
{
    return escaping;
}

void Bestiole::setEscape(bool new_state)
{
    escaping=new_state;
}
double Bestiole::getVitesse() const
{
    return vitesse;
}
void Bestiole::accelerer(bool boost)
{
    if(boost)
    {
        vitesse=vitesse*SPEED_FACTOR;
    }
    else
    {
        vitesse=vitesse/SPEED_FACTOR;
    }
}


double Bestiole::distance( const Bestiole & b ) const
{
    return (std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) ) );
}

double Bestiole::angle( const Bestiole & b ) const
{
    return (-atan2(b.y-y,b.x-x) );
}

Milieu& Bestiole::getMilieu() const
{
   return *monMilieu;
}