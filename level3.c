/*****************************************/
/****************LEVEL3.C*****************/
/***************CREATED*BY****************/ 
/**SOUPILAS*DIMITRIOS*&*ALEKSEI*PASHININ**/
/*************PROJECT*OTHELLO*************/
/********************℗********************/
/*****************************************/

#include"level3.h"

void ia_3(game *g,int p){

    bestplay bp=init_bp(g);
    
    coup cp;   
    cp.pos_x=1;
    cp.pos_y=1;

    int count=0;
    int *tablu_i=NULL;
    int *tablu_j=NULL;
    int tab[8][8];
    tablu_i=calloc(bp.nb_choises+1,sizeof(int));
    tablu_j=calloc(bp.nb_choises+1,sizeof(int));
    
    possibilite(g, tab, tablu_i, tablu_j);

    arbre a=creer_arbre_avec_prof3(g,&cp,0,p,&bp,&count);
    free_arbre(a);
 
    int best=0;
    int best_pos=1;
    for(int i=1;i<bp.nb_choises+1;i++){
        if(best<bp.best[i]){
            best=bp.best[i];
            best_pos=i;
        }
    }
    cp.pos_x=tablu_i[best_pos];
    cp.pos_y=tablu_j[best_pos];

    jouer(&cp,g);
    g->debutant=1;
    //printf("Best POS! nb = %d. Avec coup x=%d y=%d\n",best_pos,tablu_i[best_pos],tablu_j[best_pos]);

    

    free(tablu_i);
    free(tablu_j);
    free(bp.best);
    tablu_i=NULL;
    tablu_j=NULL;
    bp.best=NULL;
    a=NULL;
   
    
}

game mode_3(MLV_Image *board, MLV_Image *black, MLV_Image *white, MLV_Image *options,int prof){
    game g=init_game();
    g.debutant=2; //if == 1 player begins else if == 2 AI begins
    //get_names(&g);
    affichage_MLV(&g,board,white,black);
    coup cp;
    int taille_pos;
    
    while(!est_fini(&g)){
        taille_pos=existe_affiche_coup(&g,options);
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
            ia_3(&g,prof);
            
        }
        affichage_MLV(&g,board,white,black);
        //printf("%d vien de jouer\n\n",debutan);
        affiche_board(&g);
        eval_board(&g);
    }
    return g;
}
