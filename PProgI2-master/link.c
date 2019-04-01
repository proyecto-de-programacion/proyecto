
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"


struct _Link {
    Id identificador;
    char name[WORD_SIZE + 1];
    Id link1;
    Id link2;
    STATE state;
};

Link* link_create(Id id){
    Link *newLink = NULL;

    if (id == NO_ID)
    return NULL;
    
    newLink = (Link *)malloc(sizeof(Link));

    if (newLink == NULL) {
      return NULL;
    }
    
    newLink->identificador = id;
    newLink->name[0] = '\0';
    newLink->link1= NO_ID;
    newLink->link2= NO_ID;
    newLink->state= STATE.DESCONOCIDO;
    
    return newLink;
}
STATUS link_destroy(Link* link){
    if (!link) {
      return ERROR;
    }
    free(link);
    link=NULL;

    return OK;
}

Id link_get_id(Link* link) {
  if (!link) {
    return NO_ID;
  }
  return link->identificador;
}
Id link_get_link1(Link* link) {
  if (!link) {
    return NO_ID;
  }
  return link->link1;
}

Id link_get_link2(Link* link) {
  if (!link) {
    return NO_ID;
  }
  return link->link2;
}

const char * link_get_name(Link* link) {
  if (!link) {
    return NULL;
  }
  return link->name;
}
STATE link_get_state(Link* link) {
  if (!link) {
    return UNKNOWN;
  }
  return link->state;
}

STATUS link_set_name(Link* link, char* name) {

  /* This code makes sure a player exists and if it does it has a name */

  if (!link || !name) {
    return ERROR;
  }

  if (!strcpy(link->name, name)) {
    return ERROR;
  }

  return OK;
}

STATUS link_set_link1(Link* link, Id id) {
  if (!link || id == NO_ID) {
    return ERROR;
  }
  link->link1 = id;
  return OK;
}

STATUS link_set_link2(Link* link, Id id) {
  if (!link || id == NO_ID) {
    return ERROR;
  }
  link->link2 = id;
  return OK;
}

STATUS link_set_state(Link* link, STATE state) {
  if (!state || state == UNKNOWN) {
    return ERROR;
  }
  link->state = state;
  return OK;
}

STATUS link_print(Link* link) {

  if (!link) {
    return ERROR;
  }

  fprintf(stdout, "--> Link (Id: %ld; Name: %s)\n", link->identificador, link->name);

  
  fprintf(stdout, "---> Link 1: %ld.\n", link->link1);
  fprintf(stdout, "---> Link 2: %ld.\n", link->link2);
  fprintf(stdout, "---> STATE: %ld.\n", link->state);
  return OK;
}

