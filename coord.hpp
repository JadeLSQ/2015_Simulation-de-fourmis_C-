#ifndef COORD_HPP_INCLUDED
#define COORD_HPP_INCLUDED
#include <map>


/**Le type abstrait coord repr�sentant les cordonn�es d'une fourmi est sp�cifi� de la mani�re suivante:**/

typedef struct
{
    int x;
    int y;
} coord;


/** cr�e les coordonn�es
 * @lig coordon�e sur l'axe des abscisses
 * @col coordon�e sur l'axe des ordonn�es
 *
 * @return variable type coord initialis� � (lig;col)
 **/
coord creerCoord(int lig, int col);

/** affiche les coordonn�es sous la forme (lig;col)
 * @c variable de type coord
 **/
void afficherCoord (coord c);

/** compare si deux coordonn�es sont �gales ou non
 * @p1 variable de type coord
 * @p2 variable de type coord
 *
 * @return bool�en
 **/
bool coordonneesEgales( coord p1, coord p2);

/** Le type abstrait ensCoord repr�sentant un ensemble d'au maximum NB_COORD de coordonn�es**/

const int NB_COORD= 200;

struct ensCoord
{
    coord tableCoord [NB_COORD];
    int nbC;
};

/** affiche un ensemble de coordonn�es
 * @eC une variable de type ensCoord
 **/
void afficherEnsCoord ( ensCoord eC);

/** cr�e un ensemble de coordonn�es ne contenant aucun �l�ment
 *
 * @return un ensemble de coordonn�es vide
 **/
 ensCoord creerEnsCoordVide();

/** ajoute une variable de type coordonn�es dans un ensemble de coordonn�es
 * @eC variable de type ensCoord
 * @c variable de type coord
 **/
 void ajouterCoord ( ensCoord& eC, coord c);

 /** trouve les voisins d'une coordonn�e et les met dans un ensemble
  * @c variable de type coord
  *
  * @return l'ensemble des coordonn�es des voisins de c
  **/
 ensCoord trouverVoisins( coord c);

 /** retourne une coordonn�e au hasard parmi un ensemble de coordonn�es
  * @eC variable de type ensCoord
  *
  * @return une variable de type coord
  **/
 coord choisirCoordAleatoirement( ensCoord eC);

 /** retourne le n-i�me �l�ment d'un ensemble de coordonn�es
  *  @eC une variable de type coord;
  *  @n un entier
  *  @return une variable de type coord
  **/
coord lireElement(ensCoord eC, int n);


/** retourne le nombre d' elements d�un ensemble de coordonnees ec passee en param�tre
  * @eC une variable de type ensCoord
  * @return un entier
  */
int cardinal (ensCoord eC);

 #endif // COORD_HPP_INCLUDED



