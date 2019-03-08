#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "set.h"

struct _Set {
    Id *arId[TAM_ID];
    int numArrays;
};


Set* set_create() {
    int i;
    Set *newSet = NULL;
  
    newSet = (Set *) malloc(sizeof (Set));

    if (newSet == NULL) {
        return NULL;
    }
    for(i=0;i<TAM_ID; i++){
        newSet->arId[i]=NO_ID;
    }

    return newSet;
}


STATUS set_destroy(Set* conjunto){    
    if (!conjunto) {
        return ERROR;
    }

    free(conjunto);   

    return OK;
}
    
STATUS set_add(Set* conjunto, Id id){
    if (id == NO_ID){
        return ERROR;
    }
    if(conjunto == NULL){
       return ERROR;
    }
   
    if(conjunto->numArrays == TAM_ID){
      return ERROR;
    }
  
    conjunto->arId[conjunto->numArrays] = id;
    conjunto->numArrays++;
     
    return OK;
     
}


STATUS set_del(Set* conjunto, Id id){

    if (id == NO_ID)
        return ERROR;
    if(conjunto == NULL){
       return ERROR;
    }
    int i,j, posArray;

    posArray = conjunto->numArrays;

    for(i=0; i < posArray ; i++){
        if(conjunto->arId[i] == id){          
            for(j=i; j < posArray; j++){
               conjunto->arId[j] = conjunto->arId[j+1];
            }
            conjunto->numArrays--;
        }
    }
   
   return OK;
    
}
    

STATUS set_print(Set *set){
    int i;
    if (!set) {
        return ERROR;
    }

    fprintf(stdout, "--> Set (Number of elements: %ld)\n", set->numArrays);

    for(i=0; i<TAM_ID; i++){
        fprintf(stdout, "-->Set (Id: %ld)\n", set->arId[i]);
    }

    return OK;
}






