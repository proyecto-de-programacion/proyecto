/** 
 * @brief It implements the graphic_engine functions
 * 
 * @file graphic_engine.c
 * @author Alexandra Conache && Sara Erika Catana && Ciro Alonso Aquino
 * @version 3.0 
 * @date 4/03/2019
 */

#include <stdlib.h>
#include <stdio.h>
#include "graphic_engine.h"
/*usar strcat y strlen para lo de los espacios en blanco*/

struct _Graphic_engine{
  Area  *map, 
        *descript, 
        *banner, 
        *help, 
        *feedback;   /*!< Different type of pointers of structures of Area */
};



/**
*      @brief Creates the graphic part of the game
*                              
*      It creates the graphic engine which is in charge of creating memroy for graphic       
*         part and initialize the screen parts and return the structure 
*
*      @authors Alexandra Conache & CiroAlonso                       
*/

Graphic_engine *graphic_engine_create(){
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init();
  ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));

  ge->map      = screen_area_init( 1, 1, 48, 13);
  ge->descript = screen_area_init(50, 1, 29, 13);
  ge->banner   = screen_area_init(28,15, 23,  1);
  ge->help     = screen_area_init( 1,16, 78,  2);
  ge->feedback = screen_area_init( 1,19, 78,  3);

  return ge;
}



/**
*      @brief Destroys the graphics of the game
*                              
*      In charge of calling the functions neccessary to destroy the screen parts
*           and the total screen and then liberating the structure                   
*                                      
*      param: structure Graphic_engine from graphic_engine.c
*
*      @authors Alexandra Conache & CiroAlonso                       
*/

void graphic_engine_destroy(Graphic_engine *ge){
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}




/**
*      @brief Paints the game in the screen
*                              
*      Initializes variables, checks for errors and then creates the part in the screen 
*           in which the game s going to be played                  
*                                      
*      param: structure Graphic_engine from graphic_engine.c
*
*      @authors Alexandra Conache & CiroAlonso                       
*/

void graphic_engine_paint_game(Graphic_engine *ge, Game *game){
  Id id_act = NO_ID, 
  id_back = NO_ID, 
  id_next = NO_ID, 
  id_left = NO_ID,
  id_right = NO_ID,
  object_id = NO_ID;
  Space* space_act = NULL;
  Space* space_next = NULL;
  Space* space_back = NULL;
  int *die = NULL;
  int i = 0;
  int j = 0;
  char *obj[MAX_OBJECTS];
  char str[255];
  Enum_command last_cmd = UNKNOWN;
  extern char *cmd_to_str[];
  char *gdesc[2];
  Set *setAux = NULL;
  Id player_object_aux = NO_ID;
  int last_roll = NO_ID;

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = player_get_location(game->players)) != NO_ID){
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);
    id_left = space_get_west(space_act);
    id_right = space_get_east(space_act);

    for(i=0;i<MAX_OBJECTS;i++){
      obj[i] = "       ";
    }

    /* Miramos como se haria con el nuevo object without location*/
    for(i=0; i <MAX_OBJECTS; i++){
      object_id = NO_ID;

      object_id = object_get_id(game->objects[i]);
      if(game_getObject_space(game, id_back , object_id)==TRUE){
        obj[i] = object_get_name(game->objects[i]);
      }
    }


    if (id_back != NO_ID) {
      space_back = game_get_space(game,id_back);
      gdesc[0] = space_get_gdesc1(space_back);
      gdesc[1] = space_get_gdesc2(space_back);
      gdesc[2] = space_get_gdesc3(space_back);
      
      sprintf(str, "  |       %s%2d|",gdesc[0],(int) id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %s|",gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %s|",gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s%s%s%s|",obj[0], obj[1], obj[2], obj[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "    +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }

    for(i=0;i<MAX_OBJECTS;i++){
      obj[i] = "       ";
    }
    for(i=0; i <MAX_OBJECTS; i++){
      object_id = NO_ID;

      object_id = object_get_id(game->objects[i]);
      if(game_getObject_space(game, id_act , object_id)==TRUE){
        obj[i] = object_get_name(game->objects[i]);
      }
    }

    if (id_act != NO_ID) {
      space_act = game_get_space(game,id_act);
      gdesc[0] = space_get_gdesc1(space_act);
      gdesc[1] = space_get_gdesc2(space_act);
      gdesc[2] = space_get_gdesc3(space_act);
      
       sprintf(str, "   +-----------+");
      screen_area_puts(ge->map, str);
      if (id_act != NO_ID && id_left != NO_ID && id_right !=NO_ID){
        sprintf(str, " <| 8D      %2d |>",(int) id_act);
      }
      else if(id_act !=NO_ID && id_left == NO_ID && id_right != NO_ID){
        sprintf(str, "  | 8D      %2d |>",(int) id_act);
      }
      else if(id_act !=NO_ID && id_left != NO_ID && id_right == NO_ID){
        sprintf(str, " <| 8D      %2d |",(int) id_act);
      }
      else {
        sprintf(str, "  | 8D      %2d |",(int) id_act);
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "  |        |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |        |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |      %s|",gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |      %s|",gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |      %s|",gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |             |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |             |");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s%s%s%s|",obj[0], obj[1], obj[2], obj[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-------------+");
      screen_area_puts(ge->map, str);
}

    for(i=0;i<MAX_OBJECTS;i++){
      obj[i] = "       ";
    }

    for(i=0; i <MAX_OBJECTS; i++){
      object_id = NO_ID;

      object_id = object_get_id(game->objects[i]);
      if(game_getObject_space(game, id_next , object_id)==TRUE){
        obj[i] = object_get_name(game->objects[i]);
      }
    }
    
    if (id_next != NO_ID) {
      space_next = game_get_space(game,id_next);
      gdesc[0] = space_get_gdesc1(space_next);
      gdesc[1] = space_get_gdesc2(space_next);
      gdesc[2] = space_get_gdesc3(space_next);
      
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
       sprintf(str, "  +-------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %s%2d|",gdesc[0],(int) id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |      %s|",gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |      %s|",gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s%s%s%s|",obj[0], obj[1], obj[2], obj[3]);
      screen_area_puts(ge->map, str);
}
  }

  /* Paint the in the description area */

  /*  Prints in the description all the objects of the game  */ 
  screen_area_clear(ge->descript);

  for(i=0; i<MAX_OBJECTS && game->objects[i]!= NULL ;i++){
    sprintf(str, " Object %d: %s" ,i, object_get_name(game->objects[i]));
    screen_area_puts(ge->descript, str);
  }

  /*  Prints the objects the player has in his possesion  */

  setAux = player_get_object(game->players);

  for(i=0; i<MAX_OBJECTS && player_object_aux !=NO_ID ; i++){

    if((player_object_aux = set_get_id(setAux, i)) != NO_ID){

      for(j=0; j<MAX_OBJECTS; j++){
        if(player_object_aux == object_get_id(game->objects[j])){
          sprintf(str, "Object of the player: %s", object_get_name(game->objects[j]));
          screen_area_puts(ge->descript, str);
        }
      }
    }
  }
  set_destroy(setAux);

  /* Paints the last roll of the dice */
  
  last_roll = die_get_lastRoll(game->dice);
  sprintf(str, "Last roll : %d", last_roll);
  screen_area_puts(ge->descript, str);

  /* Paint the in the banner area */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Paint the in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, " next or n, back or b, left or l, right or r, roll or rl, pickup or p, drop or d, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint the in the feedback area */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s", cmd_to_str[last_cmd-NO_CMD]);
  screen_area_puts(ge->feedback, str);

  j = die_get_lastRoll(game->dice);
  sprintf(str, "Last throw (dice): %d",j);
  screen_area_puts(ge->descript,str);
 
  if (last_cmd == 2){
    (*die)--;
    sprintf(str,"%d ",*die);
    screen_area_puts(ge->descript,str);
  }


  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
