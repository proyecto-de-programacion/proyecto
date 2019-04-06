/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   test_game_reader.c
 * Author: Sara
 *
 * Created on 5 de abril de 2019, 17:10
 */

#include <stdio.h>
#include <stdlib.h>
#include "game_reader.h"

/*
 * Simple C Test Suite
 */


void test_game_reader_load_spaces(){
    
    Game *g = NULL;
    game_create(g);
    
    char file_name[10] = "";
    fgets(file_name,10,stdin);
    
    if(game_reader_load_spaces(g,file_name) == ERROR){
        printf("game_reader_load_spaces no superado");
    }else{
        printf("game_reader_load_spaces superado");
    }
}


void test_game_reader_load_objects() {
    
    Game *g = NULL;
    game_create(g);
    
    char file_name[10] = "";
    fgets(file_name,10,stdin);
    
    if(game_reader_load_objects(g,file_name) == ERROR){
        printf("error al leer fichero");
    }else{
        printf("el fichero se leyo correctamente");
    }
    
}

void test_game_reader_load_links(){
    Game *g = NULL;
    game_create(g);
    
    char file_name[10] = "";
    fgets(file_name,10,stdin);
    
    if(game_reader_load_links(g,file_name) == ERROR){
        printf("game_reader_load_links no superado");
    }else{
        printf("game_reader_load_links superado");
    }
}


int main(int argc, char** argv) {
    
   void test_game_reader_load_spaces();
   void test_game_reader_load_objects();
   void test_game_reader_load_spaces();

    return (EXIT_SUCCESS);
}
