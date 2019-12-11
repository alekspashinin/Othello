/*****************************************/
/*****************COUP.H******************/
/***************CREATED*BY****************/ 
/**SOUPILAS*DIMITRIOS*&*ALEKSEI*PASHININ**/
/*************PROJECT*OTHELLO*************/
/********************℗********************/
/*****************************************/

#ifndef _COUP_H_

#include "game.h"

/* Voir game.h pour les structures */


int exist_dev(coup *cp, game *g);
/* fonction bool, returne 1 si le x+1 du coup jouee est de couleur oposeeet en continuant sur cette ligne retrouve la couleur jouee.
   Prend en argument la structure coup et la structure game. */

int exist_der(coup *cp, game *g);
/* fonction bool, returne 1 si le x-1 du coup jouee est de couleur oposeeet en continuant sur cette ligne retrouve la couleur jouee.
   Prend en argument la structure coup et la structure game. */

int exist_bas(coup *cp, game *g);
/* fonction bool, returne 1 si le y+1 du coup jouee est de couleur oposeeet en continuant sur cette ligne retrouve la couleur jouee.
   Prend en argument la structure coup et la structure game. */

int exist_haut(coup *cp, game *g);
/* fonction bool, returne 1 si le y-1 du coup jouee est de couleur oposee et en continuant sur cette ligne retrouve la couleur jouee.
   Prend en argument la structure coup et la structure game. */

int exist_dev_haut(coup *cp,game *g);
/* fonction bool, returne 1 si le y-1 x+1 du coup jouee est de couleur oposee et en continuant sur cette ligne retrouve la couleur jouee.
   Prend en argument la structure coup et la structure game. */

int exist_dev_bas(coup *cp, game *g);
/* fonction bool, returne 1 si le y+1 x+1 du coup jouee est de couleur oposee et en continuant sur cette ligne retrouve la couleur jouee.
   Prend en argument la structure coup et la structure game. */

int exist_der_haut(coup *cp, game *g);
/* fonction bool, returne 1 si le y-1 x-1 du coup jouee est de couleur oposee et en continuant sur cette ligne retrouve la couleur jouee.
   Prend en argument la structure coup et la structure game. */

int exist_der_bas(coup *cp, game *g);
/* fonction bool, returne 1 si le y+1 x-1 du coup jouee est de couleur oposee et en continuant sur cette ligne retrouve la couleur jouee.
   Prend en argument la structure coup et la structure game. */

/* Toutes ses fonction modifie le tableau de la structure game si les deux regles sont valides */

int jouer(coup *cp, game *g);
/* fonction bool qui orchestre toutes le fonction precedantes lors d'un coup.
   Prend en argument la structure coup et game.
   Retourne 1 si un ou plus de ses cas sont valides 0 sinon 
   Donc sert aussi de coup legal
*/

void possibilite(game *g,int tablu[8][8],int *tablu_i,int *tablu_j);
/* fonction qui stock dans 2 tableaux pris en arguments (tablu_i / tablu_j) les coups possibles.
   Prend egalement en argument la stucture game et un tableau tablu qui sera remplis avec les possibilites. */

int existe_affiche_coup(game *g,MLV_Image *options);
/* fonction qui affiche (MLV) les coups possibles pour les joueurs.
   Prend en argument la structure game et image. */

int existe_coup(game *g);

/* fonction qui retourne 1 s'il existe un pour 0 sinon */

coup lire_coup();
/* fonction lisant un coup de la sourie sur l'interphase graphique. */





#endif