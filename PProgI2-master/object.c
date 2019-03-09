/**
 *  @brief An implementation to use 'object' data type
 *
 *  Here all functions related to 'object' data types are implemented as well as the structure Object
 *
 *  @file object.c
 *  @version 1.0
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"


/**
 *   @brief Object structure
 *
 *   Stores relevant information about the object players use to play the game
 *
 */


struct _Object {
  Id id;                     /*!< The ID the object has assigned */
  Id object_location;        /*!< The specific location the object is in */
  char name[WORD_SIZE + 1];  /*!< The name we can assign to the object */
  BOOL object;               /*!< The way we can assess wether there is an object or not when inquired */
};

/**
 *  @brief Creates the Object
 *
 *  object_create Reserves enough memory to create the object
 *                it assigns it an id, a name and a location
 *                as well as making sure everything is working
 *                properly
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param id is the id the object has assigned and will be used to identify it
 *
 *
 */

Object* object_create() {

  Object *newObject = NULL;

    newObject = (Object *) malloc(sizeof (Object));

    if (newObject == NULL) {
      return NULL;
    }
    newObject->id = NO_ID;

    newObject->name[0] = '\0';

    newObject->object = FALSE;

    newObject->object_location = NO_ID;

    return newObject;
  }

/**
 *  @brief Destroys the object by freeing the allocated memory
 *
 *  object_destroy Frees the memory we reserved with the function object_create
 *                 it also assigns it a NULL value to tie up loose ends
 *                 furthermore it has a control code to prevent possible
 *                 errors
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object the object created that's going to be destroyed
 *
 */


STATUS object_destroy(Object* object) {
    if (!object) {
      return ERROR;
    }

    free(object);

  return OK;
}

/**
 *  @brief Assigns a name to the object
 *
 *  object_set_name Gives the object a name to differentiate it
 *                  from another player's
 *
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object is the object we created
 *  @param name is the name we're going to assign to the object
 */

STATUS object_set_name(Object* object, char* name) {

  /* This code makes sure an object exists and if it does it has a name */

  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }

  return OK;
}


/**
 *  @brief Assigns a value to the object
 *
 *  object_set_object Makes sure the object exists and it assigns it a value
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object is the object we created
 *  @param value is the value the object has it's either a 1 or a 0
 */


STATUS object_set_object(Object* object, BOOL value) {
  if (!object) {
    return ERROR;
  }
  object->object = value;
  return OK;
}


/**
 *  @brief Gets the object's name
 *
 *  object_get_name Is a constant function so it can't be changed.
 *                  Makes sure object exists and gets it's assigned name
 *
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object is the object we created
 *  @param name is the object's name
 */


const char * object_get_name(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->name;
}

/**
 *  @brief Returns the object's id
 *
 *  object_get_id   Is a function that assesses whether the object exists and
 *                  it calls the object's structure to get its id
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object is the object we created
 *  @param id is the object's id
 */


Id object_get_id(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->id;
}

/**
 *  @brief Confirms the object exists
 *
 *  object_get_id   Is a function that makes sure the object has been created
 *                  and it returns it with a TRUE or FALSE
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object is the object we created
 */


BOOL object_get_object(Object* object) {
  if (!object) {
    return FALSE;
  }
  return object->object;
}

/**
 *  @brief Prints the object on screen
 *
 *  object_print   Is a simple function that prints the object on screen with
 *                 its name and id after making sure it exists. It also prints on
 *                 screen wether the object is where it's supposed to be
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object is the object we created
 *  @param id is the object's id
 *  @param name is the object's name
 */


STATUS object_print(Object* object) {

  if (!object) {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);



  if (object_get_object(object)) {
    fprintf(stdout, "---> Object in the object.\n");
  } else {
    fprintf(stdout, "---> No object in the object.\n");
  }

  return OK;
}

/**
 *  @brief Assigns a location to the object
 *
 *  game_set_object_location Is a function that assigns the object a location in space
 *                           It calls to Object's structure to set the location
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object is the object we created
 *  @param id is the object's id
 */

STATUS game_set_object_location(Object *object, Id id) {


  if (id == NO_ID) {
    return ERROR;
  }

  object->object_location = id;

  return OK;
}


/**
 *  @brief Returns the object's location
 *
 *  game_get_object_location It calls upon the location set by the game_set_object_location function
 *                           and returns it
 *
 *  @date 17/02/2019
 *  @authors Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object is the object we created
 */


Id game_get_object_location(Object* object) {
  return object->object_location;
}
