/*****************************************/
/*****************ARBRE.C*****************/
/***************CREATED*BY****************/ 
/**SOUPILAS*DIMITRIOS*&*ALEKSEI*PASHININ**/
/*************PROJECT*OTHELLO*************/
/********************℗********************/
/*****************************************/

#include "arbre.h"

arbre arbre_vide(){
    return NULL;
}

bestplay init_bp(game *g){
    bestplay bp;
    int nb_pos=existe_coup(g);
    bp.nb_choises=nb_pos;
    bp.best=(int*)calloc(nb_pos+1,sizeof(int));
    bp.best_opt=(int*)calloc(nb_pos+1,sizeof(int));
    for(int i=0;i<nb_pos+1;i++){   //or nb_pos+1
        bp.best_opt[i]=0;
    }
    
    return bp;
}

int evaluation_plateu(game * g){     //evaluation_plateu prend game g comme parametre, 
    int i,j;                                                      //elle regarde nombre des blancs et noirs, le qualite
    //de chaque cause, et elle calcule
    int res_p1, res_p2;                              //la difference de resultas te p1 et p2
    int k=0;
    int qualite[64]={
        
        120, -20, 20, 5, 5, 20, -20, 120,
        -20, -40, -5, -5, -5, -5, -40, -20,
        20, -5, 15, 3, 3, 15, -5, 20,
        5, -5, 3, 3, 3, 3, -5, 5, 
        5, -5, 3, 3, 3, 3, -5, 5, 
        20, -5, 15, 3, 3, 15, -5, 20,
        -20, -40, -5, -5, -5, -5,-40,-20,
        120, -20, 20, 5, 5, 20, -20, 120
        
    };
    
    res_p1=0;
    res_p2=0;
    if(g->tour==1){
        for (i=0; i<=7; i++) {
            for (j=0; j<=7; j++) {
                if(g->board[i][j]==BLANC){
                    res_p1=res_p1+qualite[k];
                }
                if(g->board[i][j]==NOIR){
                    res_p2=res_p2+qualite[k];
                }
                k++;
            }
            
        }
    }
    else{
        for (i=0; i<=7; i++) {
            for (j=0; j<=7; j++) {
                if(g->board[i][j]==NOIR){
                    res_p1=res_p1+qualite[k];
                }
                if(g->board[i][j]==BLANC){
                    res_p2=res_p2+qualite[k];
                }
                k++;
            }
            
        }
    }
    return (res_p1 - res_p2);
}

void eval_board(game *g){
    int i,j;                                                      //elle regarde nombre des blancs et noirs, le qualite
    //de chaque cause, et elle calcule
    int res_p1, res_p2;                              //la difference de resultas te p1 et p2
    int k=0;
    int qualite[64]={
        
        120, -20, 20, 5, 5, 20, -20, 120,
        -20, -40, -5, -5, -5, -5, -40, -20,
        20, -5, 15, 3, 3, 15, -5, 20,
        5, -5, 3, 3, 3, 3, -5, 5, 
        5, -5, 3, 3, 3, 3, -5, 5, 
        20, -5, 15, 3, 3, 15, -5, 20,
        -20, -40, -5, -5, -5, -5,-40,-20,
        120, -20, 20, 5, 5, 20, -20, 120
        
    };
    
    res_p1=0;
    res_p2=0;
    if(g->tour==1){
        for (i=0; i<=7; i++) {
            for (j=0; j<=7; j++) {
                if(g->board[i][j]==BLANC){
                    res_p1=res_p1+qualite[k];
                }
                if(g->board[i][j]==NOIR){
                    res_p2=res_p2+qualite[k];
                }
                k++;
            }
            
        }
    }
    MLV_draw_text(x/8.5333333,(y/3.3333333)+50,"%d",MLV_COLOR_GREEN,res_p2);
    MLV_draw_text(x/1.16363636,(y/3.3333333)+50,"%d",MLV_COLOR_GREEN,res_p1);
    MLV_actualise_window();

}

int est_vide(arbre a){
    return (a==arbre_vide());
}

arbre creer_arbre_vide(){
    arbre a=arbre_vide();
  
    return a;
}

arbre creer_arbre(game *g,coup *cp){
    arbre a=NULL;
    a=calloc(1,sizeof(noeud));
    if(a==NULL){
        printf("ERROR ALLOC ARBRE");
    }
    a->g=*g;
    a->cp=*cp;
    //affiche_board(a->g);
    return a;
}

arbre inserer_fils_n(arbre a, arbre fils, int num_fils){
    if(arbre_vide(a)){
        printf("Vous essayer de rajouter un fils a un arbre vide");
        return arbre_vide();
    }
    else {
        a->fils[num_fils]=fils;
        //affiche_board(a->fils[num_fils]->g);
        return a;
    }
}



arbre creer_arbre_avec_prof3(game *g, coup *cp,int prof_act, int prof_lim, bestplay *bp, int *count){
    arbre a=NULL;
    int i=0;
    int tablu[8][8];
    if(prof_act==1){
        *count +=1;
        //printf("!!!!!connt:%d\n",*count);
    }
    if(prof_act>prof_lim){
        free(a);
        return NULL;
    }
    int *tablu_i=NULL;
    int *tablu_j=NULL;
    int taille_pos=existe_coup(g);
    a=creer_arbre(g, cp);
    a->nb_fils=taille_pos;
    a->fils=NULL;
    a->fils=(arbre*)calloc(taille_pos,sizeof(noeud));
    if(a->fils==NULL){
        printf("ERREUR ALLOC FILS\n");
    }
    tablu_i=calloc(taille_pos+1,sizeof(int));
    tablu_j=calloc(taille_pos+1,sizeof(int));
    possibilite(g,tablu,tablu_i,tablu_j);
    coup cp_temp;
    game g_temp;
    if(prof_act==prof_lim){
        /*calc_score(g);
          if(g->tour==1){
          if(g->p1.score > g->p2.score){
          bp->best[*count]+=1;  
          }
          }
          else{      
          if(g->p1.score < g->p2.score){
          bp->best[*count]+=1;                    
          }
          }*/
        int r=evaluation_plateu(g);
        bp->best[*count]+=r;
        bp->best_opt[*count]+=1;
      
        //printf("!!!!!!!!!%d\n",r);
    }
    prof_act+=1;
    while(i<taille_pos && prof_act<=prof_lim){
        g_temp=copy_game(g);
        cp_temp.pos_x=tablu_i[i+1];
        cp_temp.pos_y=tablu_j[i+1];
        jouer(&cp_temp,&g_temp);             
        a=inserer_fils_n(a, creer_arbre_avec_prof3(&g_temp,&cp_temp, prof_act, prof_lim,bp,count), i);
        i++;
    }
    free(tablu_i);
    free(tablu_j);
    tablu_i=NULL;
    tablu_j=NULL;
    return a;
}

void free_arbre(arbre a){
    int i;
    if(!a){
        return;
        //printf("end of branch\n");
    }
  
    for(i=0;i<a->nb_fils;i++){
        free_arbre(a->fils[i]);
        //printf("freee\n");
        if(i==a->nb_fils-1){
            free(a->fils);
            //printf("Free son block\n");
        }
        
    }
    free(a);
    a=NULL;
}
