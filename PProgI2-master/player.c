/**
 *  @brief An implementation to use 'player' data type
 *
 *  Here all functions related to 'player' data types are implemented as well as the structure Object
 *
 *  @file player.c
 *  @version 1.0
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "player.h"


/**
 *   @brief Player structure
 *
 *   Stores relevant information about the players playing the game
 *
 */

struct _Player {
  Id id;                        /*!< The ID the player has assigned */
  Id player_location;           /*!< The specific location the player is in */
  char name[WORD_SIZE + 1];     /*!< The name we can assign to the player */
  BOOL object;                  /*!< The way we can assess wether there is an object or not when inquired */
};

/**
 *  @brief Creates the player
 *
 *  player_create Reserves enough memory to create the player
 *                it assigns it an id, a name and a location
 *                as well as making sure everything is working
 *                properly
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *
 *
 */

Player* player_create() {

  Player *newPlayer = NULL;

  newPlayer = (Player *) malloc(sizeof (Player));

  if (newPlayer == NULL) {
    return NULL;
  }
  newPlayer->id = NO_ID;

  newPlayer->name[0] = '\0';

  newPlayer->object = FALSE;

  newPlayer->player_location = NO_ID;

  return newPlayer;
}

/**
 *  @brief Destroys the player by freeing the allocated memory
 *
 *  player_destroy Frees the memory we reserved with the function player_create
 *                 it also assigns it a NULL value to tie up loose ends
 *                 furthermore it has a control code to prevent possible
 *                 errors
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player the player created that's going to be destroyed
 *
 */


STATUS player_destroy(Player* player) {
  if (!player) {
    return ERROR;
  }

  free(player);

  return OK;
}

/**
 *  @brief Assigns a name to the player
 *
 *  player_set_name Gives the player a name to differentiate it
 *                  from another player
 *
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 *  @param name is the name we're going to assign to the player
 */

STATUS player_set_name(Player* player, char* name) {

  /* This code makes sure a player exists and if it does it has a name */

  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }

  return OK;
}

/**
 *  @brief Assigns a value to the player
 *
 *  player_set_object Makes sure the player exists and it assigns it a value for
 *                    the object if it has it or not
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 *  @param value is the value the player has the object with either a TRUE or a FALSE
 */

STATUS player_set_object(Player* player, BOOL value) {
  if (!player) {
    return ERROR;
  }
  player->object = value;
  return OK;
}

/**
 *  @brief Gets the player's name
 *
 *  player_get_name Is a constant function so it can't be changed.
 *                  Makes sure player exists and gets it's assigned name
 *
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 *  @param name is the player's name
 */

const char * player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}

/**
 *  @brief Returns the player's id
 *
 *  player_get_id   Is a function that assesses whether the player exists and
 *                  it calls the player's structure to get its id
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 *  @param id is the player's id
 */

Id player_get_id(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->id;
}

/**
 *  @brief Confirms the player has the object
 *
 *  player_get_id   Is a function that makes sure the player has been created
 *                  and returns with TRUE or FALSE whether the player has
 *                  the object or not
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 */

BOOL player_get_object(Player* player) {
  if (!player) {
    return FALSE;
  }
  return player->object;
}

/**
 *  @brief Prints the player on screen
 *
 *  player_print   Is a simple function that prints the player on screen with
 *                 its name and id after making sure it exists. It also prints on
 *                 screen wether the player is where it's supposed to be
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 *  @param id is the player's id
 *  @param name is the player's name
 */

STATUS player_print(Player* player) {

  if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);


  if (player_get_object(player)) {
    fprintf(stdout, "---> Object in the player.\n");
  } else {
    fprintf(stdout, "---> No object in the player.\n");
  }

  return OK;
}

/**
 *  @brief Assigns a location to the player
 *
 *  game_set_player_location Is a function that assigns the plauer a location in space
 *                           It calls to Player's structure to set the location
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param palyer is the player we created
 *  @param id is the player's id
 */

STATUS game_set_player_location(Player *player, Id id) {

  if (id == NO_ID) {
    return ERROR;
  }

  player->player_location = id;

    return OK;

}

/**
 *  @brief Returns the player's location
 *
 *  game_get_player_location It calls upon the location set by the game_set_player_location function
 *                           and returns it
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 */

Id game_get_player_location(Player* player) {
  return player->player_location;
}
