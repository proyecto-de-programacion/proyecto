/**
 * @brief Tests the die module
 *
 * @file   test_die.c
 * @author Sara Erika Catana
 * @version 1.0
 * @date 08/04/2019
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/die.h"
#include "../include/test_die.h"
#include "../include/test.h"

#define MAX_TESTS 8

int main(int argc, char** argv) {

    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Die:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_die_create();
    if (all || test == 2) test2_die_create();
    if (all || test == 3) test1_die_roll();
    if (all || test == 4) test2_die_roll();
    if (all || test == 5) test1_die_get_lastRoll();
    if (all || test == 6) test2_die_get_lastRoll();
    if (all || test == 7) test1_die_get_id();
    if (all || test == 8) test2_die_get_id();


    PRINT_PASSED_PERCENTAGE;

    return 1;
}
void test1_die_create() {
    Die *d = NULL;
    d = die_create(10);

    PRINT_TEST_RESULT(d != NULL);
    die_destroy(d);
}

void test2_die_create(){
    Die *d = NULL;
    d = die_create (NO_ID);

    PRINT_TEST_RESULT(d == NULL);
}

void test1_die_roll() {
    Die *d = NULL;
    int result;
    d = die_create (6);

    result = die_roll(d);
    PRINT_TEST_RESULT(result > 0 || result < 7);
    die_destroy(d);
}

void test2_die_roll(){
    Die *d = NULL;
    PRINT_TEST_RESULT(die_roll(d) == -1);
}


void test1_die_get_lastRoll(){
    Die *d = NULL;
    int result;
    d = die_create (6);

    result = die_get_lastRoll(d);
    PRINT_TEST_RESULT(result > 0 || result < 7);
    die_destroy(d);
}

void test2_die_get_lastRoll(){
    Die *d = NULL;
    PRINT_TEST_RESULT(die_get_lastRoll(d) == -1);
}

void test1_die_get_id(){
    Die *d;
    d = die_create (12);

    PRINT_TEST_RESULT(die_get_id(d) == 12);
    die_destroy(d);
}

void test2_die_get_id(){
    Die *d = NULL;

    PRINT_TEST_RESULT (die_get_id(d) == NO_ID);
}
