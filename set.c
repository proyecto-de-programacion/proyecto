#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "set.h"

struct _Set {
    Id  arId[TAM_ID];
    int numArrays;
};


Set* set_create() {
    int i=0;
    Set *newSet = NULL;
  
    newSet = (Set *) malloc(sizeof (Set));

    if (newSet == NULL) {
        return NULL;
    }
    for(i=0;i<TAM_ID; i++){
        newSet->arId[i]=NO_ID;
    }
    newSet->numArrays = INIT_VALUE;
    return newSet;
}


STATUS set_destroy(Set* set){    
    if (!set) {
        return ERROR;
    }

    free(set);   

    return OK;
}
    
STATUS set_add(Set* set, Id id){
    if (id == NO_ID){
        return ERROR;
    }
    if(set == NULL){
       return ERROR;
    }
   
    if(set->numArrays == TAM_ID){
      return ERROR;
    }
  
    set->arId[set->numArrays] = id;
    set->numArrays++;
     
    return OK;
     
}


STATUS set_del(Set* set, Id id){
    int i=0,posArray=0;

    if (id == NO_ID)
        return ERROR;
    if(set == NULL){
       return ERROR;
    }
    posArray = set->numArrays;

    for(i=0; i < posArray ; i++){
        if(set->arId[i] == id){   
            if(i==0){
                set->arId[i] = NO_ID;
            }       
           set->arId[i]= set->arId[posArray];
           set->arId[posArray-1] = NO_ID;
           return OK;
        }
    }
   
   return OK;
    
}
    

STATUS set_print(Set *set){
    int i;
    if (!set) {
        return ERROR;
    }

    fprintf(stdout, "--> Set (Number of elements: %ld)\n", (long)set->numArrays);

    for(i=0; i<TAM_ID; i++){
        fprintf(stdout, "-->Set (Id: %ld)\n", (long)set->arId[i]);
    }

    return OK;
}


Id get_id(Set* set, int numArrays){
    Id aux_id = NO_ID;
    if(!set){
        return NO_ID;
    }

    aux_id = set->arId[numArrays];
    if(aux_id==NO_ID){ /* A lo mejor hace falta mejorar el control de errores ya que a lo mejor no hay id en la posicion*/
        return aux_id;
    }
    return aux_id;
}
