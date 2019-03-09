#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "die.h"

int main(){
    Die *die;

    if(!(die = die_create())){
        printf("No se ha podido hacer la reserva de memoria");
        return -1;
    }
    
    die_roll(die);
   
    die_print(die);
    
    die_destroy(die);
    
    
    
    
    return 0;
}