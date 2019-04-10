/** 
 * @brief It declares the tests for the set module
 * 
 * @file test_set.h
 * @author Sara Erika Catana
 * @version 2.0 
 * @date 08/04/2019
 * @copyright GNU Public License
 */

#ifndef TEST_SET_H
#define TEST_SET_H

/**
 *      @test Tests the create a set function
 *      @pre  Parameter: -
 *      @post Return: non Null pointer set
 */
void test1_set_create();

/**
 *      @test Tests the create a set function
 *      @pre  Parameter: -
 *      @post Return: a NULL pointer set
 */
void test2_set_create();

/**
 *      @test Tests the return the set's id function
 *      @pre  Parameter: the id we assign to the set
 *      @post Return: returns the id assigned
 */
void test1_set_get_id();

/**
 *      @test Tests the return the set's id function
 *      @pre  Parameter: a NULL set
 *      @post Return: return the set's id that is NO_ID 
 */
void test2_set_get_id();

/**
 *      @test 
 *      @pre  Parameter: the id
 *      @post Return: must return OK
 */
void test1_set_add();

/**
 *      @test 
 *      @pre  Parameter: a NULL set pointer
 *      @post Return: must return ERROR
 */
void test2_set_add();

/**
 *      @test 
 *      @pre  Parameter: the id
 *      @post Return: must return OK
 */
void test1_set_del();

/**
 *      @test 
 *      @pre  Parameter: a NULL set pointer
 *      @post Return: must return ERROR
 */
void test2_set_del();

/**
 *      @test 
 *      @pre  Parameter: the id we assign to the set
 *      @post Return: returns the id assigned
 */
void test1_set_is_full();


/**
 *      @test Tests that set is full
 *      @pre  Parameter: a NULL set
 *      @post Return: return the set's id 
 */
void test2_set_is_full();


/**
 *      @test 
 *      @pre  Parameter: the id we assign to the set
 *      @post Return: returns the id assigned
 */
void test1_set_is_empty();


/**
 *      @test test that set is empty
 *      @pre  Parameter: a NULL set
 *      @post Return: return the set's id 
 */
void test2_set_is_empty();

/**
 *      @test 
 *      @pre  Parameter: the id
 *      @post Return: must return OK
 */
void test1_set_Id_inArray();


/**
 *      @test 
 *      @pre  Parameter: a NULL set pointer
 *      @post Return: must return ERROR
 */
void test2_set_Id_inArray();

/**
 *      @test Tests 
 *      @pre  Parameter: the id
 *      @post Return: must return OK
 */
void test1_set_delete_id();


/**
 *      @test Tests that the id is deleted
 *      @pre  Parameter: a NULL set pointer
 *      @post Return: must return ERROR
 */
void test2_set_delete_id();

#endif
