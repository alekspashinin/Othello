/*****************************************/
/*****************COUP.C******************/
/***************CREATED*BY****************/ 
/**SOUPILAS*DIMITRIOS*&*ALEKSEI*PASHININ**/
/*************PROJECT*OTHELLO*************/
/********************℗********************/
/*****************************************/


#include "coup.h"



int exist_dev(coup *cp, game *g){
    //printf("case : 1\n");
    int i,j,k;
    j=cp->pos_y;
    for(i=cp->pos_x+1;i<8;i++){
        if(g->board[i][j]==VIDE){
            return 0;
        }
        if(g->board[i][j]==g->tour){
            for(k=cp->pos_x;k<i;k++){
                g->board[k][j]=g->tour;
            }
            return 1;
        }
    }
    return 0;
}

int exist_der(coup *cp, game *g){
    //printf("case: 2\n");
    int i,j,k;
    j=cp->pos_y;
    for(i=cp->pos_x-1;i>=0;i--){
        if(g->board[i][j]==VIDE){
            return 0;
        }
        if(g->board[i][j]==g->tour){
            for(k=cp->pos_x;k>i;k--){
                g->board[k][j]=g->tour;
            }
            return 1;
        }
    }
    return 0;
}

int exist_bas(coup *cp, game *g){
    //printf("case : 3\n");
    int i,j,k;
    i=cp->pos_x;
    for(j=cp->pos_y+1;j<8;j++){
        if(g->board[i][j]==VIDE){
            return 0;
        }
        if(g->board[i][j]==g->tour){
            for(k=cp->pos_y;k<=j;k++){
                g->board[i][k]=g->tour;
                //printf("g->board=%d g->tour=%d i=%d j=%d\n",g->board[i][k],g->tour,i,j);
            }
            return 1;
        }
    }
    return 0;	
}

int exist_haut(coup *cp, game *g){
    //printf("case : 4\n");
    int i,j,k;
    i=cp->pos_x;
    for(j=cp->pos_y-1;j>=0;j--){
        if(g->board[i][j]==VIDE){
            return 0;
        }
        if(g->board[i][j]==g->tour){
            for(k=cp->pos_y;k>=j;k--){
                g->board[i][k]=g->tour;
            }
            return 1;
        }
    }
    return 0;
}

int exist_dev_haut(coup *cp,game *g){
    //printf("case : 5\n");
    int i,j,n=0;
    i=cp->pos_x+1;
    j=cp->pos_y-1;
    if(i==7 || j==0){
        return 0;
    }
    while(i<8 && g->board[i][j]!=VIDE /*recent change*/&& j>=0 ){
        if(g->board[i][j]==g->tour){
            n=i;
            i=cp->pos_x;
            j=cp->pos_y;
            while(i<n && j>0){
                g->board[i][j]=g->tour;
                i++;
                j--;
            }
            return 1;
        }
        i++;
        j--;
    }
    return 0;
}


int exist_dev_bas(coup *cp, game *g){
    //printf("case : 6\n");
    int i,j,n=0;
    i=cp->pos_x+1;
    j=cp->pos_y+1;
    if(i==7 || j==7){
        return 0;
    }
    while(i<8 && g->board[i][j]!=VIDE && j<8){
        if(g->board[i][j]==g->tour){
            n=i;
            i=cp->pos_x;
            j=cp->pos_y;
            while(n>i && j<8){
                g->board[i][j]=g->tour;
                i++;
                j++;
            }
            return 1;
        }
        i++;
        j++;
    }
    return 0;

}

int exist_der_haut(coup *cp, game *g){
    // printf("case : 7\n");
    int i,j,n=0;
    i=cp->pos_x-1;
    j=cp->pos_y-1;
    if(i==0 || j==0){
        return 0;
    }
    while(i>=0 && g->board[i][j]!=VIDE && j>=0){
        if(g->board[i][j]==g->tour){
            n=i;
            i=cp->pos_x;
            j=cp->pos_y;
            while(n<i && j>0){
                g->board[i][j]=g->tour;
                i--;
                j--;
            }
            return 1;
        }
        i--;
        j--;	
    }
    return 0;
}

int exist_der_bas(coup *cp, game *g){
    //printf("case : 8\n");
	
    int i,j,n=0;
    i=cp->pos_x-1;
    j=cp->pos_y+1;
    if(i==0 || j==7){
        return 0;
    }

    while(j<8 && g->board[i][j]!=VIDE && i>=0){
        if(g->board[i][j]==g->tour){
            n=i;
            i=cp->pos_x;
            j=cp->pos_y;
            while(i>n && j<8){
                g->board[i][j]=g->tour;
                i--;
                j++;
            }
            return 1;
        }
        i--;
        j++;
    }
    return 0;
}




int jouer(coup *cp, game *g){
    int res=0;
    int temp=0;

    
    // si le coup est possible (donc ==VIDE).
    //printf("C est le tour de %d\n",g->tour);

    if(g->board[cp->pos_x][cp->pos_y]==VIDE){

        // check si le coup est adjacent a un coup adverse
        if(adverse(g)==g->board[cp->pos_x +1][cp->pos_y]){
            temp=res;
            res=exist_dev(cp,g);
            if(temp==1){
                res=temp;
            }
            //affiche_board(g);
        }

        if(adverse(g)==g->board[cp->pos_x -1][cp->pos_y]){
            temp=res;
            res=exist_der(cp,g);

            if(temp==1){
                res=temp;
            }
            //affiche_board(g);
        }
		
        if(adverse(g)==g->board[cp->pos_x][cp->pos_y +1]){
            temp=res;
			
            res=exist_bas(cp,g);
            if(temp==1){
                res=temp;
            }
            //affiche_board(g);
        }
		
        if(adverse(g)==g->board[cp->pos_x][cp->pos_y -1]){
            temp=res;
            res=exist_haut(cp,g);
            if(temp==1){
                res=temp;
            }
            //affiche_board(g);
        }

        if(adverse(g)==g->board[cp->pos_x +1][cp->pos_y +1]){
            temp=res;
            res=exist_dev_bas(cp,g);
            if(temp==1){
                res=temp;
            }
            //affiche_board(g);
        }

        if(adverse(g)==g->board[cp->pos_x -1][cp->pos_y -1]){
            temp=res;
            res=exist_der_haut(cp,g);
            if(temp==1){
                res=temp;
            }
            //affiche_board(g);
        }

        if(adverse(g)==g->board[cp->pos_x -1][cp->pos_y +1]){
            temp=res;
            res=exist_der_bas(cp,g);
            if(temp==1){
                res=temp;
            }
            //affiche_board(g);
        }
		
        if(adverse(g)==g->board[cp->pos_x +1][cp->pos_y -1]){
            temp=res;
            res=exist_dev_haut(cp,g);
            if(temp==1){
                res=temp;
            }
            //affiche_board(g);
        }
    }
    if(res==1){
        g->tour=adverse(g);
    }
        
    return res;
}

void possibilite(game *g,int tablu[8][8],int *tablu_i,int *tablu_j){
    int i,j,k=1;
        
    game *g_temp=NULL;
    coup *cp=NULL;
    g_temp=calloc(1,sizeof(game));
    cp=calloc(1,sizeof(coup));
    for(i=0;i<8;i++){
        cp->pos_x=i;
        for(j=0;j<8;j++){
            cp->pos_y=j;
            *g_temp=copy_game(g);
            if(jouer(cp,g_temp)==1){
                //MLV_wait_seconds(1);
               
                tablu_i[k]=i;
                tablu_j[k]=j;
                //printf("\ntalblu_i=%d tablu_j=%d k=%d",tablu_i[k],tablu_j[k]=j,k);
                tablu[i][j]=POSSIBLE;
                
                k++;
                    
            }
          
                                          
            else{
                tablu[i][j]=VIDE;
            }
        }            
    }
    free(g_temp);
    free(cp);
    tablu_i[0]=k;
    tablu_j[0]=k;
 
}


int existe_affiche_coup(game *g,MLV_Image *options){
    int i,j;
    coup cp;
    int existe=0;
    game g_temp;
    for(i=0;i<8;i++){
        cp.pos_x=i;
        for(j=0;j<8;j++){
            g_temp=copy_game(g);
            cp.pos_y=j;
            if(jouer(&cp,&g_temp)==1){
                MLV_draw_image(options,(taille_place*i)+x_i,(taille_place_y*j)+y_i);
                existe +=1;              
            }
        }
    }
    MLV_actualise_window();
    return existe;
   
}

int existe_coup(game *g){
    int i,j;
    coup cp;
    int existe=0;
    game g_temp;
    for(i=0;i<8;i++){
        cp.pos_x=i;
        for(j=0;j<8;j++){
            g_temp=copy_game(g);
            cp.pos_y=j;
            if(jouer(&cp,&g_temp)==1){
                existe +=1;              
            }
        }
    }
    
   
    return existe;
   
}


coup lire_coup(){
    coup cp;
    int x_mouse;
    int y_mouse;
    int taille=taille_place;
    int taille_y=taille_place_y;
    MLV_wait_mouse(&x_mouse,&y_mouse);
    cp.pos_x = (x_mouse-x_i)/taille;        
    cp.pos_y = (y_mouse-y_i)/taille_y;
    //printf("\nx=%d!!!!!!y=%d!!!!!!\n",cp.pos_x,cp.pos_y);
    return cp;
}


