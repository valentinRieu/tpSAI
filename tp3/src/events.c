#include "events.h"

int pixels[NP][2] = {0};


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(X_MIN, X_MAX, Y_MIN, Y_MAX, 0, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	printf("nb de pixels : %d\n", pixels[0][0]);

	if(pixels[0][0] == 1) {
		afficherPixel(pixels[1][0], pixels[1][1]);
	}


	for(int i = 0; i < X_MAX; i+=2) {

		afficherPixel(i, 10);
	}
	for(int i = 2; i <= pixels[0][0]; i++) {
		
		int x1 = pixels[i-1][0], x2  = pixels[i][0];
		int y1 = pixels[i-1][1], y2 = pixels[i][1];

		bresenham(x1, y1, x2, y2);
	   
	}

	bresenham(10, 100, 100, 20);
	glutSwapBuffers();

}

void update() {
	printf("update\n");
	glutPostRedisplay();
}

void keyboardInput(unsigned char key, int x, int y) {

	printf("Touche %c Souris : %d, %d\n", key, x, y);

	if(pixels[0][0] <= 2) {
		printf("ne fais rien\n");
		return;
	}

	int x1 = pixels[1][0], x2  = pixels[pixels[0][0]][0];
	int y1 = pixels[1][1], y2 = pixels[pixels[0][0]][1];
	
	bresenham(x1, y1, x2, y2);
	


	glutPostRedisplay();

}

void mouseInput(int button, int state, int x, int y) {

	printf("Bouton %d à l'état %d : %d, %d\n", button, state, x, y);

	int nbPixels = pixels[0][0];

	if(nbPixels == NP) {
		printf("N'ajoute pas de pixel\n");
		return;
	}

	if(state == 1) {
		printf("bouton relaché\n");
		return;
	}

	printf("ajout d'un pixel\n");
	
	nbPixels++;

	pixels[nbPixels][0] = x/4;
	pixels[nbPixels][1] = 200-(y/3);

	pixels[0][0] = nbPixels;


	glutPostRedisplay();

}

