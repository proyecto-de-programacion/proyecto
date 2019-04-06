/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   test_graphic_engine.c
 * Author: Sara
 *
 * Created on 5 de abril de 2019, 22:39
 */

#include <stdio.h>
#include <stdlib.h>
#include "graphic_engine.h"

/*
 * Simple C Test Suite
 */

void test_graphic_engine_create(){
    if (graphic_engine_create()!=NULL)!        
             printf("graphic_engine_create superado\n");   
     else
             printf("graphic_engine_create no superado\n");
}

void test_graphic_engine_destroy(){
    
    Graphic_engine *ge =  graphic_engine_create(50);
    if(graphic_engine_create(ge) != OK){
        printf("test_graphic_engine_destroy no superado");
    }else{
        printf("test_graphic_engine_destroy superado");
    }
}
 

int main(int argc, char** argv) {
    
    void test_graphic_engine_create();
    void test_graphic_engine_destroy();
    
    return (EXIT_SUCCESS);
}
