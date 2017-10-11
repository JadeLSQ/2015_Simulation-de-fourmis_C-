#ifndef COORD_HPP_INCLUDED
#define COORD_HPP_INCLUDED
#include <map>


/**Le type abstrait coord représentant les cordonnées d'une fourmi est spécifié de la manière suivante:**/

typedef struct
{
    int x;
    int y;
} coord;


/** crée les coordonnées
 * @lig coordonée sur l'axe des abscisses
 * @col coordonée sur l'axe des ordonnées
 *
 * @return variable type coord initialisé à (lig;col)
 **/
coord creerCoord(int lig, int col);

/** affiche les coordonnées sous la forme (lig;col)
 * @c variable de type coord
 **/
void afficherCoord (coord c);

/** compare si deux coordonnées sont égales ou non
 * @p1 variable de type coord
 * @p2 variable de type coord
 *
 * @return booléen
 **/
bool coordonneesEgales( coord p1, coord p2);

/** Le type abstrait ensCoord représentant un ensemble d'au maximum NB_COORD de coordonnées**/

const int NB_COORD= 200;

struct ensCoord
{
    coord tableCoord [NB_COORD];
    int nbC;
};

/** affiche un ensemble de coordonnées
 * @eC une variable de type ensCoord
 **/
void afficherEnsCoord ( ensCoord eC);

/** crée un ensemble de coordonnées ne contenant aucun élément
 *
 * @return un ensemble de coordonnées vide
 **/
 ensCoord creerEnsCoordVide();

/** ajoute une variable de type coordonnées dans un ensemble de coordonnées
 * @eC variable de type ensCoord
 * @c variable de type coord
 **/
 void ajouterCoord ( ensCoord& eC, coord c);

 /** trouve les voisins d'une coordonnée et les met dans un ensemble
  * @c variable de type coord
  *
  * @return l'ensemble des coordonnées des voisins de c
  **/
 ensCoord trouverVoisins( coord c);

 /** retourne une coordonnée au hasard parmi un ensemble de coordonnées
  * @eC variable de type ensCoord
  *
  * @return une variable de type coord
  **/
 coord choisirCoordAleatoirement( ensCoord eC);

 /** retourne le n-ième élément d'un ensemble de coordonnées
  *  @eC une variable de type coord;
  *  @n un entier
  *  @return une variable de type coord
  **/
coord lireElement(ensCoord eC, int n);


/** retourne le nombre d' elements d’un ensemble de coordonnees ec passee en paramètre
  * @eC une variable de type ensCoord
  * @return un entier
  */
int cardinal (ensCoord eC);

 #endif // COORD_HPP_INCLUDED



