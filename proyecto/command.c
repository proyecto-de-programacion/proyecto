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
#include <string.h>
#include <stdlib.h>
#include "command.h"

#define CMD_LENGHT 30
#define N_CMD 10

struct _Command{
  Enum_command cmd;
  char name[WORD_SIZE + 1];
};


char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Next", "Back", "Roll","Left","Right","Pickup", "Drop"};
char *short_cmd_to_str[N_CMD] = {"","","e","n","b","rl","l","r","p","d"};

Command *command_create(){
  Command *aux = NULL;

  aux = (Command *)malloc(sizeof(Command));
  if(!aux){
    return NULL;
  }

  aux->cmd = NO_CMD;

  return aux;
}

void command_destroy(Command *pc){
  if(!pc){
    return;
  }
  free(pc);
}

char *command_getName(Command *pc){
  if(!pc){
    return NULL;
  }
  return pc->name;
}

Enum_command command_get_command(Command *pc){
  if(!pc){
    return NO_CMD;
  }
  return pc->cmd;
}


Command *command_get_user_input(){
  Command *pc = NULL;
  char input[CMD_LENGHT] = "";
  int i=UNKNOWN - NO_CMD + 1; 
  char *toks = NULL;
  char cmd_name[CMD_LENGHT + 1] = "";

  pc = command_create();
  
  if(fgets(input,sizeof(input),stdin) != NULL){
    pc->cmd = UNKNOWN; 
    input[strlen(input)-1]='\0';
    toks = strtok(input, " "); 
    strcpy(cmd_name, toks);

    while (pc->cmd == UNKNOWN && i < N_CMD){ 

      if (!strncmp(cmd_name, short_cmd_to_str[i],WORD_SIZE) || !strncmp(cmd_name, cmd_to_str[i],WORD_SIZE)){
        pc->cmd = i  + NO_CMD;
        /*   *(pc->name) = strtok(NULL, " "); */

        if(pc->name==NULL){
          if (pc->cmd == PICKUP || pc->cmd == DROP){
            pc->cmd = UNKNOWN;
            return pc;
          }
        }
        else{
          if (pc->cmd == PICKUP || pc->cmd == DROP){
            strcpy(pc->name, input);   
            return pc;         
          }
          else{
            pc->cmd = UNKNOWN;
            return pc;
          }
        }
      }
      else {
	      i++;
      }
    }
  }

  return pc;
}
