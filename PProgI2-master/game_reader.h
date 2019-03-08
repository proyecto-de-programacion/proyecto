/** 
* @brief It defines a textual game reader
* 
* @file game_reader.h
* @AlexConache y CiroAlonso
* @version 1.0 
* @date 17/02/2019
*/


#ifndef GAME_READER_H
#define GAME_READER_H

#include "command.h"
#include "game.h"
/* !<  Reads and loads the spaces  */
STATUS game_reader_load_spaces(Game* game, char* filename);
 /* !<  Get the space he is reading  */
Space* game_reader_get_space(Game* game, Id id);
 
#endif