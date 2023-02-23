#include "list.h"

list newList() {return NULL; }

int isEmpty(list l) {

	return l == NULL;
}

list insert(list l, obj v) {

	if(l == NULL) {
		l = (list)malloc(sizeof(structCell));
		if(l == NULL) {
			printf("erreur malloc\n");
			exit(-1);
		}	
		l->val = v;
		l->next = newList();
		return l;
	}

	list curr = l;

	list new = (list)malloc(sizeof(structCell));
	new->val = v;
	new->next = newList();
	
	while(curr->next != NULL)
		curr = curr->next;

	curr->next = new;
	return l;
}

obj pop(list l) {

	if(isEmpty(l)) {
		return -1;
	}
	return l->val;
}

list removeFirst(list l) {
	list next = l->next;
	if(l != NULL) free(l);
	return next;
}

list removeVal(list l, obj v) {

	list p = l;
    list q = p;

	if(p->val == v) {
		list tmp = p->next;
		free(p);
		return tmp;
	}
    while (p != NULL && p->val != v) 
    {
        q = p;          
        p = p->next;
    }

    if (p->val == v) 
    {
        q->next = p->next;
        free(p);                
    }
    return q; 
}

list search(list l, obj v) {
	list p = l;
	while(p->val != v && !isEmpty(p)) {
		p = p->next;
	}
	return p;
}

void printList(list l) {
	list p = l;
	
	printf("[");
	if(isEmpty(l)) {
		printf("]\n");
		return;
	}
	
	while(!isEmpty(p)) {
		printf(" %d, ", p->val);
		p = p->next;
	}
	printf("]\n");
}

list copyList(list l) {
	list newHead = NULL;
	list curr = l;
	list prev = NULL;

	while(curr != NULL) {
		list newCell = (list)malloc(sizeof(structCell));
		newCell->val = curr->val;
		newCell->next = NULL;

		if(prev == NULL) {
			newHead = newCell;
		} else {
			prev->next = newCell;
		}

		prev = newCell;
		curr = curr->next;
	}

	return newHead;
}

void deleteList(list l) {
	while(!isEmpty(l)) {
		l = removeFirst(l);
	}
}
