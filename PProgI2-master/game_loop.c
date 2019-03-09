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


if (argc < 2){
fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]); return 1;
}

if (argc == 4 && argv[2]=='-l'){//si son 4 argumentos se quiere log    
    
    file = fopen(argv[3],"w");
    if(file == NULL){
        return ERROR;
    }
}

if (game_create_from_file(&game, argv[1]) == ERROR){
fprintf(stderr, "Error while initializing game.\n"); return 1;
}

if ((gengine = graphic_engine_create()) == NULL){
fprintf(stderr, "Error while initializing graphic engine.\n");
 game_destroy(&game);
 return 1;
}

while ((command != EXIT) && !game_is_over(&game)){ 

graphic_engine_paint_game(gengine, &game);
command = get_user_input();
STATUS result = game_update(&game, command);
fwprintf(file, command+":"+result +"\n");
}
if(file != NULL){
    fclose(file);
}

game_destroy(&game);
graphic_engine_destroy(gengine);

return 0;
}
