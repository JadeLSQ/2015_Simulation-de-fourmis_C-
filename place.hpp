#ifndef PLACE_HPP_INCLUDED
#define PLACE_HPP_INCLUDED
#include "fourmis.hpp"
#include <map>

const int nb_SUCRE=5;
/** Le type abstrait place est spécifié de la manière suivante:**/

typedef struct
{
    coord c;
    bool Contientfourmi;
    bool ContientSucre;
    bool ContientNid;
    int PheroSucre; // Entre 0 et 255, dimunue de 5 a chaque iteration de la simulation
    double PheroNid;// Entre 0 et 1
    int nbSucre;
} place;

/**Constructeur**/
/** crée une place ne contenant ni de fourmi, ni de sucre, ni d'élément de nid
 * @c une variable de type coord
 * @p une variable de type place
 **/
 place creerPlaceVide (coord c, place &p);

/**Accès**/

/** retourne l'intensité en phéromone de nid sur la place
 * @p une variable de type place
 *
 * @return un réel
 **/
 double lirePheroNid (place p);

/** renvoie vrai si la place ne contient ni du sucre ni une fourmi ni un element de nid
 *  @p place;
 * @return un booleen;
 */
 bool vide (place p);

/** retourne l'intensité en phéromone de sucre sur la place
 * @p une variable de type place
 *
 * @return un entier
 **/
 int lirePheroSucre (place p);

 /**Prédicats sur une place**/

 /** retourne vrai si la place contient une fourmi
  * @p une variable de type place
  *
  * @return booléen
  **/
  bool contientFourmi (place p);

  /** retourne vrai si la place contient du sucre
   * @p une variable de type place
   *
   * @return booléen
   */
 bool contientSucre(place p);

 /** retourne vrai si la place contient un élément de nid
  * @p une variable de type place
  *
  * @return booléen
  **/
  bool contientNid(place p);

  /** retourne vrai si la place se trouve sur une piste vers du sucre
   * @p une variable de type place
   *
   * @return booléen
   **/
  bool surUnePiste(place p);

  /**Modifications sur une place**/

  /** pose du sucre sur la place
   * @p une variable de type place
   **/
   void poserSucre (place &p);

   /** pose un élément de nid sur la place
    * @p une variable de type place
    **/
   void poserNid (place &p);

   /** pose une fourmi sur la place
    * @p une variable de type place
    **/
   void poserFourmi (place &p);

   /** pose sur la place une phéromone de nid d'intensité fournie en 2è param
    * @p une variable de type place
    * @In réel
    **/
    void poserPheroNid (place &p, float In);

  /** pose une phéromone de sucre d'intensité maximale sur la place
   * @p place
   **/
   void poserPheroSucre(place &p);

   /** diminue l'intensité en phéromone de sucre sur la place
    * @p place
    **/
    void diminuerPheroSucre (place &p);

    /** cherche le nid le plus proche en comparant l'intensite de pheromone de nid de deux places données
      * @p1 place
      * @p2 place
      * @return booleen
      **/
    bool plusProcheNid (place p1, place p2);

/** cherche le nid le plus loin en comparant l'intensite de pheromone de nid de deux places données
      * @p1 place
      * @p2 place
      * @return booleen
      **/
    bool plusLoinNid (place p1, place p2);

    /**Modification sur deux places**/

    /** déplace la fourmi qui est sur une place vers une autre
     * @f une variable de type fourmi
     * @p1 une variable de type place
     * @p2 une variable de type place
     **/
     void deplacerFourmi (fourmi &f, place &p1, place &p2);


     #endif // PLACE_HPP_INCLUDED




