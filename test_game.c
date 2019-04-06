/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   test_space.c
 * Author: Sara
 *
 * Created on 5 de abril de 2019, 17:19
 */

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

/*
 * Simple C Test Suite
 */

void test_game_add_spaceError() {
   
    Game* g= NULL;
    Space* s = NULL;
    Id i= 12;
    
    game_create(g);
    
    s= space_create(i);
    
    if (game_add_space(g,s)==ERROR){
        printf ("test_game_add_spaceError no superado");
    }else{
        printf ("test_game_add_spaceError superado");
    }
    
    
}


void test_game_add_spaceOK() {
   
    Game* g= NULL;
    Space* s = NULL;
    Id i= 12;
    
    game_create(g);
    
    s= space_create(i);
    
    if (game_add_space(g,s)==ERROR){
        printf ("test_game_add_spaceOk no superado");
    }else{
        printf ("test_game_add_spaceOk superado");
    }
    
    
}

int main(int argc, char** argv) {
    
    void test_game_add_spaceError();
    void test_game_add_spaceOK();
    
    return (EXIT_SUCCESS);
}
