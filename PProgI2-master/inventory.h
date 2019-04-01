/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   inventory.h
 * Author: Sara
 *
 * Created on 31 de marzo de 2019, 11:00
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"
#include "set.h"

typedef struct _Inventory Inventory;


Inventory* inventory_create(int maxObjects);
STATUS inventory_destroy(Inventory* inventory);

Set * inventory_get_objectsIdentificadores(Inventory* inventory, Id id);
int inventory_get_maxObjects(Inventory* inventory);

STATUS inventory_set_objetsIdentificadores(Inventory* inventory, Id id);
STATUS inventory_set_maxObjects(Inventory* inventory, int maxObjects);

STATUS inventory_print(Inventory* inventory);

#endif /* INVENTORY_H */

