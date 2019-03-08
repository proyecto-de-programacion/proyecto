/**
 * @brief defines the die functions
 *
 * @file die.h
 * @authors Catana Sara Erika & Conache Alexandra
 * @version 1.0
 * @date 23/02/2019
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "types.h"

#define MAX_DIE 7

typedef struct _Die Die;

/* Creates the die and initializes the components and returns the die*/

Die* die_create();

/* Desrtoys the dynamic memory made for the die structure */

STATUS die_destroy(Die* die);

/* Creates a random number from 1 to 6 and returns it */

int die_roll(Die *die);

/* Prints out the die structure and his elements */

STATUS die_print(Die* die);

/* Returns the last roll made */

int die_get_lastRoll(Die *d);
