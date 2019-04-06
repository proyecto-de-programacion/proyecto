/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   test_link.c
 * Author: Sara
 *
 * Created on 5 de abril de 2019, 22:21
 */

#include <stdio.h>
#include <stdlib.h>
#include "link.h"

/*
 * Simple C Test Suite
 */

void test_link_create () {
    if (link_create(50)!=NULL)!        
             printf("test_link_create superado\n");   
     else
             printf("test1_link_create no superado\n");
}


void test_link_destroy() {
    Link *lk =  link_create(50);
    if(link_destroy(lk) != OK){
        printf("test_link_destroy no superado");
    }else{
        printf("test_link_destroy superado");
    }
}

int main(int argc, char** argv) {
    
    void test_link_create ();
    void test_link_destroy();
    return (EXIT_SUCCESS);
}
