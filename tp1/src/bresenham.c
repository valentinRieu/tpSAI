#include "bresenham.h"



void bresenhamInitial(int x1, int y1, int x2, int y2) {
	int y = y1;
	float dy = y2 - y1;
	float dx = x2 - x1;

	float m = dy/dx;
	float erreur = -0.5;

	for (int x = x1; x <= x2; x++) {
		afficherPixel(x, y);
		erreur = erreur + m;

		if (erreur >= 0) {
			y++;
			erreur -= 1;
		}

	}
}


void bresenhamPremierOct(int x1, int y1, int x2, int y2) {

	int y = y1;
	int dy = y2 - y1;
	int dx = x2 - x1;

	int m = 2*dy;

	int critere = -dx;

	for (int x = x1; x <= x2; x++) {
		afficherPixel(x, y);
	    critere += m;

		if (critere >= 0) {
			y++;
			critere -= 2*dx;
		}
	}

}


/* ma méthode d'affichage du cadran de la montre m'oblige à utiliser une version plus "propre" de l'algorithme ; l'affichage a des problèmes sinon.
   bresenham(...) est utilisé pour les aiguilles.
*/
void bresenham_propre(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (1) {
        afficherPixel(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err = err - dy;
            x1 = x1 + sx;
        }
        if (e2 < dx) {
            err = err + dx;
            y1 = y1 + sy;
        }
    }
}



void bresenham(int x1, int y1, int x2, int y2) {

	int X1, Y1, X2, Y2, X, Y;
	int crit;
	int dx = x2 - x1;
	int dy = y2 - y1;
	int dX, dY;

	X1 = x1;
    Y1 = y1;
    X2 = x2;
    Y2 = y2;


	if(dx > 0) {

		if(dy > 0) {
			if (dx > dy) {		/* octant 1 */
				Y = Y1;
				dX = X2 - X1;
				dY = Y2 - Y1;
				crit = -dX;

				for(X = X1; X < X2; X++) {
					afficherPixel(X, Y);
					crit += 2* dY;
					if(crit > 0) {
						Y++;
						crit -= 2 * dX;

					}

				}
				return;
			} /* octant 2 */

			Y = Y1;
			dX = Y2 - X1;
			dY = X2 - Y1;
			crit = -dX;
			for(X = X1; X < Y2; X++) {
				afficherPixel(Y, X);
				crit += 2*dY;

				if(crit > 0) {
					Y++;
					crit -= 2 * dX;
				}
			}

			return;
			
		}
		if (dx > -dy) {			/* octant 8 */
			
			Y = Y1;
			dX = X2 - X1;
			dY = (-Y2) - Y1;
			crit = (-dX);
			for(X = X1; X < X2; X++) {
				afficherPixel(X, -Y);
				crit += 2*dY;

				if(crit > 0) {
					Y++;
					crit -= 2 * dX;
				}
			}

			return;
		} /* octant 7 */

		
		Y = Y1;
		dX = (-Y2) - X1;
		dY = X2 - Y1;
		crit = -dX;
		for(X = X1; X < -Y2; X++) {
			afficherPixel(Y, -X);
			crit += 2*dY;

			if(crit > 0) {
				Y++;
				crit -= 2 * dX;
			}
		}

		return;
	}

	if(dy > 0) {
		if((-dx) > dy) {		/* octant 4 */
			
			Y = Y1;
			dX = -X2 - X1;
			dY = Y2 - Y1;
			crit = -dX;
			for(X = X1; X < -X2; X++) {
				afficherPixel(-X, Y);
				crit += 2*dY;

				if(crit > 0) {
					Y++;
					crit -= 2 * dX;
				}
			}

			return;

		} /* octant 3 */

		Y = Y1;
		dX = Y2 - X1;
		dY = -X2 - Y1;
		crit = -dX;
		for(X = X1; X < Y2; X++) {
			afficherPixel(-Y, X);
			crit += 2*dY;

			if(crit > 0) {
				Y++;
				crit -= 2 * dX;
			}
		}

		return;
	}

	if(-dx > -dy) {				/* octant 5 */

		
		Y = Y1;
		dX = -X2 - X1;
		dY = -Y2 - Y1;
		crit = -dX;
		for(X = X1; X < -X2; X++) {
			afficherPixel(-X, -Y);
			crit += 2*dY;

			if(crit > 0) {
				Y++;
				crit -= 2 * dX;
			}
		}

		return;
		
	} /* octant 6 */

	
	Y = Y1;
	dX = -Y2 - X1;
	dY = -X2 - Y1;
	crit = -dX;
	for(X = X1; X < -Y2; X++) {
		afficherPixel(-Y, -X);
		crit += 2*dY;

		if(crit > 0) {
			Y++;
			crit -= 2 * dX;
		}
	}

	return;

}
