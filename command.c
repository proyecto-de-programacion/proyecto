/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 19-12-2014
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "command.h"

#define CMD_LENGHT 30
#define N_CMD 10

struct _Command{
  T_Command cmd;
  char symbol[2];
};


char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Next", "Back", "Roll","Left","Right","Pickup", "Drop"};
char *short_cmd_to_str[N_CMD] = {"","","e","n","b","rl","l","r","p","d"};



/**
*      @brief Gets the user input of the commands
*                              
*      In charge of reading the value of the users input of the commands 
*           
* 
*      @date  17/02/2019 
*      @AlexConache & CiroAlonso                       
*/


T_Command command_get_user_input(){
      T_Command cmd = NO_CMD;
      char input[CMD_LENGHT] = "";
      int i=UNKNOWN - NO_CMD + 1;

      if (scanf("%s", input) > 0){
        cmd = UNKNOWN;
          while(cmd == UNKNOWN && i < N_CMD){
              if (!strcasecmp(input,short_cmd_to_str[i]) || !strcasecmp(input,cmd_to_str[i])){
                cmd = i + NO_CMD;
              }
              else{
	              i++;
              }
          }
      }
  return cmd;
}
/*
Command* command_create(){
  Command* newComm;

  newComm = (Command*)malloc(sizeof(Command));
  if(!newComm){
    return NULL;
  }

  newComm->cmd = UNKNOWN;
  newComm->symbol[0]='\0';
  return newComm;
}

void command_destroy(Command* com){
  if(!com){
    return;
  }

  free(com);
  return;
}

char* command_get_symbol(Command *com){
  if(!com){
    return '\0';
  }
  return com->symbol;

}
*/