/** 
 * @brief It defines a textual graphic engine
 * 
 * @file graphic_engine.h
 * @author Alexandra Conache && Sara Erika Catana
 * @version 3.0 
 * @date 4/03/2019
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"
#include "screen.h"
#include "game_reader.h"
#include "object.h"
#include "player.h"

typedef struct _Graphic_engine Graphic_engine;

/* !< Creates the graphic part of the game */
Graphic_engine* graphic_engine_create();
/* !<  Destroys the graphics of the game */
void graphic_engine_destroy(Graphic_engine *ge);
/* !< Paints the game in the screen */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
