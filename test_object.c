/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   test_object.c
 * Author: Sara
 *
 * Created on 5 de abril de 2019, 17:47
 */

#include <stdio.h>
#include <stdlib.h>
#include "object.h"

/*
 * Simple C Test Suite
 */
void test_object_create(){
     if (object_create()!=NULL)!        
             printf("test_object_create superado\n");   
     else
             printf("test_object_create no superado\n");
}
void test_object_destroy(){
    
    Object *obj =  object_create(50);
    if(object_create(obj) != OK){
        printf("test_object_destroy no superado");
    }else{
        printf("test_object_destroy superado");
    }
}

void test_object_getname() {
    Object *o1= NULL;
    Id i= 12;
    o1 = object_create(12);
    
    
    char name[10] = "";
    fgets(name,10,stdin);
    object_set_name(o1,name );
    
    char name2[10] = object_get_name(o1);
    
    
    if (strcmp(name, name2)==0){
        printf ("Se ha leido el name correctamente");
    }else{
        printf ("Fallo al leer el name");
    }
}



int main(int argc, char** argv) {
    
    void test_object_create();
    void test_object_destroy()
    void test_object_getname();
    
    
    return (EXIT_SUCCESS);
}
