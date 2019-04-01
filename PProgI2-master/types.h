/**
 * @brief It defines common types
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H
/**
 * Definition of constant values
 */
#define WORD_SIZE 1000
#define NO_ID -1
#define INIT_VALUE 0


/**
 * Definition of data id
 */

typedef long Id;

/**
 * Definition of data enumerations
 */

typedef enum {
  FALSE, TRUE
} BOOL;

typedef enum {
  ERROR, OK
} STATUS;

typedef enum {
  N, S, E, W
} DIRECTION;

typedef enum{
  ABIERTO, CERRADO,UNKNOWN
} STATE;

#endif
