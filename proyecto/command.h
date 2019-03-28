/**
 * @brief It implements the command interpreter
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 19-12-2014
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"
/* !<  Enumeration of the commands and their values  */

typedef enum Enum_Command {
  NO_CMD = -1,  
  UNKNOWN,
  EXIT,
  NEXT,
  BACK,
  LEFT,
  RIGHT,
  ROLL,
  PICKUP,
  DROP
  }Enum_command;

typedef struct _Command Command;


/*!< Creates the structure Command */
Command *command_create();

/*!< Destroy the structure Command */
void command_destroy(Command *pc);

/*!< Returns the name of the object selected */
char *command_getName(Command *pc);

/*!< Returns the command we imputed */
Enum_command command_get_command(Command *pc);

/**
*      @brief Gets the user input of the commands
*                              
*      In charge of reading the value of the users input of the commands 
*           
*      @param The character we imput
*      @date  11/03/2019 
*      @authors AlexandraConache & CiroAlonso                       
*/


/*!< Gets the command selected by the player */
Command * command_get_user_input();

#endif