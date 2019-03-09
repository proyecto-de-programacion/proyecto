/**
 * @brief It implements the game interface and all the associated callbacks
 * for each command
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_reader.h"

#define N_CALLBACK 9

/**
   Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game* game);


/**
   List of callbacks for each command in the game
*/
void game_callback_unknown(Game* game);
void game_callback_exit(Game* game);
void game_callback_next(Game* game);
void game_callback_back(Game* game);
void game_callback_left(Game* game);
void game_callback_right(Game* game);
void game_callback_pickup(Game* game);
void game_callback_drop(Game* game);
/* */

static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_next,
  game_callback_back,
  game_callback_left,
  game_callback_right,
  game_callback_pickup,
  game_callback_drop};


/**
*      @brief Creates the game
*                              
*      It creates the game, load the spaces to NULL, creates the player
*           and the object and initializes the last_cmd to no command                     
*                                      
*      param: structure Game from file game.h

*      @alexConache & CiroAlonso                       
*/


STATUS game_create(Game* game) {
  int i;

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  game->players = player_create();
  for(i=0; i<MAX_OBJECTS; i++){
    game->objects[i]= object_create();
  }
  
  game->last_cmd = NO_CMD;

  return OK;
}

/**
*      @brief Creates the game from file
*                              
*      It creates the game, load the spaces and set the                                 
*             locations of the player and the object                         
*                                      
*      param: structure Game from file game.h
*      param: char filename, necessary to load spaces  
*      @alexConache & CiroAlonso                       
*/

STATUS game_create_from_file(Game* game, char* filename) {
  int i;
  if (game_create(game) == ERROR)
    return ERROR;

  if (game_reader_load_spaces(game, filename) == ERROR)
    return ERROR;

  game_set_player_location(game->players, game_get_space_id_at(game, 0));
  for(i=0; i<MAX_OBJECTS; i++){
  game_set_object_location(game->objects[i], game_get_space_id_at(game, 0));
  }
  return OK;
}



/**
*     @brief Destroys de memory peviously called   

*     Destroys the memroy created for each space, the player                                
*                         and the object             
*     param: structure Game from file game.h                                
*     @alexConache & CiroAlonso                                 
*/

STATUS game_destroy(Game* game) {
  int i;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }

  player_destroy(game->players);

  for(i=0; i<MAX_OBJECTS;i++){
    object_destroy(game->objects[i]);
  }
  return OK;
}




/**
*      @brief Adds space to the game
*                                   
*      param: structure Game from file game.h
*      param: struct Space from file space.c  
*      @alexConache & CiroAlonso                       
*/

STATUS game_add_space(Game* game, Space* space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}



/**
*      @brief Returns the id of the space
*                              
*      Checks for errors, if not returns the id of the space of the game
*                 thanks to the finction space_get_id
*      param: structure Game from file game.h
*      param: int position, the position of the space
*      @alexConache & CiroAlonso                       
*/


Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}



/**
*      @brief Updates the game 
*                              
*      Updates the game using the callback functions                        
*                                      
*      param: structure Game from file game.h
*      param: T_command cmd to choose which of callback function you want  
*      @alexConache & CiroAlonso                       
*/


STATUS game_update(Game* game, T_Command cmd) {
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
  return OK;
}



/**
*      @brief Returns the last command
*                                                              
*      param: structure Game from file game.h  
*      @AlexConache & CiroAlonso                       
*/


T_Command game_get_last_command(Game* game){
  return game->last_cmd;
}




/**
*      @brief Print out the game
*                              
*      Print out the player location as well as the object location                         
*                                      
*      param: structure Game from file game.h  
*      @AlexConache & CiroAlonso                       
*/

void game_print_data(Game* game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }
  for(i=0; i<MAX_OBJECTS; i++){
    printf("=> %d. Object location: %d\n", i+1, (int) game_get_object_location(game->objects[i]));
  }
  printf("=> Player location: %d\n", (int) game_get_player_location(game->players));
  printf("prompt:> ");
}




/**
*      @brief The game is finished 
*                              
*      param: structure Game from file game.h 
*      @AlexConache & CiroAlonso                       
*/

BOOL game_is_over(Game* game) {
  return FALSE;
}

void game_callback_roll(Game* game){

  /*funcion que usa el dado creado en el punto 3
    die_roll:
    srand(semilla->tiempo)
    rand()
    create()
      srand(aqui recogemos el valor de rand generado en roll)<- inicializamos la semilla una unica vez
    roll()
      rand()
    destroy
  */


  /* de momento no imprime nada por pantalla porque hay que implementarlo en graphic_engine */
  Id die_id = NO_ID;

  if(die_id == NO_ID){
    return;
  }

    die_roll(game->dice);

  free(game->dice);
  
  return;
}



/**
*      @brief Pick up the object from the player location
*                              
*      Checks for multiple errors, if not set the object from player to true                         
*        to say that he has the object in his possesion and eliminates the
*                object location to eliminate it visually   
*
*      param: structure Game from file game.h 
*      @AlexConache & CiroAlonso                       
*/

void game_callback_pickup(Game* game){

  Id player_id=NO_ID;
  Id object_id=NO_ID;

  object_id=game_get_object_location(game->objects);
  player_id=game_get_player_location(game->players);

  if(object_id == NO_ID || player_id == NO_ID){
    return;
  }

  if(object_id != player_id){
    return;
  }

  player_get_object(game->players);
  game_set_object_location(game->objects,FALSE);
}




/**
*     @brief Drop in the object from the player location
*                              
*      Checks for multiple errors, if not set the object from player to false                        
*      to say that now he hasn't the object in his possesion and place the object 
*                          in the laction of the player
*
*      param: structure Game from file game.h 
*      @AlexConache & CiroAlonso                       
*/

void game_callback_drop(Game* game){

  game_set_object_location(game->objects , game_get_player_location(game->players));
  player_set_object(game->players,FALSE);

}


void game_callback_unknown(Game* game) {
}

void game_callback_exit(Game* game) {
}


/**
*      @brief It moves the player location one further box 
*                              
*      It moves the player one box futher from his actual position
*
*      param: structure Game from file game.h 
*      @AlexConache & CiroAlonso                       
*/


void game_callback_next(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game->players);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID) {
      	game_set_player_location(game->players, current_id);
      }
      return;
    }
  }
}
/**
*      @brief It moves the player to the box linked on the left
*
*      It moves the player to the left box from his actual position
*
*      param: structure Game from file game.h
*      @AlexConache & CiroAlonso
*/
void game_callback_left(Game* game) {

  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game->players);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_west(game->spaces[i]);
      if (current_id != NO_ID) {
      	game_set_player_location(game->players, current_id);
      }
      return;
    }
  }
}

/**
*      @brief It moves the player to the box linked on the right
*
*      It moves the player to the right box from his actual position
*
*      param: structure Game from file game.h
*      @AlexConache & CiroAlonso
*/
void game_callback_right(Game* game) {

  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game->players);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_east(game->spaces[i]);
      if (current_id != NO_ID) {
      	game_set_player_location(game->players, current_id);
      }
      return;
    }
  }
}



/**
*      @brief It moves the player one box back
*
*      It moves the player one box back from his actual position
*                              
*      param: structure Game from file game.h 
*      @AlexConache & CiroAlonso                       
*/


void game_callback_back(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game->players);

  if (NO_ID == space_id) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
	      game_set_player_location(game->players, current_id);
      }
      return;
    }
  }
}

