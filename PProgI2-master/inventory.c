/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"


struct _Inventory {
  Set *objectsIdentificadores;  
  int maxObjects;
};

Inventory* inventory_create(int maxObjects){
    Inventory *newInventory = NULL;

    
    newInventory = (Inventory *)malloc(sizeof(Inventory));

    if (newInventory == NULL) {
      return NULL;
    }
    
    newInventory->objectsIdentificadores = set_create();
    newInventory->maxObjects = maxObjects;

    return newInventory;
}
STATUS inventory_destroy(Inventory* inventory){
    if (!inventory) {
      return ERROR;
    }
    set_destroy(inventory->objectsIdentificadores);
    free(inventory);
    inventory=NULL;

    return OK;
}

Set * inventory_get_objectsIdentificadores(Inventory* inventory, Id id){
  if (!inventory || id == NO_ID) {
    return ERROR;
  }
  if(set_Id_inArray(inventory->objectsIdentificadores, id)==TRUE){
    set_del(inventory->objectsIdentificadores, id);
    return OK;
  }
  
  return ERROR;
}
int inventory_get_maxObjects(Inventory* inventory){
  if (!inventory) {
    return ERROR;
  }
  return inventory->maxObjects;
    
}

STATUS inventory_set_objetsIdentificadores(Inventory* inventory, Id id){
  if (!inventory || id == NO_ID) {
    return ERROR;
  }
  
  return set_add(inventory->objectsIdentificadores,id);
}
STATUS inventory_set_maxObjects(Inventory* inventory, int maxObjects){
  if (!inventory) {
    return ERROR;
  }
  inventory->maxObjects = maxObjects;
  return OK;
}

STATUS inventory_print(Inventory* inventory){
  
  if (!inventory) {
    return ERROR;
  }

  fprintf(stdout, "--> Inventory \n");
  
  fprintf(stdout, "--> Max objects: %d \n", inventory->maxObjects);
  
  set_print(inventory);

  
  
  return OK;
}