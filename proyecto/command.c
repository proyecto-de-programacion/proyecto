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
  char name[CMD_LENGHT + 1];
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
  return (char *)pc->name;
}

Command *command_setName(Command *pc, const char *name){
  if(!pc || !name){
    return NULL;
  }
  if(!strcpy(pc->name, name)){
    return NULL;
  }
  return pc;
}

Enum_command command_get_command(Command *pc){
  if(!pc){
    return NO_CMD;
  }
  return pc->cmd;
}

void command_setCommand(Command *pc, Enum_command cmd){
  if( !pc ){
    return;
  }
  pc->cmd = cmd;
}

STATUS command_get_user_input(Command *pc){
  
  char input[CMD_LENGHT] = "";
  int i=UNKNOWN - NO_CMD + 1; 
  char *toks = NULL;
  char cmd_name[CMD_LENGHT + 1] = "";

  if(fgets(input,CMD_LENGHT,stdin) != NULL){
    pc->cmd = UNKNOWN; 
    input[strlen(input)-1]='\0';
    toks = strtok(input, " "); 
    strcpy(cmd_name, toks);

    while (pc->cmd == UNKNOWN && i < N_CMD){ 

      if (!strcasecmp(cmd_name, short_cmd_to_str[i],WORD_SIZE) || !strcasecmp(cmd_name, cmd_to_str[i],WORD_SIZE)){
        pc->cmd = i  + NO_CMD;

        if (pc->cmd == PICKUP || pc->cmd == DROP){
          toks= strtok(NULL," ");
          strcpy(pc->name, toks);   
          return OK;         
        }else{
          return OK;
        }
      }
      else {
	      i++;
      }
    }
  }

  return ERROR;
}
