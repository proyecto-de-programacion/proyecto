#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

typedef struct _Set Set;

#define TAM_ID 100


/* Creates the set structure */
Set* set_create();
/* Liberates the dynamic memory made for the set structure */
STATUS set_destroy(Set* set);
/* Add a element to the structure */
STATUS set_add(Set* set,Id id);
/* Deletes a element of the structure */
STATUS set_del(Set* set,Id id);
/* Prints out in the screen the set structure and all of his elements */
STATUS set_print(Set *set);
/* Returns the id of a specitic array position */
Id get_id (Set *set ,int numArrays);
