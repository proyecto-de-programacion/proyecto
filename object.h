/**
 *  @brief A definition to use 'object' data type
 *
 *  Here all functions related to 'object' data types are defined as well as the structure Object
 *
 *  @file object.h
 *  @version 1.0
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 */
#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

/**
 * Definition of constant values
 */

#define MAX_OBJECTS 4

/**
 * Definition of data structures
 */

typedef struct _Object Object;



/**
 *  Delcaration of public functions
 */

/* It creates an object */
Object* object_create(Id id);

/* It destroyes the memory allocated to the prviously created object, thus destroying it */
STATUS object_destroy(Object* object);

/* It returns the object's id */
Id object_get_id(Object* object);

/* It assigns a name to the object */
STATUS object_set_name(Object* object, char* name);

/* It returns the name assigned to the object */
char* object_get_name(Object* object);

/* It prints the object on screen */
STATUS object_print(Object* object);

/* It tells the game to return the object location ID */
Id     object_get_location(Object* object);

/* It assigns an id to the object in game */
STATUS object_set_location(Object* object, Id id);
#endif
