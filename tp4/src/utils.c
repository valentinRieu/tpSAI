#include "utils.h"


void afficherPixel(int x, int y) {
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x+8, y);
	glVertex2i(x+8, y+8);
	glVertex2i(x, y+8);
	glEnd();
 
}

void usage(char *s) {

	printf("usage : %s <x y>+\n", s);

	printf("Autant de couple <x y> que de points du polygone à remplir\n");
}
