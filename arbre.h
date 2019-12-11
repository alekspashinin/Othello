/*****************************************/
/*****************ARBRE.H*****************/
/***************CREATED*BY****************/ 
/**SOUPILAS*DIMITRIOS*&*ALEKSEI*PASHININ**/
/*************PROJECT*OTHELLO*************/
/********************℗********************/
/*****************************************/

#ifndef _ARBRE_H_

#include"level1.h"

typedef struct noeud{
    game g;
    coup cp;
    int nb_fils;
    struct noeud **fils;
}noeud;

typedef struct {
    int nb_choises;
    int *best;
    int *best_opt;
}bestplay;

typedef noeud * arbre;

arbre arbre_vide();
/* retourne NULL */

bestplay init_bp(game *g);
/* fonction qui initialise le bestplay */

int evaluation_plateu ( game * g);

void eval_board(game *g);

int est_vide(arbre a);
/* fonction bool retourne 1 si l'arbre == NULL */

arbre creer_arbre(game *g,coup *cp);
/* fonction qui retourne un structure arbre avec les "game" et "coup" pris en argument. 
   Tout le reste est set a NULL */

arbre inserer_fils_n(arbre a, arbre fils, int num_fils);
/* fonction qui insere un arbre "fils" dans le tableau fils a la position "num_fils" */

arbre creer_arbre_avec_prof3(game *g, coup *cp, int prof_act, int prof_lim, bestplay *bp, int *count);
/* fonction qui cree l arbre de prof="prof_lim" = nombre pair si on veut qu elle fasse corecement,
 son travail sinon elle calcule le meilleur coup pour faire gagner l'adversaire.
 Prie de renomer en creer_arbre_contre_enfants si l'on insiste a l'utiliser avec un nb impaire. */  

void free_arbre(arbre a);
/* libere l'arbre */



#endif



