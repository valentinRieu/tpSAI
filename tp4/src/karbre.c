#include "karbre.h"

karbre kArbreVide() {
	return NULL;
}

karbre kConsArbre(int n, element e,...) {

	if(n != K) return NULL;
	
	karbre a = malloc(sizeof(struct s_karbre));
	a->children = malloc(n * sizeof(karbre));
	a->e = e;
	
	va_list ap;
	int i;

	va_start(ap, n);

	for(i = 0; i < n; i++) {
		a->children[i] = va_arg(ap, karbre);
	}
	va_end(ap);
	
	return a;
}

karbre kFils(int ieme, karbre a) {
	if(ieme >= K || a == NULL) return NULL;

	return a->children[ieme];
}


element kRacine(karbre a) {
	if(a == NULL) exit(0);
	
	return a->e;
}

int kEstVide(karbre a) {
	return (a == NULL || a->e.stat == VIDE);
}

void kAfficher(karbre a) {

}

void kDestroy(karbre a) {

}
