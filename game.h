/*****************************************/
/*****************GAME.H******************/
/***************CREATED*BY****************/ 
/**SOUPILAS*DIMITRIOS*&*ALEKSEI*PASHININ**/
/*************PROJECT*OTHELLO*************/
/********************℗********************/
/*****************************************/

#ifndef _GAME_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <MLV/MLV_all.h>

#define x MLV_get_desktop_width()
#define y MLV_get_desktop_height()

#define x_f x / 1.4970760234
#define y_f y / 1.3008130081


#define x_i x / 3.0260047281
#define y_i y / 4.23
#define taille_police 75
#define taille_place (x_f-x_i)/8
#define taille_place_y (y_f-y_i)/8

typedef struct {
    int score;
    char name[20];
}player;

typedef struct{
    int board[8][8];
    player p1;
    player p2;
    int tour;
    int debutant; //if == 1 player begins else if == 2 AI begins
}game;

typedef struct{
    int pos_x;
    int pos_y;
}coup;

#define VIDE 0
#define BLANC 1
#define NOIR 2
#define POSSIBLE 3

game init_game();
/* fonction d'initialisation de la structure game. Le tour est mis donne au NOIR. 
   Les cases du tableau sont initialises a 0 et les NOIR/BLANCS du debut sont positiones. 
   Les scores sont mis a 0. */

void affiche_board(game *g);
/* fontion d'affichage de la partie sur le terminal.
   Prend en argument la structure de type game.*/

void affiche_possibilite(int tablu[8][8]);
/* fonction d'affichage des possibilites du joueur sur e terminal. 
   Prend en argument le tableau a 2 dimensions representat le board. */

int adverse(game *g);
/* fonction qui retourne le joueur adverse. Prend en argument la structure game. */

void calc_affiche_score_MLV(game *g);
/* fonction qui calcule et affiche (MLV) le score des joueurs. 
   Prend en argument la structure game. */

void calc_score(game *g);

void affiche_score_fin_MLV(game *g, MLV_Image *board, MLV_Image *white, MLV_Image *black);
/* fonction qui affiche (MLV) a la fin de la partie "l'animation" de l'affichage des resultats. 
   Prend en argument la structure game et des images qui lui sont utiles. */

void affichage_MLV(game *g, MLV_Image *board, MLV_Image *white, MLV_Image *black);
/* fonction qui affiche (MLV) la partie courante.
   Prend en argument la structure game et de images qui lui sont utiles. */

game copy_game(game* g);
/* fonction de clonage de la structure game.
   Prend en argument un game et retourne son clone/copie */

int est_fini(game *g);
/* fonction bool retourne 1 si la partie est finie 0 sinon */

#endif