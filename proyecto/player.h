/**
 *  @brief A definition to use 'player' data type
 *
 *  Here all functions related to 'player' data types are defined as well as the structure Object
 *
 *  @file player.h
 *  @version 1.0
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "space.h"
#include "object.h"

/**
 * Definition of constant values
 */

#define MAX_PLAYERS 4

/**
 * Definition of data structures
 */

typedef struct _Player Player;

/**
 *  Delcaration of public functions
 */

 /* It creates a player */
Player* player_create();

/* It destroyes the memory allocated to the previously created player, thus destroying it */
STATUS player_destroy(Player* player);

/* It returns the player's id */
Id player_get_id(Player* player);

/* It assigns a name to the player */
STATUS player_set_name(Player* player, char* name);

/* It returns the name assigned to the player */
const char* player_get_name(Player* player);

/* It makes sure the player has an object and has no errors */
STATUS player_set_object(Player* player, Id id);

/* It returns the result of the inquiry if the player has indeed an object */
Set* player_get_object(Player* player);

/* It prints the player on screen */
STATUS player_print(Player* player);

/* It tells the game to return the player location ID */
Id player_get_location(Player* player);

STATUS player_drop_object(Player* player,Id id);

/* It assigns an id to the player in game */
STATUS player_set_location(Player* player, Id id);
#endif
