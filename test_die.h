/** 
 * @brief It declares the tests for the set module
 * 
 * @file test_die.h
 * @author Sara Erika Catana
 * @version 2.0 
 * @date 08/04/2019
 * @copyright GNU Public License
 */

#ifndef TEST_DIE_H
#define TEST_DIE_H

/**
 *      @test   Tests the die creation function
 *      @pre    Parameter: -
 *      @post   Return:  non Null pointer die
 */
void test1_die_create();

/**
 *      @test   Tests the die creation function
 *      @pre    Parameter: -
 *      @post   Return: a Null pointer die
 */
void test2_die_create();

/**
 *      @test Tests the return the die's last roll function
 *      @pre  Parameter: a NULL die pointer
 *      @post Return: returns the last roll
 */
void test1_die_roll();

/**
 *      @test Tests the return the die's last roll function
 *      @pre  Parameter: a NULL die
 *      @post Return: return the die's last roll  
 */
void test2_die_roll();

/**
 *      @test Tests the return the die's get last roll function
 *      @pre  Parameter: a NULL die pointer
 *      @post Return: returns the last roll
 */
void test1_die_get_lastRoll();

/**
 *      @test Tests the return the die's get last roll function
 *      @pre  Parameter: a NULL die
 *      @post Return: return the die's last roll 
 */
void test2_die_get_lastRoll();

/**
 *      @test   Tests the return the die's id function
 *      @pre    Parameter: an Id
 *      @post   Return: die's id is the one we inputed
 */
void test1_die_get_id();

/**
 *      @test   Tests the return the die's id function
 *      @pre    Parameter: a NULL die
 *      @post   Return: the die has NO_ID assigned
 */
void test2_die_get_id();


#endif
