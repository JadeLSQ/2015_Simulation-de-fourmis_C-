#include <iostream>
#include "fourmis.hpp"
using namespace std;

/*constructeurs*/
fourmi creerFourmi (coord c)
{
    fourmi f;
    f.c =c;
    f.ChargeSucre = false;
    return f;
}

/* Accès */
coord lireCoord (fourmi f)
{
    return f.c;
}

/*Prédicats*/
bool chercheSucre (fourmi f)
{
   return !(f.ChargeSucre);
}

bool rentreNid (fourmi f)
{
    return (f.ChargeSucre);
}

/*Modifications*/
void dechargerSucre (fourmi &f)
{
    f.ChargeSucre = false;
}

void chargerSucre (fourmi &f)
{
    f.ChargeSucre = true;
}

void chargerEnsFourmis ( ensCoord eC, ensFourmis eF){

for (int i=0; i<eC.nbC; i++){
    fourmi f =creerFourmi(eC.tableCoord[i]);
}

}
