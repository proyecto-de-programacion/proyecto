/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   test_command.c
 * Author: Sara
 *
 * Created on 5 de abril de 2019, 17:30
 */

#include <stdio.h>
#include <stdlib.h>
#include "command.h"

/*
 * Simple C Test Suite
 */


void test_command_create(){
    if (command_create()!=NULL)!        
             printf("test_command_create superado\n");   
     else
             printf("test_command_create no superado\n");
}

void test_command_destroy(){
    
    Command *cmd =  command_create(50);
    if(command_create(cmd) != OK){
        printf("test_command_destroy no superado");
    }else{
        printf("test_command_destroy superado");
    }
}


void test_command_getName (){
    Command *cmd= NULL;
    Id i= 12;
    cmd = command_create(12);
    
  
    char name[10] = "";
    fgets(name,10,stdin);
    command_setName(cmd,name);
    
    char name2[10] = command_getName(cmd);
    
    if (strcmp(name, name2)==0){
        printf ("test_command_getName superado");
    }else{
        printf ("test_command_getName no superado");
    }
}

void test_command_setName() {
    Command * c= NULL;
    c = command_create();
    
    char name[10] = "";
    fgets(name,10,stdin);
    
    Command *c2 =command_setName(c, name);
    if(strcasecmp(command_getName(c2),name) == 0){
        printf("test_command_setName superado");
    }else{
        printf("test_command_setName no superado");
    }
    
}


int main(int argc, char** argv) {
    
    void test_command_create();
    void test_command_destroy ();
    void test_command_getName ();
    void test_command_setName();
    
    return (EXIT_SUCCESS);
}
