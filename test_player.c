/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   test_player.c
 * Author: Sara
 *
 * Created on 5 de abril de 2019, 22:43
 */

#include <stdio.h>
#include <stdlib.h>
#include "player.h"

/*
 * Simple C Test Suite
 */

void test_player_create(){
    if (player_create()!=NULL)!        
             printf("test_player_create superado\n");   
     else
             printf("test_player_create no superado\n");
}


void test_player_destroy(){
    
    Player *p =  player_create(50);
    if(player_create(p) != OK){
        printf("test_player_destroy no superado");
    }else{
        printf("test_player_destroy superado");
    }
}


int main(int argc, char** argv) {
    
    void test_player_create();
    void test_command_destroy();
    
    
    return (EXIT_SUCCESS);
}
