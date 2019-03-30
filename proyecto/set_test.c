#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "set.h"

int main(){
    Set *set;
    Set *music;
    Set *chill;

    if(!(set = set_create())){
        printf("No se ha podido hacer la reserva de memoria");
        return -1;
    }
    if(!(music = set_create())){
        printf("No se ha podido hacer la reserva de memoria");
        set_destroy(set);
        return -1;
    }

    if(set_add(chill , 32)==ERROR){
        printf("No existe dicha estructura. xory");
    }
    
    return 0;
}