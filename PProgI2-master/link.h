/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#ifndef LINK_H
#define LINK_H

#include "types.h"
#include "set.h"

typedef struct _Link Link;


Link* link_create(Id id);
STATUS link_destroy(Link* link);

Id link_get_id(Link* link);
Id link_get_link1(Link* link);
Id link_get_link2(Link* link);
const char * link_get_name(Link* link);
STATE link_get_state(Link* link);


STATUS link_set_name(Link* link, char* name);
STATUS link_set_link1(Link* link, Id id) ;
STATUS link_set_link2(Link* link, Id id);
STATUS link_set_state(Link* link, STATE state);
STATUS link_print(Link* link) ;

#endif /* LINK_H */

