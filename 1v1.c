/*****************************************/
/******************1V1.C******************/
/***************CREATED*BY****************/ 
/**SOUPILAS*DIMITRIOS*&*ALEKSEI*PASHININ**/
/*************PROJECT*OTHELLO*************/
/********************℗********************/
/*****************************************/

#include "1v1.h"


game mode_1v1(MLV_Image *board, MLV_Image *black, MLV_Image *white, MLV_Image *options){
    
    game g=init_game();
    //get_names(&g);
    affichage_MLV(&g,board,white,black);
    coup cp;
    printf("%d commence\n",g.tour);
    while(!est_fini(&g) && existe_affiche_coup(&g,options)){
        //lire le coup   
        cp=lire_coup();
        //jouer le coup si le coup est valide changeemnt de tour
        jouer(&cp,&g);
        //affiche le board MLV      
        affichage_MLV(&g,board,white,black);
        
        affiche_board(&g);
    }
    return g;
}