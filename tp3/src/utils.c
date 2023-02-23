#include "utils.h"


void afficherPixel(int x, int y) {
	glBegin(GL_QUADS);
	glVertex2f(x - 0.5, y - 0.5);
	glVertex2f(x+0.5, y - 0.5);
	glVertex2f(x+0.5, y+0.5);
	glVertex2f(x - 0.5, y+0.5);
	glEnd();
 
}

void usage(char *s) {

	printf("usage : %s <x y>+\n", s);

	printf("Autant de couple <x y> que de points du polygone à remplir\n");
}
