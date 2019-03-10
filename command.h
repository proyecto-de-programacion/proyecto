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

typedef enum enum_Command {
  NO_CMD = -2,  
  UNKNOWN,
  EXIT,
  NEXT,
  BACK,
  ROLL,
  LEFT,
  RIGHT,
  PICKUP,
  DROP} T_Command;

typedef struct _Command Command;


/* !< Gets the user input of the commands */
T_Command command_get_user_input();
/*
Command* command_create();
void command_destroy(Command *com);
char* command_get_symbol(Command *com);
*/

#endif
