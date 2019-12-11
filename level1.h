/*****************************************/
/****************LEVEL1.H*****************/
/***************CREATED*BY****************/ 
/**SOUPILAS*DIMITRIOS*&*ALEKSEI*PASHININ**/
/*************PROJECT*OTHELLO*************/
/********************℗********************/
/*****************************************/

#ifndef _LEVEL1_H_

#include "1v1.h"

void position_gagnate(game *g,int *tablu_i,int *tablu_j);
/* fonction calculant quel est le prochain coup qui lui raportera le plus de points.
   Prend en argument la structure game et deux tableaux (voir game.h possibilite) */

void ia_next_step_max(game *g,int taille_pos);
/* fonction qui orchestre l'IA de niveau 0.
Prend en argument la structure game */

game mode_1(MLV_Image *board, MLV_Image *black, MLV_Image *white, MLV_Image *options);
/* fonction qui met en euvre le "gameplay de l'IA de niveau 0.
   prend en argument que les images utiles */


#endif


