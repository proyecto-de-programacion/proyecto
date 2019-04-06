/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newsimpletest.c
 * Author: Sara
 *
 * Created on 5 de abril de 2019, 16:29
 */

#include <stdio.h>
#include <stdlib.h>
#include "inventory.h";

/*
 * Simple C Test Suite
 */

void test_inventory_create() {
     if (inventory_create(50)!=NULL)!        
             printf("test_inventory_create superado\n");   
     else
             printf("test1_inventory_create no superado\n");
}

void test_inventory_destroy() {
    Inventory *i1 =  inventory_create(50);
    if(inventory_destroy(i1) != OK){
        printf("test_inventory_destroy no superado");
    }else{
        printf("test_inventory_destroy superado");
    }
}

void test_inventory_getMaxObject(){
    
    Inventory *i1 =  inventory_create(50);
    
    int size = inventory_get_maxObjects(i1);
    if(size==50)
        printf("test_inventory_getMaxObject superado");
    else
        printf("test_inventory_getMaxObject no superado");
    
    
}

void test_inventory_setMaxObjects(){
    Inventory *i1 =  inventory_create(50);
    
    int tam = inventory_get_maxObjects(i1);
    if(tam==50)
        printf("test_inventory_setMaxObjects superado");
    else
        printf("test_inventory_setMaxObjects no superado");
    
}

int main(int argc, char** argv) {
    
    void test_inventory_create();
    void test_inventory_destroy();
    void test_inventory_getMaxObject();
    void test_inventory_setMaxObjects();

    return (EXIT_SUCCESS);
}
