/*****************************************/
/****************LEVEL1.C*****************/
/***************CREATED*BY****************/ 
/**SOUPILAS*DIMITRIOS*&*ALEKSEI*PASHININ**/
/*************PROJECT*OTHELLO*************/
/********************℗********************/
/*****************************************/

#include "level1.h"

void position_gagnate(game *g,int *tablu_i,int *tablu_j){
    int i,i_choi,j_choi;
    game g_temp;
    coup cp;
    int score;
    if(g->tour==2){
        score=g->p1.score;
    }
    else{
        score=g->p2.score;
    }
    //printf("\n le score est %d\n",score);
    int nb_possibl=tablu_i[0];
    //printf("\n le nb de possibl es %d",nb_possibl);
    for(i=1;i<nb_possibl;i++){
        g_temp=copy_game(g);
        cp.pos_x=tablu_i[i];
        cp.pos_y=tablu_j[i];
        //printf("\n\n La %d possibl est %d et %d\n",i,cp.pos_x,cp.pos_y);
        jouer(&cp,&g_temp);
        calc_affiche_score_MLV(&g_temp);
        //printf("\n le nv score est %d\n",g_temp.p1.score);
        if(g->tour==2){
            //!may have to copy score of players
            if(score < g_temp.p1.score){
                score=g_temp.p1.score;
                i_choi=cp.pos_x;
                j_choi=cp.pos_y;
                
            }
        }
        else{
            if(score < g_temp.p2.score){
                score=g_temp.p2.score;
                i_choi=cp.pos_x;
                j_choi=cp.pos_y;
            }
        }
        
    }
    cp.pos_x=i_choi;
    cp.pos_y=j_choi;

    free(tablu_i);
    free(tablu_j);
   
    jouer(&cp,g);

    

}

void ia_next_step_max(game *g,int taille_pos){
    int tablu[8][8];
    int *tablu_i=NULL;
    int *tablu_j=NULL;
    
    
    tablu_i=(int*)malloc((taille_pos+1) * sizeof(int));
    tablu_j=(int*)malloc((taille_pos+1) * sizeof(int));

    MLV_wait_seconds(2);
    possibilite(g,tablu,tablu_i,tablu_j);
  
    position_gagnate(g,tablu_i,tablu_j);
    affiche_possibilite(tablu);
   
    g->debutant=1;
   
}

   
game mode_1(MLV_Image *board, MLV_Image *black, MLV_Image *white, MLV_Image *options){
    // init da game & names
      
    game g=init_game();
    g.debutant=2; //if == 1 player begins else if == 2 AI begins
    //get_names(&g);
    affichage_MLV(&g,board,white,black);
    coup cp;
    int taille_pos;
    
    while(!est_fini(&g)){
        taille_pos=existe_affiche_coup(&g,options);
        ///printf("IL Y A %d POSS\n",taille_pos);
        if(taille_pos==0){
            return g;
        }
        
        if(g.debutant==1){
            cp=lire_coup();
       
            if(jouer(&cp,&g)==1){
                g.debutant=2;
            }
        }
        else{
            ia_next_step_max(&g,taille_pos);
            
        }
        affichage_MLV(&g,board,white,black);
        //printf("%d vien de jouer\n\n",debutan);
        affiche_board(&g);
    }
    return g;
}
