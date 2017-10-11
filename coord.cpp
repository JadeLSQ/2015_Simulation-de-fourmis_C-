#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "coord.hpp"

using namespace std;

coord creerCoord(int lig, int col)
{
    coord point;
    point.x=lig;
    point.y=col;
    return point;

}
void afficherCoord (coord c)
{
    cout<< "(" << c.x << ";" << c.y <<")";
}

bool coordonneesEgales( coord p1, coord p2)
{
    if (p1.x==p2.x&&p1.y==p2.y)
    {
        return true;
    }
    else return false;
}

void afficherEnsCoord ( ensCoord eC)
{

    for (int i=0; i< eC.nbC; i++)
    {
        afficherCoord(eC.tableCoord[i]);
        cout << endl;
    }
}

ensCoord creerEnsCoordVide ()
{
    ensCoord eC;
    eC.nbC=0;
    return eC;
}

void ajouterCoord ( ensCoord& eC, coord c)
{
    if ( eC.nbC == NB_COORD)
    {
        cout << " Le tableau est plein " ;
    }
    else
    {
        eC.tableCoord[eC.nbC]=c;
        eC.nbC=eC.nbC+1;
    }
}

ensCoord trouverVoisins(coord c)
{
    int TAILLE=20;
    int lig= c.x;
    int col= c.y;

    int imin = max(lig-1,0);
    int imax = min(lig+1,TAILLE-1);
    int jmin = max(col-1,0);
    int jmax = min(col+1,TAILLE-1);

    ensCoord ensVoisins= creerEnsCoordVide();
    for (int i=imin; i<=imax; i++)
    {
        for (int j=jmin; j<=jmax; j++)
        {
            coord p=creerCoord(i,j);
            if (!coordonneesEgales(p,c))
            {
                ajouterCoord(ensVoisins,p);
            }
        }
    }
    return ensVoisins;
}

coord choisirCoordAleatoirement( ensCoord eC)
{
    coord c;
    srand(time(0));
    int i;
        i = (rand()%eC.nbC);

    c=eC.tableCoord[i];
    return c;
}

coord lireElement (ensCoord eC, int n){
if (n>eC.nbC) cout<< "choisissez une valeur plus petite"<< endl;
else { coord c=eC.tableCoord[n];
       return c;
     }
}

int cardinal(ensCoord eC){
return eC.nbC;
}
