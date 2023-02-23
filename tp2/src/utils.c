#include "utils.h"

void afficherGrille() {
	glBegin(GL_LINES);
	for(float i = X_MIN + 0.5; i < X_MAX; i++) {
		for(float j = Y_MIN + 0.5; j < Y_MAX; j++) {
			/* affichage lignes verticales */
			glVertex2f(i, Y_MIN);
			glVertex2f(i, Y_MAX);

			/* affichage lignes horizontales */

			glVertex2f(X_MIN, j);
			glVertex2f(X_MAX, j);
		}
	}
	glEnd();
}


void afficherPixel(int x, int y) {
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x+8, y);
	glVertex2i(x+8, y+8);
	glVertex2i(x, y+8);
	glEnd();
 
}


void afficherPixelPoint(point p) {
	glBegin(GL_QUADS);
	glVertex2i(p.x, p.y);
	glVertex2i(p.x+8, p.y);
	glVertex2i(p.x+8, p.y+8);
	glVertex2i(p.x, p.y+8);
	glEnd();
	
}


void afficherPoly(point *points, int nbPoints) {

	for(int i = 0; i < nbPoints; i++) {
		
		bresenham(points[i].x, points[i].y, points[(i+1) % nbPoints].x, points[(i+1) % nbPoints].y);
	}
}


void usage(char *s) {

	printf("usage : %s <x y>+\n", s);

	printf("Autant de couple <x y> que de points du polygone à remplir\n");
}
