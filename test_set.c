/**
 * @brief Tests the set module
 * 
 * @file   test_set.c
 * @author Sara Erika Catana
 * @version 1.0
 * @date 08/04/2019
 *   
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/set.h"
#include "../include/test_set.h"
#include "../include/test.h"

#define MAX_TESTS 16

int main(int argc, char** argv) {

    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Set:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_set_create();
    if (all || test == 3) test1_set_get_id();
    if (all || test == 4) test2_set_get_id();
    if (all || test == 5) test1_set_add();
    if (all || test == 6) test2_set_add();
    if (all || test == 7) test1_set_del();
    if (all || test == 8) test2_set_del();
    if (all || test == 9) test1_set_is_full();
    if (all || test == 10) test2_set_is_full();
    if (all || test == 11) test1_set_is_empty();
    if (all || test == 12) test2_set_is_empty();
    if (all || test == 13) test1_set_Id_inArray();
    if (all || test == 14) test2_set_Id_inArray();
    if (all || test == 15) test1_set_delete_id();
    if (all || test == 16) test2_set_delete_id();


    PRINT_PASSED_PERCENTAGE;

    return 1;
}


void test1_set_create(){
    Set *s = NULL;
    s = set_create();
    
    PRINT_TEST_RESULT(s != NULL);
    set_destroy(s);
}


void test1_set_get_id(){
    Set *s = NULL;
    s = set_create ();
    
    set_add(s, 28);
    PRINT_TEST_RESULT(set_get_id(s, 0) == 28);
    set_destroy(s);
}


void test2_set_get_id(){
    Set *s = NULL;
    
    PRINT_TEST_RESULT (set_get_id(s, 2) == NO_ID);
}

void test1_set_add(){
    Set *s = NULL;
    s = set_create ();
    
    PRINT_TEST_RESULT(set_add(s, 21) == OK);
    set_destroy(s);
}

void test2_set_add(){
    Set *s = NULL;
    
    PRINT_TEST_RESULT (set_add(s, 21) == ERROR);

}

void test1_set_del(){
    Set *s = NULL;
    s = set_create();
    
    set_add(s, 21);
    PRINT_TEST_RESULT(set_del(s, 21) == OK);
    set_destroy(s);
}

void test2_set_del(){
    Set *s = NULL;
    
    PRINT_TEST_RESULT (set_del(s, 3) == ERROR);
}

void test3_set_del(){
    Set *s = NULL;
    s = set_create();

    PRINT_TEST_RESULT(set_del(s, 21) == ERROR);
    set_destroy(s);
}

void test1_set_is_full(){
    Set *s = NULL;
    s = set_create ();
    
    PRINT_TEST_RESULT(set_is_full(s) == FALSE);
    set_destroy(s);
}

void test2_set_is_full(){
    Set *s = NULL;
    
    PRINT_TEST_RESULT (set_is_full(s) == TRUE);
}

void test1_set_is_empty(){
    Set *s = NULL;
    s = set_create ();
    
    set_add(s, 21);
    PRINT_TEST_RESULT(set_is_empty(s) == FALSE);
    set_destroy(s);
}

void test2_set_is_empty(){
    Set *s = NULL;
    
    PRINT_TEST_RESULT (set_is_empty(s) == TRUE);
}

void test1_set_Id_inArray(){
    Set *s = NULL;
    s = set_create ();
    
    PRINT_TEST_RESULT(set_Id_inArray(s, 24) == FALSE);
    set_destroy(s);
}

void test2_set_Id_inArray(){
    Set *s = NULL;
    
    PRINT_TEST_RESULT (set_Id_inArray(s, 2) == FALSE);
}

void test1_set_delete_id(){
    Set *s = NULL;
    s = set_create ();
    
    set_add(s, 24);
    PRINT_TEST_RESULT(set_delete_id(s, 24) == OK);
    set_destroy(s);
}

void test2_set_delete_id(){
    Set *s = NULL;
    
    PRINT_TEST_RESULT (set_delete_id(s, 1) == ERROR);
}


