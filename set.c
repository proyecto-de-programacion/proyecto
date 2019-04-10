#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/set.h"

struct _Set {
    Id  arId[TAM_ID + 1];
    int numArrays;
};


Set* set_create() {
    int i = 0;
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


void set_destroy(Set* set){    
    if (!set) {
        return;
    }

    free(set);   

    return;
}
    
STATUS set_add(Set* set, Id id){
    int i;
    if (id == NO_ID || set == NULL || set_is_full(set)==TRUE){
        return ERROR;
    }

    /* Compruebo que no se repita el id dado*/                                 
    for(i=0; i<TAM_ID; i++){
        if(set->arId[i] == id){
            /* El objeto ya está dentro del array, si salta este error ha salido algo mal */
            return ERROR;
        }
    }
    set->arId[set->numArrays] = id;
    set->numArrays++;
     
    return OK;
     
}


STATUS set_del(Set* set, Id id){
    int i=0,j=0;
    Id id_aux = NO_ID;
    if (id == NO_ID || set == NULL || set_is_empty(set)==TRUE) return ERROR;
   
    

    for(i = 0; i < set->numArrays; i++){
        id_aux = set_get_id(set,i);
        if(id == id_aux){
            for(j=i; j+1 <TAM_ID && set->arId[j] != NO_ID; j++){
                set->arId[j] = set->arId[j+1];
            }
            set->numArrays--;
            return OK;

        }
    }
    return ERROR;

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
	if (!set) return TRUE;
	if(set->numArrays == TAM_ID){
		return TRUE;
	}

	return FALSE;
}

BOOL set_is_empty(Set* set) {
    if (!set) return TRUE;
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

STATUS set_delete_id(Set* set, Id id){
    int i = 0, j = 0;
    Id aux_id = NO_ID;

    if(set == NULL|| id == NO_ID) return ERROR;
    for(i=0; i<set->numArrays;i++){
        aux_id = set_get_id(set,i);
        if(id == aux_id){
            for(j=i; j+1<TAM_ID && set->arId[j] != NO_ID;j++){
                set->arId[j] = set->arId[j+1];
            }
            set->numArrays--;
            return OK;
        }
    }
    return ERROR;
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