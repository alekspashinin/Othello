/*****************************************/
/****************MENU.C*****************/
/***************CREATED*BY****************/ 
/**SOUPILAS*DIMITRIOS*&*ALEKSEI*PASHININ**/
/*************PROJECT*OTHELLO*************/
/********************℗********************/
/*****************************************/


#include "menu.h"


void menu_princ();
void blic_test(int i);

void newgame(){
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image3;
  image3 = MLV_load_image( "images2/back.png" );
  MLV_resize_image( image3, x, y);
  MLV_draw_image( image3, 0, 0 );
  MLV_Image *button1;
  button1 = MLV_load_image( "images2/1player1.png" );
  MLV_draw_image( button1,x/1.6, y/2.5 );
  MLV_Image *button2;
  button2 = MLV_load_image( "images2/2players1.png" );
  MLV_draw_image( button2,x/1.6, y/2.5+img_y+25);
  MLV_Image *button4;
  button4 = MLV_load_image( "images2/exit1.png" );
  MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
  MLV_actualise_window();
  MLV_wait_seconds(0.5);
  MLV_free_image(image3);
  MLV_free_image(button1);
  MLV_free_image(button2);
  MLV_free_image(button4);
  blic_test(1);
  return ;
}

void newgame2(){
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image3;
  image3 = MLV_load_image( "images2/back.png" );
  MLV_resize_image( image3, x, y);
  MLV_draw_image( image3, 0, 0 );
  MLV_Image *button1;
  button1 = MLV_load_image( "images2/level01.png" );
  MLV_draw_image( button1,x/1.6, y/2.5);
  MLV_Image *button2;
  button2 = MLV_load_image( "images2/level11.png" );
  MLV_draw_image( button2,x/1.92, y/2.5+img_y+25 );
  MLV_Image *button3;
  button3 = MLV_load_image( "images2/level21.png" );
  MLV_draw_image( button3,x/1.37, y/2.5+img_y+25 );
  MLV_Image *button4;
  button4 = MLV_load_image( "images2/exit1.png" );
  MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
  MLV_actualise_window();
  MLV_wait_seconds(0.5);
  MLV_free_image(image3);
  MLV_free_image(button1);
  MLV_free_image(button2);
  MLV_free_image(button3);
  MLV_free_image(button4);
  blic_test(2);
  return ;
}

void newgame3(){
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image3;
  image3 = MLV_load_image( "images2/back.png" );
  MLV_resize_image( image3, x, y);
  MLV_draw_image( image3, 0, 0 );
  MLV_Image *annonce;
  annonce = MLV_load_image( "images2/prof.png" );
  MLV_draw_image( annonce,x/1.92, y/2.5);
  MLV_Image *button2;
  button2 = MLV_load_image( "images2/2.png" );
  MLV_draw_image( button2,x/1.88+100, y/2.5+img_y+25 );
  MLV_Image *button3;
  button3 = MLV_load_image( "images2/3.png" );
  MLV_draw_image( button3,x/1.88+200, y/2.5+img_y+25 );
  MLV_Image *button5;
  button5 = MLV_load_image( "images2/4.png" );
  MLV_draw_image( button5,x/1.88+300, y/2.5+img_y+25);
  MLV_Image *button4;
  button4 = MLV_load_image( "images2/exit1.png" );
  MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
  MLV_actualise_window();
  MLV_wait_seconds(0.5);
  MLV_free_image(image3);
  MLV_free_image(button2);
  MLV_free_image(button3);
  MLV_free_image(button4);
  MLV_free_image(button5);
  MLV_free_image(annonce);
  blic_test(5);
  return ;
}


void about(){
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image3;
  image3 = MLV_load_image( "images2/back.png" );
  MLV_resize_image( image3, x, y);
  MLV_draw_image( image3, 0, 0 );
  MLV_Image *photo1;
  photo1 = MLV_load_image( "images2/about.png" );
  MLV_resize_image_with_proportions( photo1,500, 500);
  MLV_draw_image( photo1, x/2.1*1.125, y/9*1.125 );    
  MLV_Image *button4;
  button4 = MLV_load_image( "images2/exit1.png" );
  MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
  MLV_actualise_window();
  MLV_wait_seconds(0.5);
  MLV_free_image(image3);
  MLV_free_image(photo1);
  MLV_free_image(button4);
  blic_test(4);
}



void button(int z, int x1, int y1){
  if (z==0){
    if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5 && y1 < (y/2.5)+img_y){
    newgame();
  }
  else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+img_y+25 && y1 < y/2.5+img_y+25+img_y){
    MLV_wait_seconds(0.5);
    menu_princ();
    return;
  }
  else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+2*img_y+50 && y1 < y/2.5+2*img_y+50+img_y){
    about();
  }
  else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+3*img_y+75 && y1 < y/2.5+3*img_y+75+img_y){
    MLV_free_window();
    exit(0);
    return;
  }
  }
  else if (z==1){
   if (x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5 && y1 < (y/2.5)+img_y){
    newgame2();
  }
   else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+img_y+25 && y1 < y/2.5+img_y+25+img_y){
       //conect 1v1
       MLV_Image *board;
       board= MLV_load_image("images2/board.png");
       MLV_resize_image(board, x, y);
       MLV_Image *white;
       white=MLV_load_image("images2/white.png");
       MLV_resize_image(white,taille_place,taille_place_y);
       MLV_Image *black;
       black=MLV_load_image("images2/black.png");
       MLV_resize_image(black,taille_place,taille_place_y);
       MLV_Image *options;
       options=MLV_load_image("images2/triangle.png");
       MLV_resize_image(options,taille_place,taille_place_y);
       
       game g=mode_1v1(board,black,white,options);
       affiche_score_fin_MLV(&g,board,white, black);

       MLV_free_image(board);
       MLV_free_image(white);
       MLV_free_image(black);
       MLV_free_image(options);
       MLV_wait_seconds(0.5);
       
       return ;
   }
  else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+3*img_y+75 && y1 < y/2.5+3*img_y+75+img_y){
    MLV_wait_seconds(0.5);
    menu_princ();
  }
  }
  else if (z==2){
  if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5 && y1 < ((y/2.5)+img_y)){
    MLV_wait_seconds(0.5);
    /*!!!!!!!!!!!!!!!!!!!CONNECT JEUX 1 PLAYER LEVEL 0 !!!!!!!!!!!!!!!!!!!*/
      MLV_Image *board;
       board= MLV_load_image("images2/board.png");
       MLV_resize_image(board, x, y);
       MLV_Image *white;
       white=MLV_load_image("images2/white.png");
       MLV_resize_image(white,taille_place,taille_place_y);
       MLV_Image *black;
       black=MLV_load_image("images2/black.png");
       MLV_resize_image(black,taille_place,taille_place_y);
       MLV_Image *options;
       options=MLV_load_image("images2/triangle.png");
       MLV_resize_image(options,taille_place,taille_place_y);
       
       game g= mode_1(board, black, white, options);
       affiche_score_fin_MLV(&g, board, white, black);
       
       MLV_free_image(board);
       MLV_free_image(white);
       MLV_free_image(black);
       MLV_free_image(options);
       MLV_wait_seconds(0.5);
    //menu_princ();
    return;
  }
  else if(x1 > x/1.92 && x1 < ((x/1.92)+img_x) && y1 > y/2.5+img_y+25 && y1 < ((y/2.5)+2*img_y+25)){
    /*!!!!!!!!!!!!!!!!!!!CONNECT JEUX 1 PLAYER LEVEL 1 !!!!!!!!!!!!!!!!!!!*/
        MLV_Image *board;
       board= MLV_load_image("images2/board.png");
       MLV_resize_image(board, x, y);
       MLV_Image *white;
       white=MLV_load_image("images2/white.png");
       MLV_resize_image(white,taille_place,taille_place_y);
       MLV_Image *black;
       black=MLV_load_image("images2/black.png");
       MLV_resize_image(black,taille_place,taille_place_y);
       MLV_Image *options;
       options=MLV_load_image("images2/triangle.png");
       MLV_resize_image(options,taille_place,taille_place_y);
       
       game g=mode_2(board, black, white, options);
         affiche_score_fin_MLV(&g, board,white, black);
       
       MLV_free_image(board);
       MLV_free_image(white);
       MLV_free_image(black);
       MLV_free_image(options);
    MLV_wait_seconds(0.5);
    //menu_princ();
    return;
  }
  else if(x1 > x/1.37 && x1 < ((x/1.37)+img_x) && y1 > y/2.5+img_y+25 && y1 < ((y/2.5)+2*img_y+25)){
    newgame3();
    MLV_wait_seconds(0.5);
    //menu_princ();
    return;
  }
  
  else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+3*img_y+75 && y1 < y/2.5+3*img_y+75+img_y){
    newgame();
    return;
  }
  }
  /////////////////////////////////////
  else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+3*img_y+75 && y1 < y/2.5+3*img_y+75+img_y && z==3){
    menu_princ();
    
    return;
  }
  else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+3*img_y+75 && y1 < y/2.5+3*img_y+75+img_y && z==4){
    menu_princ();
  }
  else if(z==5){
   if(x1 > x/1.88+100 && x1 < x/1.88+100+66 && y1 > y/2.5+img_y+25 && y1 < y/2.5+2*img_y+25){
    /*!!!!!!!!!!!!!!!!!!!CONNECT JEUX 1 PLAYER LEVEL 2 PROFONDEUR 4 !!!!!!!!!!!!!!!!!!!*/
        MLV_Image *board;
       board= MLV_load_image("images2/board.png");
       MLV_resize_image(board, x, y);
       MLV_Image *white;
       white=MLV_load_image("images2/white.png");
       MLV_resize_image(white,taille_place,taille_place_y);
       MLV_Image *black;
       black=MLV_load_image("images2/black.png");
       MLV_resize_image(black,taille_place,taille_place_y);
       MLV_Image *options;
       options=MLV_load_image("images2/triangle.png");
       MLV_resize_image(options,taille_place,taille_place_y);
       
       game g=mode_3(board, black, white, options,4);
         affiche_score_fin_MLV(&g, board,white, black);
       
       MLV_free_image(board);
       MLV_free_image(white);
       MLV_free_image(black);
       MLV_free_image(options);
    MLV_wait_seconds(0.5);
    MLV_actualise_window();
  }
  else if(x1 > x/1.88+200 && x1 < x/1.88+200+66 && y1 > y/2.5+img_y+25 && y1 < y/2.5+2*img_y+25){
    /*!!!!!!!!!!!!!!!!!!!CONNECT JEUX 1 PLAYER LEVEL 2 PROFONDEUR 6 !!!!!!!!!!!!!!!!!!!*/
          MLV_Image *board;
       board= MLV_load_image("images2/board.png");
       MLV_resize_image(board, x, y);
       MLV_Image *white;
       white=MLV_load_image("images2/white.png");
       MLV_resize_image(white,taille_place,taille_place_y);
       MLV_Image *black;
       black=MLV_load_image("images2/black.png");
       MLV_resize_image(black,taille_place,taille_place_y);
       MLV_Image *options;
       options=MLV_load_image("images2/triangle.png");
       MLV_resize_image(options,taille_place,taille_place_y);
       
       game g=mode_3(board, black, white, options,6);
         affiche_score_fin_MLV(&g, board,white, black);
       
       MLV_free_image(board);
       MLV_free_image(white);
       MLV_free_image(black);
       MLV_free_image(options);
    MLV_actualise_window();
  }
  else if(x1 > x/1.88+300 && x1 < x/1.88+300+66 && y1 > y/2.5+img_y+25 && y1 < y/2.5+2*img_y+25){
    /*!!!!!!!!!!!!!!!!!!!CONNECT JEUX 1 PLAYER LEVEL 2 PROFONDEUR 8 !!!!!!!!!!!!!!!!!!!*/
          MLV_Image *board;
       board= MLV_load_image("images2/board.png");
       MLV_resize_image(board, x, y);
       MLV_Image *white;
       white=MLV_load_image("images2/white.png");
       MLV_resize_image(white,taille_place,taille_place_y);
       MLV_Image *black;
       black=MLV_load_image("images2/black.png");
       MLV_resize_image(black,taille_place,taille_place_y);
       MLV_Image *options;
       options=MLV_load_image("images2/triangle.png");
       MLV_resize_image(options,taille_place,taille_place_y);
       
       game g=mode_3(board, black, white, options,8);
         affiche_score_fin_MLV(&g, board,white, black);
       
       MLV_free_image(board);
       MLV_free_image(white);
       MLV_free_image(black);
       MLV_free_image(options);
    MLV_actualise_window();
  }
  else if(x1 > x/1.6 && x1 < x/1.6+img_x && y1 > y/2.5+3*img_y+75 && y1 < y/2.5+4*img_y+75){
    newgame2();
  }
  }
  else{
    blic_test(z);
  }
}


void nav(int x1, int y1, int i){
  if(i==0){
    if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5 && y1 < ((y/2.5)+img_y)){
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/newgame2.png" );
      MLV_draw_image( button1,x/1.6, y/2.5 );
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/settings1.png" );
      MLV_draw_image( button2,x/1.6, y/2.5+img_y+25);
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/about1.png" );
      MLV_draw_image( button3,x/1.6, y/2.5+2*img_y+50);
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
      MLV_actualise_window();
    }
    else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+img_y+25 && y1 < y/2.5+img_y+25+img_y){
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/newgame1.png" );
      MLV_draw_image( button1,x/1.6, y/2.5 );
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/settings2.png" );
      MLV_draw_image( button2,x/1.6, y/2.5+img_y+25);
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/about1.png" );
      MLV_draw_image( button3,x/1.6, y/2.5+2*img_y+50);
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
      MLV_actualise_window();
    }
    else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+2*img_y+50 && y1 < y/2.5+2*img_y+50+img_y){
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/newgame1.png" );
      MLV_draw_image( button1,x/1.6, y/2.5 );
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/settings1.png" );
      MLV_draw_image( button2,x/1.6, y/2.5+img_y+25);
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/about2.png" );
      MLV_draw_image( button3,x/1.6, y/2.5+2*img_y+50);
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
      MLV_actualise_window();
    }
    
    else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+3*img_y+75 && y1 < y/2.5+3*img_y+75+img_y){
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/newgame1.png" );
      MLV_draw_image( button1,x/1.6, y/2.5 );
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/settings1.png" );
      MLV_draw_image( button2,x/1.6, y/2.5+img_y+25);
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/about1.png" );
      MLV_draw_image( button3,x/1.6, y/2.5+2*img_y+50);
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit2.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
      MLV_actualise_window();
    }
    else{
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/newgame1.png" );
      MLV_draw_image( button1,x/1.6, y/2.5 );
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/settings1.png" );
      MLV_draw_image( button2,x/1.6, y/2.5+img_y+25);
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/about1.png" );
      MLV_draw_image( button3,x/1.6, y/2.5+2*img_y+50);
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
      MLV_actualise_window();
    }
    
  }
  else if(i==1){
    if (x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5 && y1 < ((y/2.5)+img_y)){
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/1player2.png" );
      MLV_draw_image( button1,x/1.6, y/2.5 );
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/2players1.png" );
      MLV_draw_image( button2,x/1.6, y/2.5+img_y+25);
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_wait_seconds(0.5);
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button4);
    }
    else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+img_y+25 && y1 < y/2.5+img_y+25+img_y){
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/1player1.png" );
      MLV_draw_image( button1,x/1.6, y/2.5 );
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/2players2.png" );
      MLV_draw_image( button2,x/1.6, y/2.5+img_y+25);
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_wait_seconds(0.5);
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button4);
    }
    else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+3*img_y+75 && y1 < y/2.5+3*img_y+75+img_y){
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/1player1.png" );
      MLV_draw_image( button1,x/1.6, y/2.5 );
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/2players1.png" );
      MLV_draw_image( button2,x/1.6, y/2.5+img_y+25);
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit2.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_wait_seconds(0.5);
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button4);
    }
    else{
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/1player1.png" );
      MLV_draw_image( button1,x/1.6, y/2.5 );
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/2players1.png" );
      MLV_draw_image( button2,x/1.6, y/2.5+img_y+25);
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button4);
    }
  }
  else if(i==2){
    if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5 && y1 < ((y/2.5)+img_y)){
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/level02.png" );
      MLV_draw_image( button1,x/1.6, y/2.5);
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/level11.png" );
      MLV_draw_image( button2,x/1.92, y/2.5+img_y+25 );
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/level21.png" );
      MLV_draw_image( button3,x/1.37, y/2.5+img_y+25 ); 
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
    }
    else if(x1 > x/1.92 && x1 < ((x/1.92)+img_x) && y1 > y/2.5+img_y+25 && y1 < ((y/2.5)+2*img_y+25)){
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/level01.png" );
      MLV_draw_image( button1,x/1.6, y/2.5);
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/level12.png" );
      MLV_draw_image( button2,x/1.92, y/2.5+img_y+25 );
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/level21.png" );
      MLV_draw_image( button3,x/1.37, y/2.5+img_y+25 ); 
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
    }
    else if(x1 > x/1.37 && x1 < ((x/1.37)+img_x) && y1 > y/2.5+img_y+25 && y1 < ((y/2.5)+2*img_y+25)){
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/level01.png" );
      MLV_draw_image( button1,x/1.6, y/2.5);
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/level11.png" );
      MLV_draw_image( button2,x/1.92, y/2.5+img_y+25 );
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/level22.png" );
      MLV_draw_image( button3,x/1.37, y/2.5+img_y+25 );  
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
    }
    else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+3*img_y+75 && y1 < y/2.5+3*img_y+75+img_y){
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/level01.png" );
      MLV_draw_image( button1,x/1.6, y/2.5);
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/level11.png" );
      MLV_draw_image( button2,x/1.92, y/2.5+img_y+25 );
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/level21.png" );
      MLV_draw_image( button3,x/1.37, y/2.5+img_y+25 );  
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit2.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
    }
    else{
      MLV_Image *button1;
      button1 = MLV_load_image( "images2/level01.png" );
      MLV_draw_image( button1,x/1.6, y/2.5);
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/level11.png" );
      MLV_draw_image( button2,x/1.92, y/2.5+img_y+25 );
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/level21.png" );
      MLV_draw_image( button3,x/1.37, y/2.5+img_y+25 );
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button1);
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
    }
  }
  else if(x1 > x/1.6 && x1 < ((x/1.6)+img_x) && y1 > y/2.5+3*img_y+75 && y1 < y/2.5+3*img_y+75+img_y &&( i==2 || i==3 || i==4)){
    MLV_Image *button4;
    button4 = MLV_load_image( "images2/exit2.png" );
    MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
    MLV_actualise_window();
    MLV_free_image(button4);
    MLV_actualise_window();
  }
  else if(i==5){
    if(x1 > x/1.88+100 && x1 < x/1.88+100+66 && y1 > y/2.5+img_y+25 && y1 < y/2.5+2*img_y+25){
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/2-2.png" );
      MLV_draw_image( button2,x/1.88+100, y/2.5+img_y+25 );
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/3.png" );
      MLV_draw_image( button3,x/1.88+200, y/2.5+img_y+25 );
      MLV_Image *button5;
      button5 = MLV_load_image( "images2/4.png" );
      MLV_draw_image( button5,x/1.88+300, y/2.5+img_y+25);
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
      MLV_free_image(button5);
      
    }
    else if(x1 > x/1.88+200 && x1 < x/1.88+200+66 && y1 > y/2.5+img_y+25 && y1 < y/2.5+2*img_y+25){
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/2.png" );
      MLV_draw_image( button2,x/1.88+100, y/2.5+img_y+25 );
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/3-2.png" );
      MLV_draw_image( button3,x/1.88+200, y/2.5+img_y+25 );
      MLV_Image *button5;
      button5 = MLV_load_image( "images2/4.png" );
      MLV_draw_image( button5,x/1.88+300, y/2.5+img_y+25);
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
      MLV_free_image(button5);
    }
    else if(x1 > x/1.88+300 && x1 < x/1.88+300+66 && y1 > y/2.5+img_y+25 && y1 < y/2.5+2*img_y+25){
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/2.png" );
      MLV_draw_image( button2,x/1.88+100, y/2.5+img_y+25 );
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/3.png" );
      MLV_draw_image( button3,x/1.88+200, y/2.5+img_y+25 );
      MLV_Image *button5;
      button5 = MLV_load_image( "images2/4-2.png" );
      MLV_draw_image( button5,x/1.88+300, y/2.5+img_y+25);;
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
    }
    else if(x1 > x/1.6 && x1 < x/1.6+img_x && y1 > y/2.5+3*img_y+75 && y1 < y/2.5+4*img_y+75){
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/2.png" );
      MLV_draw_image( button2,x/1.88+100, y/2.5+img_y+25 );
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/3.png" );
      MLV_draw_image( button3,x/1.88+200, y/2.5+img_y+25 );
      MLV_Image *button5;
      button5 = MLV_load_image( "images2/4.png" );
      MLV_draw_image( button5,x/1.88+300, y/2.5+img_y+25);
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit2.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
      MLV_free_image(button5);
    }
    else{
      MLV_Image *button2;
      button2 = MLV_load_image( "images2/2.png" );
      MLV_draw_image( button2,x/1.88+100, y/2.5+img_y+25 );
      MLV_Image *button3;
      button3 = MLV_load_image( "images2/3.png" );
      MLV_draw_image( button3,x/1.88+200, y/2.5+img_y+25 );
      MLV_Image *button5;
      button5 = MLV_load_image( "images2/4.png" );
      MLV_draw_image( button5,x/1.88+300, y/2.5+img_y+25);
      MLV_Image *button4;
      button4 = MLV_load_image( "images2/exit1.png" );
      MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
      MLV_actualise_window();
      MLV_free_image(button2);
      MLV_free_image(button3);
      MLV_free_image(button4);
      MLV_free_image(button5);
    }
  }
  else if (i==2 || i==3 || i==4){
    MLV_Image *button4;
    button4 = MLV_load_image( "images2/exit1.png" );
    MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
    MLV_actualise_window();
    MLV_free_image(button4);
    MLV_actualise_window();
  }
}


void blic_test(int i){
  MLV_flush_event_queue();
  MLV_Event event;
  int x3, y3;
  do {
    event = MLV_get_event(NULL, NULL, NULL,NULL, NULL,&x3, &y3, NULL,NULL );
    nav(x3,y3,i);
  } while( event != MLV_MOUSE_BUTTON );
  button(i,x3, y3);
  MLV_wait_seconds(0.5);
  return;
}

void menu_princ(){
  MLV_wait_seconds(0.5);
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image3;
  image3 = MLV_load_image( "images2/back.png" );
  MLV_resize_image( image3, x, y);
  MLV_draw_image( image3, 0, 0 );
  MLV_Image *button1;
  button1 = MLV_load_image( "images2/newgame1.png" );
  MLV_draw_image( button1,x/1.6, y/2.5);
  MLV_Image *button2;
  button2 = MLV_load_image( "images2/settings1.png" );
  MLV_draw_image( button2,x/1.6, y/2.5+img_y+25);
  MLV_Image *button3;
  button3 = MLV_load_image( "images2/about1.png" );
  MLV_draw_image( button3,x/1.6, y/2.5+2*img_y+50);
  MLV_Image *button4;
  button4 = MLV_load_image( "images2/exit1.png" );
  MLV_draw_image( button4,x/1.6, y/2.5+3*img_y+75);
  MLV_actualise_window();
  MLV_wait_seconds(0.5);
  MLV_free_image(image3);
  MLV_free_image(button1);
  MLV_free_image(button2);
  MLV_free_image(button3);
  MLV_free_image(button4);
  blic_test(0);
}






