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
#include "link.h"



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
  char firstrow[7];
  char secondrow[7];
  char thirdrow[7];
  Link * id = NULL;
  Link *north = NULL;
  Link *east = NULL; 
  Link *south = NULL; 
  Link *west = NULL;
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

      toks = strtok(NULL, "|");
      strcpy(firstrow,toks);

      toks = strtok(NULL, "|");
      strcpy(secondrow,toks);

      toks = strtok(NULL, "|");
      strcpy(thirdrow,toks);

      

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
        space_set_gdesc(space,firstrow,0);
        space_set_gdesc(space,secondrow,1);
        space_set_gdesc(space,thirdrow,2);
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
*      @param: structure Game from file game.h 
*      @param: char filename, necessary to load objects 
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
  int num_objects = 0;
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
  while (fgets(line, WORD_SIZE, file)&& num_objects < MAX_OBJECTS) {
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
      space_id = atol(toks);
      toks = strtok(NULL,"|");
      *name = toks[0];


	#ifdef DEBUG 
      	printf("Leido: %ld|%ld|%c\n", object_id,space_id, *name);
	#endif
        object = object_create(object_id);
        if(object != NULL){
          object_set_name(object,name);
          /* Posicionar el objeto donde diga el datat.dat */
          game_setObject_space(game, space_id, object_id);
          object_destroy(object);
        }
        num_objects++;
      }
    }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}


STATUS game_reader_load_links(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id link_id = NO_ID;
  Link * link1 =  NULL;
  Link * link2 =  NULL;
  Link* link = NULL;
  STATE state = DESCONOCIDO;
  
  STATUS status = OK;
  int num_objects = 0;
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
  while (fgets(line, WORD_SIZE, file)&& num_objects < MAX_OBJECTS) {
    /**
     *  The if makes sure the first 3 characters are "#o:" 
     */
    if (strncmp("#l:", line, 3) == 0) {
      /**
       *    Here we cut the string using the character "|"
       *    Here is also where the variables get assigned the right value read from the file
       */
      toks = strtok(line + 3, "|");
      link_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);

      toks = strtok(NULL, "|");
      link1 = link_create(atol(toks));

      toks = strtok(NULL, "|");
      link2 = link_create(atol(toks));

      toks = strtok(NULL, "|");
      state = atol(toks);//revisar como coger la opcion STATE(abierto, cerrado)

      
       link = link_create(link_id);
        if(link != NULL){
          link_set_name(link,name);
          link_set_link1(link, link1->identificador);
          link_set_link2(link, link2->identificador);
          link_set_state(link, state);
          game_add_link(game,link);
        }
      
       
        num_objects++;
      }
    }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}