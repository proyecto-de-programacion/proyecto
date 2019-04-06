/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   test_die.c
 * Author: Sara
 *
 * Created on 5 de abril de 2019, 17:02
 */

#include <stdio.h>
#include <stdlib.h>
#include "die.h"

/*
 * Simple C Test Suite
 */

void test_die_create() {
   if (die_create()!=NULL)!        
             printf("test_die_create superado\n");   
     else
             printf("test_die_create no superado\n");
}

void test_die_destroy(){
    Die *d =  die_create(50);
    if(die_create(d) != OK){
        printf("test_die_destroy no superado");
    }else{
        printf("test_die_destroy superado");
    }
}

void test_Die_Roll() {
    Die *d= die_create();
    int num = die_roll(d);
    if(num != -1){
        printf("test_die_roll superado");
    }else{
        printf("test_die_roll no superado");
    }
}

int main(int argc, char** argv) {
    
    void test_die_create();
    void test_Die_Roll();
    
    
    return (EXIT_SUCCESS);
}
