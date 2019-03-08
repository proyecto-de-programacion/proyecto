/** 
 * @brief It defines a textual graphic engine
 * 
 * @file graphic_engine.h
 * @AlexConache y CiroAlonso
 * @version 2.0 
 * @date 17/02/2019
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;

/* !< Creates the graphic part of the game */
Graphic_engine* graphic_engine_create();
/* !<  Destroys the graphics of the game */
void graphic_engine_destroy(Graphic_engine *ge);
/* !< Paints the game in the screen */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);


#endif
