#include "montre.h"

const double degSecond = 360./60.;
const double degMin = 360./60.;
const double degHour = 360./12.;

const double degSecondToMin = (degMin) / 60.;	/* angle en deg. d'une seconde en minute  */

const double toRad = M_PI/180.;

const double degSecondToHour = degHour / 3600.; /* angle en deg. d'une seconde en heure */

const double degMinToHour = degHour / 60.;	/* angle en deg. d'une minute en heure  */


const double ratioH = 0.3;
const double ratioMin = 0.6;
const double ratioS = 0.8;

const double ratioDeuxiemeCercle = 0.85;


void afficherCadran(int xc, int yc, int r, double ratio);



void montre(int xc, int yc, int r, int h, int min, int s) {

	int xh, yh, xmin, ymin, xs, ys;

	double angleSecond = ((degSecond * s) * toRad) - M_PI_2;
	angleSecond = fmod(angleSecond, 2 * M_PI);

	angleSecond = -angleSecond;
	
	double angleMin = (((degMin * min) + (degSecondToMin * s)) * toRad) - M_PI_2;
	angleMin = fmod(angleMin, 2 * M_PI);
	angleMin = -angleMin;
	
	double angleHour = (((degHour * h) + (degMinToHour * min) + (degSecondToHour * s)) * toRad) - M_PI_2;
	angleHour = fmod(angleHour, 2 * M_PI);
	angleHour = -angleHour;


	xh = (int)(xc + ratioH*(cos(angleHour)) * r);
	yh = (int)(yc + ratioH*(sin(angleHour)) * r);

	xmin = (int)(xc + ratioMin*(cos(angleMin)) * r);
	ymin = (int)(yc + ratioMin*(sin(angleMin)) * r);

	xs = (int)(xc + ratioS*(cos(angleSecond)) * r);
	ys = (int)(yc + ratioS*(sin(angleSecond)) * r);

	afficherCadran(xc, yc, r, ratioDeuxiemeCercle);
	bresenham(xc, yc, xh, yh);
	bresenham(xc, yc, xmin, ymin);
	bresenham(xc, yc, xs, ys);
}

void montreEnSec(int xc, int yc, int r, int tempsEnSec) {
	int h, min, s;
	h = tempsEnSec / 3600;
	tempsEnSec = tempsEnSec % 3600;

	min = tempsEnSec / 60;

    s = tempsEnSec % 60;

	printf("%d, %d, %d\n", h, min, s);
	
	montre(xc, yc, r, h, min, s);
}

void afficherCadran(int xc, int yc, int r, double ratio) {

	cercleBresenham(xc, yc, r);
	cercleBresenham(xc, yc, r*ratio);

	double longueur = r - r*ratio;
	double angle = 0.;

	int x1, y1, x2, y2;
	for(int i = 0; i < 12; i++) {
		x1 = (int)(xc + (cos(angle) * (r - longueur)));
		x2 = (int)(xc + (cos(angle) * r));

		y1 = (int)(yc + (sin(angle) * (r - longueur)));
		y2 = (int)(yc + (sin(angle) * r));
		
		bresenham_propre(x1, y1, x2, y2);

		angle += M_PI / 6;
	}


}
