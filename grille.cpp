#include <iostream>
#include <algorithm>
#include "grille.hpp"
using namespace std;


void chargerGrilleVide ( grille &g)
{
    {
        coord c;
        for (int i= 0; i< TAILLE; i++)
        {
            c.x = i;
            for (int j = 0; j < TAILLE; j++)
            {
                c.y =j;
                creerPlaceVide(c, g.tabPlace[i][j]);
            }
        }
    }

}

void chargerPlace (grille g, coord c, place &p)
{
   p=g.tabPlace[c.x][c.y];

}


void rangerPlace (grille &g, place p)
{
    coord c= p.c;
    g.tabPlace[c.x][c.y]=p;
}

void placerNid( grille &g, ensCoord cNid)
{
    place p;

    for (int i=0; i<cNid.nbC; i++)
    {
        coord c=cNid.tableCoord[i];
        chargerPlace(g,c,p);

        poserNid(p);
        poserPheroNid(p,1);
        rangerPlace(g,p);

    }

}

void placerSucre (grille &g, ensCoord cSucre)
{
    place p;

    for (int i=0; i<cSucre.nbC; i++)
    {
        coord c=cSucre.tableCoord[i];
        chargerPlace(g,c,p);
        poserSucre(p);
        poserPheroSucre(p);
        rangerPlace(g,p);

    }
}

void placerFourmis (grille &g, ensFourmis eF)
{
    fourmi f;
    place p;
    coord c;
    for (int i=0; i<eF.nbF; i++)
    {
        f= eF.tabF[i];
        c= lireCoord(f);
        chargerPlace(g,c,p);
        poserFourmi(p);
        rangerPlace(g,p);
    }

}


void lineariserPheroNid (grille &g)
{
    coord c,v;
    ensCoord ensVoisins;
    place p,voisin;

    for (int x=1; x<=TAILLE; x++)
    {
        for (int i=0; i<TAILLE; i++)
        {
            for (int j=0; j<TAILLE; j++)
            {
                c= creerCoord(i,j);
                chargerPlace(g,c,p);
                if (lirePheroNid(p)<1.)
                {
                    ensVoisins=trouverVoisins(c);
                    double maxPheroVoisins=0;
                    for (int z=0; z<ensVoisins.nbC; z++)
                    {
                        v=ensVoisins.tableCoord[z];
                        chargerPlace(g,v,voisin);
                        double y=lirePheroNid(voisin);
                        maxPheroVoisins= max(maxPheroVoisins,y);
                    }


                    double pheroRes= max ((maxPheroVoisins-(1/(double) x)),0.0);
                    poserPheroNid(p,pheroRes);
                    rangerPlace(g,p);
                }
            }
        }
    }

}

void initialiserGrille (ensCoord cNid, ensCoord cSucre, ensFourmis eF, grille &g)
{
    chargerGrilleVide(g);

    placerFourmis (g,eF);
    placerNid (g,cNid);
    placerSucre (g,cSucre);

    lineariserPheroNid (g);

}

void diminuerPheroSucreGrille( grille &g)
{
    place p;
    for (int i=0; i<TAILLE; i++)
    {
        for (int j=0; j< TAILLE; j++)
        {
            if(g.tabPlace[i][j].PheroSucre>0) g.tabPlace[i][j].PheroSucre=g.tabPlace[i][j].PheroSucre-5;
        }
    }
}




