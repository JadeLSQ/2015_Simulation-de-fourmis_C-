#ifndef FOURMIS_HPP_INCLUDED
#define FOURMIS_HPP_INCLUDED
#include "coord.hpp"
#include <map>


/**Le type abstrait fourmi representant une fourmi**/

 struct fourmi
{
    coord c;
    bool ChargeSucre;
} ;

const int NB_FOURMIS =12;

/**Le type abstrait ensFourmis representant un ensemble de fourmis**/
struct ensFourmis
{
    fourmi tabF [NB_FOURMIS];
    int nbF;

};

/*constructeurs*/
/** crée une fourmi ne portant pas de surcre, a partir de ses coordonnees sur la grille

 * @c coordonée de la fourmi que l'on veut creer

 * @return variable type fourmi representant la fourmi crée

 **/
fourmi creerFourmi (coord c);


/* Accès */
/** retourne coordonnees de la fourmi

 * @f la fourmi dont on cherche les coordonnees

 * @return variable type coord f.c representant les coordonnee de la fourmi f

 **/
coord lireCoord (fourmi f);

/*Prédicats*/
/** retourne true si la fourmi cherche du sucre
  * @f variable d'entree la fourmi
  * @return un booleen
 **/

bool chercheSucre (fourmi f);

/** retourne true si la fourmi rentre au nid

 * @f variable donnee la fourmi

 * @return un booleen

 **/
bool rentreNid (fourmi f);

/*Modifications*/
/** supprime la charge de sucre portee par la fourmi
 * @f variable donnee-resultat la fourmi
 **/
void dechargerSucre (fourmi &f);


/** ajoute une charge de sucre sur la fourmi
 * @f variable donnee-resultat la fourmi
 **/
void chargerSucre (fourmi &f);

/** crée un ensemble de fourmi positionnées aux coordonnées spécifiées par l'ensemble de coordonnées
 * @eC variable de type ensCoord
 * @eF variable de type ensFourmis
 **/
 void chargerEnsFourmis (ensCoord eC, ensFourmis eF);



#endif // FOURMIS_HPP_INCLUDED



