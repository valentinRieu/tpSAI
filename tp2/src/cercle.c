#include "cercle.h"

void cercleAndres(int xc, int yc, int r) {
	int x = 0;
	int y = r;
	int critere = r - 1;

	while(y >= x) {
		afficherPixel(xc + x, yc + y);
		afficherPixel(xc + y, yc + x);
		afficherPixel(xc - x, yc + y);
		afficherPixel(xc - y, yc + x);
		afficherPixel(xc + x, yc - y);
		afficherPixel(xc + y, yc - x);
		afficherPixel(xc - x, yc - y);
		afficherPixel(xc - y, yc - x);
		if(critere >= 2*x) {
			critere = critere - 2*x - 1;
			x += 1;
		} else if(critere < 2*(r-y)) {

			critere = critere + 2*y -1;
			y -= 1;
		} else {
			critere = critere + 2*(y-x-1);
			y -= 1;
			x += 1;
		}

	}				
}

void cercleBresenham(int xc, int yc, int r) {
	int x = 0, y = r;
    int d = 5 / 4 - r;
    while (y >= x)
    {
        afficherPixel(xc + x, yc + y);
        afficherPixel(xc + y, yc + x);
        afficherPixel(xc - x, yc + y);
        afficherPixel(xc - y, yc + x);
        afficherPixel(xc - x, yc - y);
        afficherPixel(xc - y, yc - x);
        afficherPixel(xc + x, yc - y);
        afficherPixel(xc + y, yc - x);
        if (d < 0)
        {
            d = d + 2 * x + 3;
        }
        else
        {
            d = d + 2 * x - 2 * y + 5;
            y--;
        }
        x++;
    }
}


