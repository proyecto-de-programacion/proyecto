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

/* !<  Enumeration of the commands and their values  */

typedef enum enum_Command {
  NO_CMD = -1,  
  UNKNOWN,
  EXIT,
  NEXT,
  BACK,
  ROLL,
  LEFT,
  RIGHT,
  PICKUP,
  DROP} T_Command;

/* !< Gets the user input of the commands */
T_Command command_get_user_input();

#endif
