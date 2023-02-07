#include "utils.h"

int temps = 0;
int speed = 4;

void update() {
	usleep(1000000 * 1/(speed*4));
	temps++;
	temps %= S_DZ_H;
	glutPostRedisplay();
}

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
	glVertex2i(x+1, y);
	glVertex2i(x+1, y+1);
	glVertex2i(x, y+1);
	glEnd();
	
}



void usage(char *s) {

	printf("usage : %s (<s> <vitesse>) (<heures>) (<minutes>) (<secondes>)\n\tvitesse, heures, minutes et secondes options, valeurs entières\n", s);

	printf("Si pas d'heure donnée, affiche l'heure actuelle avec une vitesse de 4\n");
}
