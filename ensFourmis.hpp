#ifndef ENSFOURMIS_HPP_INCLUDED
#define ENSFOURMIS_HPP_INCLUDED
#include "fourmi.hpp"
#include <vector>
#include <map>

/*le type abstrait ensfoumi represente une fourmi. Il est specifie de la maniere suivante*/
const int NB_Fourmis = 50;
struct ensFourmis{
    Fourmi tab[NB_Fourmis];
    int nb_fo;
};

/*cree un ensemble de fourmis positionnees aux coord
specifiees par l'ensemble de coord fourni en 2eme parametre
*/
void chargerEnsFourmi( ensFourmis &EF, ensCoord EC);

/*
*/
void ensfourmisVide(ensFourmis &EF);

/*
*/
void ajoutFourmis(ensFourmis &EF, Fourmi f);


#endif // ENSFOURMIS_HPP_INCLUDED
