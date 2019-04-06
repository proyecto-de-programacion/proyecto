/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   test_space.c
 * Author: Sara
 *
 * Created on 5 de abril de 2019, 22:51
 */

#include <stdio.h>
#include <stdlib.h>
#include "space.h"

/*
 * Simple C Test Suite
 */

void test_space_create(){
    if (space_create()!=NULL)!        
             printf("test_space_create superado\n");   
     else
             printf("test_space_create no superado\n");
}

void test_space_destroy(){
    
    Space *s =  space_create(50);
    if(space_create(s) != OK){
        printf("test_space_destroy no superado");
    }else{
        printf("test_space_destroy superado");
    }
}

int main(int argc, char** argv) {
   
    void test_space_create();
    void test_space_destroy();
    
    
    return (EXIT_SUCCESS);
}
