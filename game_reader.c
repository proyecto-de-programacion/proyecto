/** 
 * @brief It implements the game_reader interface 
 * 
 * @file game_reader.c
 * @author Alexandra Conache
 * @version 3.0 
 * @date 8/03/2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"



/**
*      @brief Reads and loads the spaces 
*                              
*      In charge of reading the positions of the boxes and how the are interconnected                        
*      and load the spaces required from the file
*       
*
*      param: structure Game from file game.h 
*      param: char filename, necessary to load spaces 
*      @date  8/03/2019 
*      @author Alexandra Conache                    
*/

STATUS game_reader_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  char *firstrow = NULL;
  char *secondrow = NULL;
  char *thirdrow = NULL;
  char stringrow[7] = "";
  Id id = NO_ID, 
  north = NO_ID, 
  east = NO_ID, 
  south = NO_ID, 
  west = NO_ID;
  Space* space = NULL;
  STATUS status = OK;
  
  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  /**
 *      What this while does is set where the string read is going to get copied
 *      and it scans the whole file going line by line until it maximum value and 
 *      saves it in "line"
 */ 
  while (fgets(line, WORD_SIZE, file)) {
    /**
     *  The if makes sure the first 3 characters are "#s:" 
     */
    if (strncmp("#s:", line, 3) == 0) {
      /**
       *    Here we cut the string using the character "|"
       *    Here is also where the variables get assigned the right value read from the file
       */
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);

      toks = strtok(NULL, "|");
      north = atol(toks);

      toks = strtok(NULL, "|");
      east = atol(toks);

      toks = strtok(NULL, "|");
      south = atol(toks);

      toks = strtok(NULL, "|");
      west = atol(toks);

      firstrow = strtok(NULL,"|");
      secondrow = strtok(NULL,"|");
      thirdrow = strtok(NULL,"|");

	#ifdef DEBUG 
      	printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
	#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        game_add_space(game, space);
        if(firstrow == NULL){
          space_set_gdesc(space,stringrow,0);
        }
        if(secondrow == NULL){
          space_set_gdesc(space,stringrow,1);
        }
        if(thirdrow == NULL){
          space_set_gdesc(space,stringrow,2);
        }
        game_add_space(game,space);
      }
    }
  }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}

/**
*      @brief Reads and loads the objects 
*                              
*      In charge of reading the positions of the boxes and how the are interconnected                        
*      and load the objects required from the file
*       
*
*      param: structure Game from file game.h 
*      param: char filename, necessary to load objects 
*      @date  8/03/2019 
*      @author Alexandra Conache                    
*/
STATUS game_reader_load_objects(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id object_id = NO_ID;
  Id space_id = NO_ID;
  Object* object = NULL;
  STATUS status = OK;
  
  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  /**
 *      What this while does is set where the string read is going to get copied
 *      and it scans the whole file going line by line until it maximum value and 
 *      saves it in "line"
 */ 
  while (fgets(line, WORD_SIZE, file)) {
    /**
     *  The if makes sure the first 3 characters are "#o:" 
     */
    if (strncmp("#o:", line, 3) == 0) {
      /**
       *    Here we cut the string using the character "|"
       *    Here is also where the variables get assigned the right value read from the file
       */
      toks = strtok(line + 3, "|");
      object_id = atol(toks);
      toks = strtok(NULL,"|");
      strcpy(name,toks);
      toks = strtok(NULL,"|");
      space_id = atol(toks);


	#ifdef DEBUG 
      	printf("Leido: %ld|%s|%ld\n", object_id,name,space_id);
	#endif
      object = object_create(object_id);
        if(object != NULL){
          object_set_name(object,name);
          object_set_location(object,space_id);
        }
      }
    }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}