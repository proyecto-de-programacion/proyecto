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
#include "game.h"
#include "command.h"

int main(int argc, char *argv[]){
    
    Game game;
    Command *command = NULL;
    Graphic_engine *gengine;
    FILE  *file = NULL;
    STATUS result = FALSE;
    Enum_command cmd = NO_CMD;

    if (argc < 2){
        fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]); return 1;
    }

    /* si argc tiene 4 argumentos y el argumento 2 es "-l"*/

    if (argc == 4 && strcmp(argv[2],"-l")==0){/*si son 4 argumentos se quiere log    */
    
        file = fopen(argv[3],"w");
        if(file == NULL){
            return ERROR;
        }else{
            fprintf(file, "Fichero creado \n");
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

    if ((command = command_create()) == NULL){
        fprintf(stderr, "Error while initializing command.\n");
        game_destroy(&game);
        graphic_engine_destroy(gengine);
        return 1;
    }   
    while ((cmd != EXIT) && !game_is_over(&game)){ 

        
        graphic_engine_paint_game(gengine, &game);
        
        command_get_user_input(command);
        result = game_update(&game, command);

        /*  He creado una estructura Enum_command para guardar el valor del cmd
            para saber cuando alguien ha escogido la opcion exit  */
        cmd = command_get_command(command);

        if(result == OK && file != NULL){
            fprintf(file,"%s: OK",(char*)command);
        }
        else if(result==ERROR){
            fprintf(file,"%s: ERROR",(char*)command);
        }
        
    }

    if(file != NULL){
        fclose(file);
    }

    game_destroy(&game);
    graphic_engine_destroy(gengine);
    command_destroy(command);

    return 0;
}
