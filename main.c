
/*****************************************/
/******************MAIN.C*****************/
/***************CREATED*BY****************/ 
/**SOUPILAS*DIMITRIOS*&*ALEKSEI*PASHININ**/
/*************PROJECT*OTHELLO*************/
/********************℗********************/
/*****************************************/

#include"menu.h"


int main( int argc, char *argv[] ){
  int human (int, int *);
  MLV_create_window_with_default_font("Projet","Projet",x,y,"Fonts2/DaysOne-Regular.ttf" , 50);
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Image *image;
  
  image = MLV_load_image( "images2/intro.png" );
  MLV_resize_image( image, x, y);
  MLV_draw_image( image,0, 0);
  MLV_actualise_window();
  MLV_wait_seconds(3);
  MLV_free_image( image );
  
  while(1){
    menu_princ();
  }
  MLV_wait_seconds(1);
  MLV_draw_adapted_text_box(170,675,"STOP", 10, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_actualise_window();
  MLV_wait_seconds(3);
  MLV_free_window();
  exit(0);
}