/** 
* @brief It defines a textual game reader
* 
* @file game_reader.h
* @author Alexandra Conache
* @version 2.0 
* @date 25/02/2019
*/


#ifndef GAME_READER_H
#define GAME_READER_H

#include "command.h"
#include "game.h"
#include "space.h"
#include "set.h"


/**
 * @author PPROG professors 
 * @brief Reads the file and loads the spaces found
 * 
 * @param Game is where the pointers to "toks" are getting copied
 * @param filename is the name of the file we're using
 * 
 * @return OK or ERROR
 * 
 */ 
STATUS game_reader_load_spaces(Game* game, char* filename);

/**
 * @author Alexandra Conache 
 * @brief Reads the file and loads the objects found
 * 
 * @param Game is where the pointers to "toks" are getting copied
 * @param filename is the name of the file we're using
 * 
 * @return OK or ERROR
 * 
 */ 
STATUS game_reader_load_objects(Game* game, char* filename);
#endif