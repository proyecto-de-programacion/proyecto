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


struct _Game{ 
  Player *players;    /* !<  Structure of the Player  */
  Object *objects[MAX_OBJECTS];    /*!< Structure of the Object */
  Die *dice;          /*!< Structure of the Die */
  Space* spaces[MAX_SPACES + 1];    /*!< Array of structures of Space */
  Command *cmd;    /*!< Last command */
  Link *links;//3103 creado array de links punto 12 de la practica
};



/**
* Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game* game);


/**
* List of callbacks for each command in the game
*/
void game_callback_unknown(Game* game);
void game_callback_exit(Game* game);
void game_callback_next(Game* game);
void game_callback_back(Game* game);
void game_callback_left(Game* game);
void game_callback_right(Game* game);
void game_callback_roll(Game* game);
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
  game_callback_roll,
  game_callback_pickup,
  game_callback_drop};


/**
*      @brief Creates the game
*                              
*      It creates the game, load the spaces to NULL, creates the player
*           and the array of objects and initializes and initializes their Id 
*                     to the local variable i last_cmd to no command                     
*                                      
*      param: structure Game from file game.h
*
*      @alexConache & CiroAlonso                       
*/


STATUS game_create(Game* game) {
  Id i;

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  game->players = player_create();
  for(i=0; i<MAX_OBJECTS; i++){
    game->objects[i]= NULL;
  }
  game->dice = die_create();
  game->cmd = command_create();

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
  
  if (game_create(game) == ERROR){
    return ERROR;
  }
  if (game_reader_load_spaces(game, filename) == ERROR){
    return ERROR;
  } 
  if(game_reader_load_objects(game, filename) == ERROR){
    return ERROR;
  }
  game_set_player_location(game, game_get_space_id_at(game, FIRST_SPACE));
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
  
  die_destroy(game->dice);

  for(i=0; i<MAX_OBJECTS;i++){
    object_destroy(game->objects[i]);
  }
  command_destroy(game->cmd);
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
*      param: Enum_command cmd to choose which callback function you want  
*      @alexConache & CiroAlonso                       
*/


STATUS game_update(Game* game, Command *pc) {
  Enum_command last_cmd;
  last_cmd = command_get_command(pc);
  
  (*game_callback_fn_list[last_cmd])(game);
  
  return OK;
}



/**
*      @brief Returns the last command
*                                                              
*      param: structure Game from file game.h  
*      @AlexConache & CiroAlonso                       
*/


Enum_command game_get_last_command(Game* game){

  return command_get_command(game->cmd);
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
  /*
  for(i=0; i<MAX_OBJECTS && game->objects[i] != NULL; i++){
    printf("=> %d. Object location: %d\n", i+1, (int) game_get_object_location(game,game->objects[i]));
  }
  */
  printf("=> Player location: %d\n", (int) game_get_player_location(game));
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

  die_roll(game->dice);

  
  return;
}



/**
*      @brief Pick up the object from the player location
*                              
*      Checks for multiple errors, if not gets the object from the space the 
*       the player is and if found, gives it to the player   
*
*      param: structure Game from file game.h 
*      @AlexConache & CiroAlonso                       
*/


void game_callback_pickup(Game *game){
  Id object_id = NO_ID; /* El id del objeto del nombre pasado*/ 
	int i;
  char *pName = NULL;

  pName = command_getName(game->cmd);

  if(!game || pName == NULL){
    return;
  }

  for(i=0; i< MAX_OBJECTS && game->objects[i] != NULL; i++){
	  /*  Si existe un objeto con ese nombre comprueba que este en el espacio del jugador  */
    if(object_get_name(game->objects[i]) == pName){
      object_id = object_get_id(game->objects[i]);

      /*  Si esta el objeto en el espacio del jugador lo elimina del espacio y se lo da al jugador */ 

      game_space_getObject(game, object_id);
      player_set_object(game->players, object_id);
      return;
    }

  }
	
  return;
}


/**
*     @brief Drop in the object from the player location
*                              
*      Checks for multiple errors, if not set the object from player to false                        
*      to say that now he hasn't the object in his possesion and place the object 
*                          in the laction of the player
*
*      @param: structure Game from file game.h 
*      @authors Alexandra Conache & Ciro Alonso                       
*/



void game_callback_drop(Game *game){
  Id object_id = NO_ID;
  int i;
  char *pName;

  pName = command_getName(game->cmd);

  if(!game || pName == NULL){
    return;
  }

  for(i=0; i < MAX_OBJECTS && game->objects[i] != NULL; i++){
    if(object_get_name(game->objects[i]) == pName){
      object_id = object_get_id(game->objects[i]);
      player_drop_object(game->players, object_id);
      game_space_setObject(game, object_id);
      return;
    }
  }

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

  space_id = player_get_location(game->players);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID) {
      	player_set_location(game->players, current_id);
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

  space_id = player_get_location(game->players);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_west(game->spaces[i]);
      if (current_id != NO_ID) {
      	player_set_location(game->players, current_id);
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

  space_id = player_get_location(game->players);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_east(game->spaces[i]);
      if (current_id != NO_ID) {
      	player_set_location(game->players, current_id);
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

  space_id = player_get_location(game->players);

  if (NO_ID == space_id) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
	      player_set_location(game->players, current_id);
      }
      return;
    }
  }
}

/**
*      @brief Get the space he is reading 
*                                    
*      param: structure Game from file game.h 
*      param: char filename, necessary to load spaces 
*      @date  17/02/2019 
*      @authors Alexandra Conache & CiroAlonso                       
*/

Space* game_get_space(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }
    
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }
    
  return NULL;
}

STATUS game_set_player_location(Game* game, Id id){
  if(!game || id == NO_ID){
    return ERROR;
  }
  player_set_location(game->players,id);

  return OK;
}


Id game_get_player_location(Game* game){
  return player_get_location(game->players);
}


/*    Set an object to the space of the player   */
STATUS game_space_setObject(Game *game, Id id){
  Id player_loc = NO_ID;
  int i;
  if(!game || id <= 0){
    return ERROR;
  }
  player_loc = game_get_player_location(game);

  for(i=0; i<MAX_SPACES && game->spaces[i] != NULL; i++){
    if(space_get_id(game->spaces[i])==player_loc){

      if(space_set_object(game->spaces[i], id)== ERROR){
        return ERROR;
      }
      
      return OK;
    }
  }

  return ERROR;

}


/*  Returns TRUE if deleted properly the object from the space the player is in    */
STATUS game_space_getObject(Game *game, Id id){
  Id player_loc = NO_ID;
  int i;
  if(!game || id <= 0){
    return ERROR;
  }
  player_loc = game_get_player_location(game);

  for(i=0; i<MAX_SPACES && game->spaces[i] != NULL; i++){
    if(space_get_id(game->spaces[i]) == player_loc){
      /* This function (space_get_object) returns OK if deleted properly the object */
      if(space_get_object(game->spaces[i], id)==OK){
        return OK;
      }
      
      return ERROR;
    }
  }
  return ERROR;
}

/* !< Sets the object to the space you want */
STATUS game_setObject_space(Game *game, Id spaceID, Id objectId){
  int i;

  for(i=0; i<MAX_SPACES && game->spaces[i] != NULL; i++){
      if(space_get_id(game->spaces[i]) == spaceID){
      space_set_object(game->spaces[i], objectId);
      return OK;
    }
  }

  return ERROR;
}

/*  Gets the object to the space you want */
BOOL game_getObject_space(Game *game, Id spaceID, Id objectId){
  int i;
  if(objectId == NO_ID){
    return FALSE;
  }
  for(i=0; i<MAX_SPACES && game->spaces[i] != NULL; i++){
    if(space_get_id(game->spaces[i]) == spaceID){     
      if(space_object_is_in(game->spaces[i], objectId)){
        return TRUE;
      }
    }
  }

  return FALSE;
}