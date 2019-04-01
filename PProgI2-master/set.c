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
  
    newSet = (Set *) malloc(sizeof (Set)+1);

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
    int i;
    if (id == NO_ID || set == NULL){
        return ERROR;
    }

    if(set->numArrays == TAM_ID-1){
      return ERROR;
    }
    /* Compruebo que no se repita el id dado (cuestion= se puede devolver OK ya que el objeto 
     *ya esta dentro del array)                                      */
    for(i=0; i<TAM_ID; i++){
        if(set->arId[i]== id){
            return OK;
        }
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
        }else{
            return ERROR;
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


Id set_get_id(Set* set, int position){
    
    if(!set){
        return NO_ID;
    }

    return set->arId[position];
}
BOOL set_is_full(Set* set) {
	
	if(set->numArrays == TAM_ID){
		return TRUE;
	}

	return FALSE;
}

BOOL set_is_empty(Set* set) {
	if(set->numArrays == 0) return TRUE;
	else return FALSE;
}

BOOL set_Id_inArray(Set *set, Id id){
    int i;
    if(!set){
        return FALSE;
    }
    for(i=0; i<TAM_ID; i++){
        if(set->arId[i]==id){
            return TRUE;
        }
    }
    return FALSE;
}

/* Hace una copia de la estructura Set y te devuelve una nueva creada con la misma informacion */
Set *set_copy(Set *ps){
    int i = 0;
    Set *pAux = NULL;
    if(!ps){
        return NULL;
    }

    pAux = set_create();
    if(!pAux){
        return NULL;
    }

    for(i=0 ; i < ps->numArrays ; i++){
        if(set_add(pAux, ps->arId[i])==ERROR){
            set_destroy(ps);
            return NULL;
        }
    }
    return pAux;
}