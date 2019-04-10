/**
 *  @brief An implementation to use 'die' data type
 *
 *  Here all functions related to 'die' data types are implemented as well as the structure Die
 *
 *  @file die.c
 *  @date 17/03/2019
 *  @authors Catana Sara Erika, Conache Alexandra
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/die.h"


struct _Die {
  Id id;
  int last_roll;
};

/*!< Creates the die and initializes the components and returns the die*/

Die* die_create(Id id){
    
  Die *newDie = NULL;
  
  if (id == NO_ID) return NULL;
  
  newDie = (Die *) malloc(sizeof (Die));

  if (newDie == NULL) {
    return NULL;
  }
  newDie->id = id;
  newDie->last_roll = 0;

  return newDie; 
}

/*!< Desrtoys the dynamic memory made for the die structure */
STATUS die_destroy(Die* die){
    
    if (!die) {
        return ERROR;
    }

    free(die);
    return OK;
}

/*!< Creates a random number from 1 to 6 and returns it */

int die_roll(Die *die){
  

  time_t time_randomizer;

  if (!die){
    return -1;
  }

  srand(time(NULL));

  srand((unsigned) time(&time_randomizer));
  die->last_roll = ((rand()%6)+1);
  
  if(die->last_roll <= 0){
    return -1;
  }

  return die->last_roll;
}



/*!< Prints out the die structure and his elements */

STATUS die_print(Die* die){
  if(!die){
    return ERROR;
  }
  fprintf(stdout,"-->Die ID: %ld | Last Roll: %d\n", die_get_id(die), die_get_lastRoll(die));

  return OK;
}

/*!< Returns the last roll made */

int die_get_lastRoll(Die *d){
  if(!d){
    return -1;
  }
  return d->last_roll;
}
/*!< Returns the id */
Id die_get_id(Die* die){
  if(!die){
    return NO_ID;
  }
  return die->id;
}