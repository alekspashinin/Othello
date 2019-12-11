#include "game.h"

game init_game(){
    int i,j;
    game g;
	
    // tour si debut =1 alors noir sinon blanc

    g.tour=NOIR;

    // initialisation du tableau a 0.
    for(i=0;i<8;i++){ 
        for(j=0;j<8;j++){
            g.board[i][j]=VIDE;
        }
    }
	
    // position de depart.

    g.board[3][3]=BLANC;                
    g.board[4][3]=NOIR;
    g.board[3][4]=NOIR;
    g.board[4][4]=BLANC;

    

    // init score joueur1.
    g.p1.score=0;

    // init score joueur2. 
    g.p2.score=0;

    return g;
}

void affiche_board(game *g){
    int i,j;
    printf("   1 2 3 4 5 6 7 8\n");
    for(i=0;i<8;i++){
        printf("%d  ",i+1);
        for(j=0;j<8;j++){

            if(g->board[j][i]==BLANC){
                fprintf(stdout,"B ");
            }
            if(g->board[j][i]==NOIR){
                fprintf(stdout,"N ");
            }
            if(g->board[j][i]==VIDE){
                fprintf(stdout,". ");
            }
        }
        fprintf(stdout,"\n");
    }
    printf("\n");
}

void affiche_possibilite(int tablu[8][8]){
    int i,j;
    printf("   1 2 3 4 5 6 7 8\n");
    for(i=0;i<8;i++){
        printf("%d  ",i+1);
        for(j=0;j<8;j++){

            if(tablu[j][i]==POSSIBLE){
                fprintf(stdout,"P ");
            }
            if(tablu[j][i]==VIDE){
                fprintf(stdout,". ");
            }
        }
        fprintf(stdout,"\n");
    }
    printf("\n");
}
    

// retour de l'adversaire.
int adverse(game *g){
    // si le joueur est 1.
    if(g->tour==1){
        // son adversaire est 2.
        return 2;
    }
    else
        // sinon son adveraire est 1.
        return 1;
}



void calc_affiche_score_MLV(game *g){
    int i,j,j1=0,j2=0;	
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            //si noir on ajoute un point au premier joueur
            if(g->board[i][j]==NOIR){
                j1++;
            }
            //si blanc on ajoute un point au deuxieme joueur
            if(g->board[i][j]==BLANC){
                j2++;
            }
        }
    }
    //affectation des score a la structure
    g->p1.score=j1;
    g->p2.score=j2;
	
    //affichage des noms et scores
    //MLV_draw_text(0,x_i,"%s :",MLV_COLOR_RED,g->p1.name);
    MLV_draw_text(x/8.5333333,y/3.3333333,"%d",MLV_COLOR_RED,g->p1.score);

    //MLV_draw_text(0,4*x_i,"%s :",MLV_COLOR_RED,g->p2.name);
    MLV_draw_text(x/1.16363636,y/3.3333333,"%d",MLV_COLOR_RED,g->p2.score);

    //affichage du joueur qui doit jouer
    /*
      if(g->tour==2){
      MLV_draw_text(x/4,y-(x_i/2)," C'est le tour de %s (NOIR) !",MLV_COLOR_RED,g->p1.name);
      }
      else{
      MLV_draw_text(x/4,y-(x_i/2)," C'est le tour de %s (BLANC) !",MLV_COLOR_RED,g->p2.name);
      }
    */
    MLV_actualise_window();

}
void calc_score(game *g){
    int i,j,j1=0,j2=0;	
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            //si noir on ajoute un point au premier joueur
            if(g->board[i][j]==NOIR){
                j1++;
            }
            //si blanc on ajoute un point au deuxieme joueur
            if(g->board[i][j]==BLANC){
                j2++;
            }
        }
    }
    //affectation des score a la structure
    g->p1.score=j1;
    g->p2.score=j2;
}

void affiche_score_fin_MLV(game *g, MLV_Image *board, MLV_Image *white, MLV_Image *black){
    int i,j;  
    int score1=g->p1.score;
    int score2=g->p2.score;
    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_draw_image(board,0,0);
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            MLV_wait_seconds(0.8);
            MLV_actualise_window();
            if(score1>0){
                
                MLV_draw_image(black,(taille_place*i)+x_i,(taille_place_y*j)+y_i);
                score1--;
            }
            else{
                if(score2>0){
                    MLV_draw_image(white,(taille_place*i)+x_i,(taille_place_y*j)+y_i);
                    score2--;
                }
            }
        }
    }
    MLV_actualise_window();
    calc_affiche_score_MLV(g);
    
    MLV_wait_seconds(5);
}


void affichage_MLV(game *g, MLV_Image *board, MLV_Image *white, MLV_Image *black){

    int i,j;
    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_draw_image(board,0,0);
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(g->board[i][j]==BLANC){
                MLV_draw_image(white,(taille_place*i)+x_i,(taille_place_y*j)+y_i);
				
            }
            if(g->board[i][j]==NOIR){
                MLV_draw_image(black,(taille_place*i)+x_i,(taille_place_y*j)+y_i);
            }
        }
    }
    calc_affiche_score_MLV(g);
    MLV_actualise_window();
	
}

game copy_game(game* g){
    int i,j;
    game g_temp;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            
            g_temp.board[i][j]=g->board[i][j];
        }
    }
    g_temp.tour=g->tour;
    //("C est le tour de %d", g_temp.tour);
    g_temp.p1=g->p1;
    g_temp.p2=g->p2;
    g_temp.tour=g->tour;
    g_temp.debutant=g->debutant;

    return g_temp;
}

int est_fini(game *g){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(g->board[i][j]==VIDE){
                return 0;
            }
        }
    }
    return 1;
}


