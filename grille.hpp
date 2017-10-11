#ifndef GRILLE_HPP_INCLUDED
#define GRILLE_HPP_INCLUDED
#include <algorithm>
#include "coord.hpp"
#include "place.hpp"


/**Le type abstrait grille**/

const int TAILLE = 20;
struct grille
{
    place tabPlace [TAILLE][TAILLE];
    int nbP;
} ;
/** initialise la grille avec une grille vide
 * @g grille en donnee
 **/
void chargerGrilleVide ( grille &g);

/** donne en resultat la place de la grille situee aux coordonnees indiquees
 * @g grille en donnee
 * @c coord en donnee
 * @p place en resultat
 **/
void chargerPlace (grille g, coord c, place &p);

/** ranger la place dans la grille
 * @g grille en donnee-resultat
 * @p place en resultat
 **/
void rangerPlace (grille &g, place p);

/** place des elements de nid sur la grille passee en premier parametre, a l'ensemble
des coordonnees fournies en 2eme parametre
 * @g grille en donnee-resultat
 * @cNid ensemble de coordonnees
 **/
void placerNid( grille &g, ensCoord cNid);

/** place des elements de sucre sur la grille passee en premier parametre, a l'ensemble
des coordonnees fournies en 2eme parametre
 * @g grille en donnee-resultat
 * @cSucre ensemble de coordonnees
 **/
void placerSucre (grille &g, ensCoord cSucre);

/** prend une grille et un ensemble de fourmis en parametres, et pose l'ensemble de fourmis
sur la grille
 * @g grille en donnee-resultat
 * @eF ensemble de Fourmis
 **/
void placerFourmis (grille &g, ensFourmis eF);

/** prend une grille en parametre et linearise l'intensite en pheromones de nid des cases de la grille
 * @g grille en donnee-resultat
 **/
void lineariserPheroNid (grille &g);

/** initialise la grille en placant les fourmis, le sucre et le nid et en linearisant les pheromones
de nid
 * @cNid ensCoord des elements de nid en donnee
 * @cSucre ensCoord des elements de sucre en donnee
 * @eF ensFourmis en donnee
 * @g grille en resultat
 **/
void initialiserGrille (ensCoord cNid, ensCoord cSucre, ensFourmis eF, grille &g);

/** diminue l'intensite des pheromones de sucre sur la grille pour modeliser leur evaporation
 * @g grille en resultat
 **/
void diminuerPheroSucreGrille( grille &g);

#endif // GRILLE_HPP_INCLUDED
