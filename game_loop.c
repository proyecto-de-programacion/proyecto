/** 
 * @brief It defines the game loop 
 * 
 * @file game_loop.c
 * @AlexConache y CiroAlonso
 * @version 2.0 
 * @date 17/02/2019
 */

#include <stdio.h>
#include <stdlib.h>
#include "graphic_engine.h"

int main(int argc, char *argv[]){
    
Game game;
T_Command command = NO_CMD;
Graphic_engine *gengine;
FILE*  file = NULL;
STATUS result = FALSE;
    
   /**
    * se modifica los parametros de entrada para simular el lanzamiento con el netbeans 
    * una vez finalizadas las pruebas borrar todas las lineas
    
        argv[1]="data.dat"; 
        argv[2]="-l";
        argv[3]="log.txt"; 
        argc= 4;
    */



if (argc < 2){
fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]); return 1;
}

/* si argc tiene 4 argumentos y el argumento 2 es "-l"*/

if (argc == 4 && strcmp(argv[2],"-l")==0){/*si son 4 argumentos se quiere log    */
    
    file = fopen(argv[3],"w");
    if(file == NULL){
        return ERROR;
    }else{
        /*fprintf(file, "Fichero creado \n");*/
    }
}

if(game_create_from_file(&game, argv[1]) == ERROR){
    fprintf(stderr, "Error while initializing game.\n"); 
    game_destroy(&game);
    return 1;
}

if ((gengine = graphic_engine_create()) == NULL){
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(&game);
    return 1;
}

while ((command != EXIT) && !game_is_over(&game)){ 

    graphic_engine_paint_game(gengine, &game);
    command = command_get_user_input();
    result = game_update(&game, command);

        if(result == OK){
            if(command == NEXT){
                fprintf(file, "NEXT:OK \n");
            }else if(command == NO_CMD){
                fprintf(file, "NO COMMAND:OK \n"); 
            }else if(command == UNKNOWN){
                fprintf(file, "UNKNOWN:OK \n"); 
            }else if(command == EXIT){
                fprintf(file, "EXIT:OK \n"); 
            }else if(command == BACK ){
                fprintf(file, "BACK:OK \n"); 
            }else if(command == ROLL ){
                fprintf(file, "ROLL:OK \n"); 
            }else if(command == LEFT ){
                fprintf(file, "LEFT:OK \n"); 
            }else if(command == RIGHT ){
                fprintf(file, "RIGHT:OK \n"); 
            }else if(command == BACK ){
                fprintf(file, "BACK:OK \n"); 
            }else if(command == PICKUP ){
                fprintf(file, "PICKUP:OK \n"); 
            }else if(command == DROP ){
                fprintf(file, "DROP:OK \n"); 
            }
        
        }else{
        if(command == NEXT){
                fprintf(file, "NEXT:ERROR \n");
            }else if(command == NO_CMD){
                fprintf(file, "NO COMMAND:ERROR \n"); 
            }else if(command == UNKNOWN){
                fprintf(file, "UNKNOWN:ERROR \n"); 
            }else if(command == EXIT){
                fprintf(file, "EXIT:ERROR \n"); 
            }else if(command == BACK){
                fprintf(file, "BACK:ERROR \n"); 
            }else if(command == ROLL){
                fprintf(file, "ROLL:ERROR \n"); 
            }else if(command == LEFT){
                fprintf(file, "LEFT:ERROR \n"); 
            }else if(command == RIGHT){
                fprintf(file, "RIGHT:ERROR \n"); 
            }else if(command == DROP){
                fprintf(file, "DROP:ERROR \n"); 
            }
        }
}
if(file != NULL){
    fclose(file);
}

game_destroy(&game);
graphic_engine_destroy(gengine);

return 0;
}
