/** 
 * @brief It defines the game interface
 * for each command
 * 
 * @file game.h
 * @AlexConache y CiroAlonso
 * @version 2.0 
 * @date 17/02/2019
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "types.h"
#include "die.h"

typedef struct _Game{ 
  Player *players;    /* !<  Structure of the Player  */
  Object *objects[MAX_OBJECTS];    /*!< Structure of the Object */
  Die *dice;          /*!< Structure of the Die */
  Space* spaces[MAX_SPACES + 1];    /*!< Array of structures of Space */
  T_Command last_cmd;    /*!< Last command */
} Game;


/* !< Adds space to the game  */
STATUS game_add_space(Game* game, Space* space);

/* !<  Creates the game  */
STATUS game_create(Game* game);

/* !< Creates the game from file  */
STATUS game_create_from_file(Game* game, char* filename);

/* !< Updates the game  */
STATUS game_update(Game* game, T_Command cmd);

/* !< Destroys de memory peviously called  */
STATUS game_destroy(Game* game);

/* !< The game is finished  */
BOOL   game_is_over(Game* game);

/* !<  Doesn't appear in the code for the current moment  */
void   game_print_screen(Game* game);

/* !<  Print out the game  */
void game_print_data(Game* game);

/* !< Returns the last command */
T_Command game_get_last_command(Game* game);

/* !< Returns the id of the space  */
Id game_get_space_id_at(Game* game, int position);

#endif
