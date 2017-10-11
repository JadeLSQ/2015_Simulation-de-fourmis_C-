#ifndef PLACE_HPP_INCLUDED
#define PLACE_HPP_INCLUDED
#include "fourmis.hpp"
#include <map>

const int nb_SUCRE=5;
/** Le type abstrait place est sp�cifi� de la mani�re suivante:**/

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
/** cr�e une place ne contenant ni de fourmi, ni de sucre, ni d'�l�ment de nid
 * @c une variable de type coord
 * @p une variable de type place
 **/
 place creerPlaceVide (coord c, place &p);

/**Acc�s**/

/** retourne l'intensit� en ph�romone de nid sur la place
 * @p une variable de type place
 *
 * @return un r�el
 **/
 double lirePheroNid (place p);

/** renvoie vrai si la place ne contient ni du sucre ni une fourmi ni un element de nid
 *  @p place;
 * @return un booleen;
 */
 bool vide (place p);

/** retourne l'intensit� en ph�romone de sucre sur la place
 * @p une variable de type place
 *
 * @return un entier
 **/
 int lirePheroSucre (place p);

 /**Pr�dicats sur une place**/

 /** retourne vrai si la place contient une fourmi
  * @p une variable de type place
  *
  * @return bool�en
  **/
  bool contientFourmi (place p);

  /** retourne vrai si la place contient du sucre
   * @p une variable de type place
   *
   * @return bool�en
   */
 bool contientSucre(place p);

 /** retourne vrai si la place contient un �l�ment de nid
  * @p une variable de type place
  *
  * @return bool�en
  **/
  bool contientNid(place p);

  /** retourne vrai si la place se trouve sur une piste vers du sucre
   * @p une variable de type place
   *
   * @return bool�en
   **/
  bool surUnePiste(place p);

  /**Modifications sur une place**/

  /** pose du sucre sur la place
   * @p une variable de type place
   **/
   void poserSucre (place &p);

   /** pose un �l�ment de nid sur la place
    * @p une variable de type place
    **/
   void poserNid (place &p);

   /** pose une fourmi sur la place
    * @p une variable de type place
    **/
   void poserFourmi (place &p);

   /** pose sur la place une ph�romone de nid d'intensit� fournie en 2� param
    * @p une variable de type place
    * @In r�el
    **/
    void poserPheroNid (place &p, float In);

  /** pose une ph�romone de sucre d'intensit� maximale sur la place
   * @p place
   **/
   void poserPheroSucre(place &p);

   /** diminue l'intensit� en ph�romone de sucre sur la place
    * @p place
    **/
    void diminuerPheroSucre (place &p);

    /** cherche le nid le plus proche en comparant l'intensite de pheromone de nid de deux places donn�es
      * @p1 place
      * @p2 place
      * @return booleen
      **/
    bool plusProcheNid (place p1, place p2);

/** cherche le nid le plus loin en comparant l'intensite de pheromone de nid de deux places donn�es
      * @p1 place
      * @p2 place
      * @return booleen
      **/
    bool plusLoinNid (place p1, place p2);

    /**Modification sur deux places**/

    /** d�place la fourmi qui est sur une place vers une autre
     * @f une variable de type fourmi
     * @p1 une variable de type place
     * @p2 une variable de type place
     **/
     void deplacerFourmi (fourmi &f, place &p1, place &p2);


     #endif // PLACE_HPP_INCLUDED




