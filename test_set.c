/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   test_set.c
 * Author: Sara
 *
 * Created on 5 de abril de 2019, 22:48
 */

#include <stdio.h>
#include <stdlib.h>
#include "set.h"

/*
 * Simple C Test Suite
 */


void test_set_create(){
    if (set_create()!=NULL)!        
             printf("test_set_create superado\n");   
     else
             printf("test_set_create no superado\n");
}

void test_set_destroy(){
    
    Set *s =  set_create(50);
    if(set_create(s) != OK){
        printf("test_set_destroy no superado");
    }else{
        printf("test_set_destroy superado");
    }
}
int main(int argc, char** argv) {
   
    
    void test_set_create();
    void test_set_destroy();
    
    return 0;
}
