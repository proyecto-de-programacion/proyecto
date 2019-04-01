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
#include "player.h"
#include "types.h"
#include "die.h"
#include "object.h"

typedef struct _Game Game;




/* !< Adds space to the game  */
STATUS game_add_space(Game* game, Space* space);

/* !<  Creates the game  */
STATUS game_create(Game* game);

/* !< Creates the game from file  */
STATUS game_create_from_file(Game* game, char* filename);

/* !< Updates the game  */
STATUS game_update(Game* game, Command *cmd);

/* !< Destroys de memory peviously called  */
STATUS game_destroy(Game* game);

/* !< The game is finished  */
BOOL   game_is_over(Game* game);

/* !<  Doesn't appear in the code for the current moment  */
void   game_print_screen(Game* game);

/* !<  Print out the game  */
void game_print_data(Game* game);

 /* !<  Get the space the game is reading  */
Space* game_get_space(Game* game, Id id);

/* !< Returns the last command */
Enum_command game_get_last_command(Game* game);

/* !< Returns the id of the space  */
Id game_get_space_id_at(Game* game, int position);

STATUS game_set_player_location(Game* game, Id id);

Id game_get_player_location(Game* game);


/* !< Sets the object to the space of the player  */
STATUS game_space_setObject(Game *game, Id id);

/* !< Deletes the object from the space of the player if found, else return ERROR */
STATUS game_space_getObject(Game *game, Id id);

/* !< Sets the object to the space you want */
STATUS game_setObject_space(Game *game, Id spaceID, Id objectId);

BOOL game_getObject_space(Game *game, Id spaceID, Id objectId);

#endif
