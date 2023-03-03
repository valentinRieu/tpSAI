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


void bresenham(int x1, int y1, int x2, int y2) {
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
