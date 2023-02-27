#include "events.h"

int pixels[NP][2] = {0};
Objet o1 = {0};
Objet o2 = {0};
int objets = 0;

int donePP = 0;

int listeIndexPP[NS];

int ratio;

void afficherObjet(Objet o) {
	int x1, x2, y1, y2, i;
	for(i = 1; i <= o[0][0][0]; i++) {
		x1 = o[i][0][0];
		y1 = o[i][0][1];

		x2 = o[i][1][0];
		y2 = o[i][1][1];

		bresenham(x1, y1, x2, y2);
	}
}

void getPlusProche(Objet o1, Objet o2);

void morphisme_aux(Objet o1, Objet o2, int ratio) {


}


void morphisme(Objet o1, Objet o2) {
	/* 
	 * déplacement selon un ratio k 
	 * => point M appartenant à la droite (a, b) tq a est un sommet de o1 et b son associé dans o2
	 * tq aM = k*ab
	 * on vient incrémenter k à chaque update, au début linéairement pour s'assurer que cela fonctionne
	 * puis suivant une courbe gaussienne pour lisser le mouvement
	 */
	morphisme_aux(o1, o2, ratio);

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(X_MIN, X_MAX, Y_MIN, Y_MAX, 0, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	printf("nb de pixels : %d\n", pixels[0][0]);

	if(objets >= 1) {
		afficherObjet(o1);

		if(objets >= 2) {
			afficherObjet(o2);
			if(!donePP) {
				getPlusProche(o1, o2);
				donePP = 1;
			}
			morphisme(o1, o2);
			
		}
	}
	
	if(pixels[0][0] == 1) {
		afficherPixel(pixels[1][0], pixels[1][1]);
	}
	
	for(int i = 2; i <= pixels[0][0]; i++) {
		
		int x1 = pixels[i-1][0], x2  = pixels[i][0];
		int y1 = pixels[i-1][1], y2 = pixels[i][1];

		bresenham(x1, y1, x2, y2);
	   
	}
	
	glutSwapBuffers();

}

void update() {
	printf("update\n");
	glutPostRedisplay();
}

void keyboardInput(unsigned char key, int a, int b) {

	int x1, y1, x2, y2;
	int i;

	printf("Touche %c Souris : %d, %d\n", key, a, b);
	int nbPixels = pixels[0][0];
	if(nbPixels < 2 || objets > 1)
		return;
	
	if(objets == 0) {
		for(i = 2; i <= nbPixels; i++) {
			x1 = pixels[i-1][0];
			y1 = pixels[i-1][1];

			x2 = pixels[i][0];
			y2 = pixels[i][1];
			
			o1[i-1][0][0] = x1;
			o1[i-1][0][1] = y1;

			o1[i-1][1][0] = x2;
			o1[i-1][1][1] = y2;

			o1[0][0][0] += 1;
		}
		o1[0][0][0]++;
	} else if(objets == 1) {
		
		for(i = 2; i <= nbPixels; i++) {
			x1 = pixels[i-1][0];
			y1 = pixels[i-1][1];

			x2 = pixels[i][0];
			y2 = pixels[i][1];

			o2[i-1][0][0] = x1;
			o2[i-1][0][1] = y1;

			o2[i-1][1][0] = x2;
			o2[i-1][1][1] = y2;

			o2[0][0][0] += 1;
		}
		o2[0][0][0]++;
	}
	

	memset(pixels, 0, sizeof(pixels));

	objets++;
		
	
	

	glutPostRedisplay();

}

void mouseInput(int button, int state, int x, int y) {

	int nbPixels = pixels[0][0];

	if(nbPixels == NP) {

		return;
	}

	if(state == 1) {

		return;
	}

	if(objets >= 2) {
		return;
	}

	
	nbPixels++;

	pixels[nbPixels][0] = x/4;
	pixels[nbPixels][1] = 200-(y/3);

	pixels[0][0] = nbPixels;

	printf("ajout du sommet (%d, %d)\n", pixels[nbPixels][0], pixels[nbPixels][1]);

	glutPostRedisplay();

}


void getPlusProche(Objet o1, Objet o2) {
	int centreSeg1[NS][2];
	int centreSeg2[NS][2];
	int i, j;

	int x1, x2, y1, y2;

	int nbSeg1 = o1[0][0][0];
	int nbSeg2 = o2[0][0][0];
	int segmentsLibres[NS];
	memset(segmentsLibres, 1, sizeof(segmentsLibres));
	if(nbSeg1 < nbSeg2) {
		i = 1;
		while(nbSeg1 != nbSeg2 && nbSeg1 < NS) {
			o1[nbSeg1][0][0] = (o1[i][0][0] + o1[i][1][0]) / 2;
			o1[nbSeg1][0][1] = (o1[i][0][1] + o1[i][1][1]) / 2;

			o1[nbSeg1][1][0] = o1[i][1][0];
			o1[nbSeg1][1][1] = o1[i][1][1];
			
			o1[i][1][0] = o1[nbSeg1][0][0];
			o1[i][1][1] = o1[nbSeg1][0][1];

			nbSeg1 = ++o1[0][0][0];
			i++;
		}
	} else if(nbSeg1 > nbSeg2) {
		i = 1;
		
		while(nbSeg1 != nbSeg2 && nbSeg2 < NS) {
			o2[nbSeg2][0][0] = (o2[i][0][0] + o2[i][1][0]) / 2;
			o2[nbSeg2][0][1] = (o2[i][0][1] + o2[i][1][1]) / 2;

			o2[nbSeg2][1][0] = o2[i][1][0];
			o2[nbSeg2][1][1] = o2[i][1][1];
			
			o2[i][1][0] = o2[nbSeg2][0][0];
			o2[i][1][1] = o2[nbSeg2][0][1];

			nbSeg2 = ++o2[0][0][0];
			i++;
		}
	}
	
	centreSeg1[0][0] = nbSeg1;
	centreSeg1[0][0] = nbSeg2;

	for(i = 1; i < nbSeg1; i++) {
		x1 = o1[i][0][0];
		y1 = o1[i][0][1];
		x2 = o1[i][1][0];
		y2 = o1[i][1][1];
		
		centreSeg1[i][0] = (x1 + x2) / 2;
		centreSeg1[i][1] = (y1 + y2) / 2;

		printf("Segment (%d, %d) - (%d, %d), centre : (%d, %d)\n", x1, y1, x2, y2, centreSeg1[i][0], centreSeg1[i][1]);

	}

	for(i = 1; i < nbSeg2; i++) {

		x1 = o2[i][0][0];
	    y1 = o2[i][0][1];
		x2 = o2[i][1][0];
		y2 = o2[i][1][1];

		centreSeg2[i][0] = (x1 + x2) / 2;
		centreSeg2[i][1] = (y1 + y2) / 2;
		printf("Segment (%d, %d) - (%d, %d), centre : (%d, %d)\n", x1, y1, x2, y2, centreSeg2[i][0], centreSeg2[i][1]);
	}


	int longueurCurr;

	for(i = 1; i < nbSeg1; i++) {
		x1 = centreSeg1[i][0];
		y1 = centreSeg1[i][1];

		int indexPlusProche = 99999;
		int longueurPlusProche = 99999;
		for(j = 1; j < nbSeg2; j++) {
			if(segmentsLibres[j] == 0) {
				continue;
			}
			x2 = centreSeg2[j][0];
			y2 = centreSeg2[j][1];
			
			longueurCurr = ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
			printf("Distance entre %d et %d : %d\n", i, j + nbSeg1 - 1, longueurCurr);
			if(longueurPlusProche > longueurCurr) {
				indexPlusProche = j;
				longueurPlusProche = longueurCurr;
			}

		}
		printf("%d prend %d\n", i, indexPlusProche);
		
		listeIndexPP[i] = indexPlusProche;
		segmentsLibres[indexPlusProche] = 0;
	}

	printf("Liste des plus proches : \n");

	for(i = 1; i < nbSeg1; i++) {
		printf("Plus proche de %d ==> %d\n", i, listeIndexPP[i]);
	}
	
}

