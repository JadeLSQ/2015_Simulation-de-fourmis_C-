#include <iostream>
#include "fourmis.hpp"
#include "place.hpp"

using namespace std;

place creerPlaceVide (coord c, place &p)
{
    p.c = c;
    p.Contientfourmi = false ;
    p.ContientSucre = false ;
    p.ContientNid = false ;
    p.PheroSucre = 0 ; // entre 0 et 255
    p.PheroNid = 0 ; // entre 0 et 1
    p.nbSucre=0;
}

double lirePheroNid (place p)
{
    double N;
    if (p.PheroNid >= 0)
    {
        N = p.PheroNid;
    }
    else
    {
        cout << "impossible de lire PheroNid car sa valeur est negative" << endl;
    }
    return N;
}

int lirePheroSucre (place p)
{
    int S;
    S = p.PheroSucre;
    return S;
}

bool contientSucre (place p)
{
    return (p.ContientSucre);
}

bool contientNid (place p)
{
    return (p.ContientNid);
}

bool contientFourmi (place p)
{
    return (p.Contientfourmi);
}

bool surUnePiste (place p)
{
    return (p.PheroSucre > 0);

}

/** l'intensite des pheromones de nid sur p1 est plus importante que celle sur p2
 **/
bool plusProcheNid (place p1, place p2)
{
    return (p1.PheroNid > p2.PheroNid);

}

bool vide (place p){
if (!p.Contientfourmi && !p.ContientNid && !p.ContientSucre)
    return true;
else return false;
}

/** l'intensite des pheromones de nid sur p1 est moins importante que celle sur p2
 **/
bool plusLoinNid (place p1, place p2)
{
    return (p1.PheroNid < p2.PheroNid);

}

void poserSucre (place &p)
{
    p.ContientSucre = true;
    p.ContientNid=false;
    p.Contientfourmi=false;
    p.nbSucre=nb_SUCRE;
}

void poserNid (place &p)
{
    p.ContientNid = true;
    p.Contientfourmi=false;
    p.ContientSucre=false;
    p.PheroNid = 1;
}

void poserFourmi (place &p)
{
    p.Contientfourmi = true;
    p.ContientNid=false;
    p.ContientSucre=false;
}

void poserPheroNid (place &p, float In)
{
    p.PheroNid = In;
}

void poserPheroSucre (place &p)
{
    p.PheroSucre = 255;
}

void diminuerPheroSucre (place &p)
{
    if (p.PheroSucre >= 5)
        p.PheroSucre -= 5;
}

void deplacerFourmi (fourmi &f, place &p1, place &p2)
{
    coord x= f.c;
    coord y=p1.c;
    if(coordonneesEgales(x,y))
    {
        f.c=p2.c ;
        p2.Contientfourmi = true;
        p2.ContientNid=false;
        p2.ContientSucre=false;

        p1.Contientfourmi = false;
        p1.ContientNid=false;
        p1.ContientSucre=false;
    }

    else
    {
        cout << "la fourmi n'est pas sur cette place ";
    }

}
