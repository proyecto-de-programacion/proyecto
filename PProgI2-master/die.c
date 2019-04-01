#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "die.h"
#include "types.h"


struct _Die {
    Id id;
    int last_roll;
};

/**
 *  @brief Creates a die
 *
 *  die_create     Reserves enough memory to create the die and assigns it an ID
 *
 *  @date 23/02/2019
 *  @authors Catana Sara Erika
 *
 *  @param id is the id assigned to the die so it can be identified
 *
 */

Die* die_create(){
    
   Die *newDie = NULL;
  
  newDie = (Die *) malloc(sizeof (Die));

  if (newDie == NULL) {
    return NULL;
  }
  newDie->id =NO_ID;
  newDie->last_roll = 0;

  return newDie; 
    
    
}

/**
 *  @brief Destroys the die by freeing the allocated memory
 *
 *  die_destroy    Frees the memory we reserved with the function die_create
 *                 it also assigns it a NULL value to tie up loose ends
 *                 furthermore it has a control code to prevent possible
 *                 errors
 *
 *  @date 23/02/2019
 *  @authors Catana Sara Erika
 *
 *  @param die the die created that's going to be destroyed
 *
 */
STATUS die_destroy(Die* die){
    
    if (!die) {
        return ERROR;
      }

    free(die);

    return OK;
    
}

/**
 *  @brief Rolls the die
 *
 *  die_roll        It randomly generates a value between 1 and 6 for the die
 *
 *  @date 23/02/2019
 *  @authors Conache Alexandra
 *
 *  @param die the die created that we're going to roll
 *
 */

int die_roll(Die *die){
  time_t time_randomizer;
  int random;

  if (!die){
    return -1;
  }

  srand(time(NULL));

  srand((unsigned) time(&time_randomizer));
  random = ((rand()%6)+1);
  
  if(random == 0){
    return -1;
  }

  return random;
}



/**
 *  @brief Prints the values the die rolled
 *
 *  die_print      Prints on screen the value the die rolled
 *
 *  @date 23/02/2019
 *  @authors Conache Alexandra
 *
 *  @param die the die value that's going to be printed
 *
 */

STATUS die_print(Die* die){
  if(!die){
    return ERROR;
  }
  fprintf(stdout,"-->Die ID: %ld | Last Roll: %d\n", die_get_id(die), die_get_lastRoll(die));

  return OK;
}

/**
 *  @brief Prints the values the die rolled
 *
 *  die_get_lastRoll   Prints on screen the value the die last_rolled
 *
 *  @date 23/02/2019
 *  @authors Conache Alexandra
 *
 *  @param die the die created that's going to be destroyed
 *
 */

int die_get_lastRoll(Die *d){
  if(!d){
    return -1;
  }
  return d->last_roll;
}

Id die_get_id(Die* die){
  if(!die){
    return NO_ID;
  }
  return die->id;
}