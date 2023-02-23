#ifndef LIST_H
#define LIST_H

#include "common.h"

typedef int obj;

typedef struct cell {
	obj val;
	struct cell *next;
} structCell;

typedef structCell *list;

list newList();

int isEmpty(list l);

list insert(list l, obj v);

obj pop(list l);

list removeFirst(list l);

list removeVal(list l, obj v);

list search(list l, obj v);

void printList(list l);

list copyList(list l);

void deleteList(list l);

#endif
