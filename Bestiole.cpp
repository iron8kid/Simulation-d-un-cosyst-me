#include "Bestiole.h"
#include "Milieu.h"
#include "VisiteurDeplacement.h"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <random>

const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 1.5;
const double      Bestiole::SPEED_FACTOR = 1.5;
const double      Bestiole::LIMITE_VUE = 50.;
const int         Bestiole::AGE_MAX = 1000;


int               Bestiole::next = 0;


Bestiole::Bestiole( Milieu & milieu )
{

   identite = ++next;

   // cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y =  0;
   collisionState=false;
   mustDie=false;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;
   age_limit = rand() % AGE_MAX + 1; // age entre 1 et 100
   //age_limit = AGE_MAX;
   age_actuel = 0;
   monMilieu = &milieu;
   comportement = monMilieu->comportements[rand() % 5];
   camouflage = Camouflage();
   carapace = Carapace();
   nageoire = Nageoire();
   couleur = comportement->getCouleur();
   oeil = Oeil();
   oreille = Oreille();
}
Bestiole::Bestiole( Milieu & milieu, int c )
{

    identite = ++next;

    // cout << "const Bestiole (" << identite << ") par defaut" << endl;

    x = y =  0;
    collisionState=false;
    mustDie=false;
    cumulX = cumulY = 0.;
    orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
    vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;
    age_limit = rand() % AGE_MAX + 1; // age entre 1 et 100
    //age_limit = AGE_MAX;
    age_actuel = 0;
    monMilieu = &milieu;
    comportement = monMilieu->comportements[c];
    camouflage = Camouflage();
    carapace = Carapace();
    nageoire = Nageoire();
    couleur = comportement->getCouleur();
    oeil = Oeil();
    oreille = Oreille();
}


Bestiole::Bestiole(const Bestiole & b)
{

   identite = ++next;

   //cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   collisionState=false;
   mustDie=false;
   monMilieu=b.monMilieu;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   age_limit = b.age_limit;
   age_actuel = 0;
   comportement = b.comportement;
   camouflage = b.camouflage;
   carapace = b.carapace;
   nageoire = b.nageoire;

   couleur = comportement->getCouleur();
   oeil = b.oeil;
   oreille = b.oreille;

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

//Methode pour se deplacer
void Bestiole::bouge( int xLim, int yLim )
{

   double         nx, ny;
   double         dx = cos( orientation )*vitesse*nageoire.getVitesseNageoire()/carapace.getRalentissement();
   double         dy = -sin( orientation )*vitesse*nageoire.getVitesseNageoire()/carapace.getRalentissement();
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
// Methode pour vieillir
void Bestiole::increment_age( void )
{
   age_actuel++;
}

//Methode pour faire toutes les actions neccessaires par tour
void Bestiole::action( Milieu & monMilieu )
{
   increment_age();
   comportement->accept(monMilieu.visiteurDeplacement, this);
   bouge( monMilieu.getWidth(), monMilieu.getHeight() );

}

// methode pour être afficher
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
   oeil = other.oeil;
   oreille = other.oreille;
   return *this;
}

// methode pour savoir si la bestiole est visible ou non par this
bool Bestiole::jeTeVois( const Bestiole & b ) const
{  
   double dist = this->distance(b);
   double angle = std::remainder(this->angle(b)-orientation, 2*M_PI);
   double camouflage_autre = b.getCamouflage();

   bool oeil_cond = oeil.detecte(dist, angle, camouflage_autre);
   bool oreille_cond = oreille.detecte(dist, camouflage_autre);

   return ( oeil_cond || oreille_cond );

}
// methode pour savoir si this a atteint son age limite et doit mourir de vieillesse
bool Bestiole::estTropVieux( void ) const
{
   return (age_actuel >= age_limit);
}
void Bestiole::collision()
{
    bool stillInCollison=false;
    for ( auto it = monMilieu->getListeBestioles().begin() ; it != monMilieu->getListeBestioles().end() ; ++it )
    {
        if (((*it).getID() != identite) && (this->distance(*it)<AFF_SIZE))
        {
            stillInCollison=true;
            if(!collisionState)
            {
                orientation=-orientation;
                collisionState=true;

            }

        }
    }
    if(!stillInCollison)
    {
        collisionState=false;
    }
}

// SETTERS
void Bestiole::setOrientation(double newOrientation){
   orientation = newOrientation;
}
void Bestiole::setcollisionState(bool newState)
{
    collisionState=newState;
}

// GETTERS
bool Bestiole::getcollisionState() const
{
    return collisionState;
}
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
bool Bestiole::getMustDie() const
{
    return mustDie;
}
void Bestiole::setMustDie(bool new_state)
{

    mustDie=new_state;

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

double Bestiole::getCamouflage( ) const
{
   return camouflage.getCamouflage();
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

// methode pour savoir la distance qui sépare les deux bestioles
double Bestiole::distance( const Bestiole & b ) const
{
    return (std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) ) );
}

// methode pour savoir l'angle entre les deux bestioles
double Bestiole::angle( const Bestiole & b ) const
{
    return (-atan2(b.y-y,b.x-x) );
}

Milieu& Bestiole::getMilieu() const
{
   return *monMilieu;
}

double Bestiole::getProtection() const
{
   return carapace.getProtection();
}