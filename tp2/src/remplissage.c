#include "remplissage.h"

void remplissage(point *points, int nbPoints) {

	int yMin, yMax;
	int y1, y2;
	int yc;
	int i;
	int numCote;
	list lce, lcs, lcc, l, p, q, r;
    float a = 0., b = 0., dnum = 0., num = 0.; // calcul d'intersection
	int nbCotes = nbPoints;
	int cotes[nbCotes][2];
	int countInter;

	float ax, bx;


	yMin = points[0].y;
	yMax = points[0].y;
	
	/* calcul de ymin et ymax + cotes */

	for(int i = 0; i < nbPoints; i++) {

		y1 = points[i].y;
		y2 = points[(i+1) % nbCotes].y;

		if(y1 > y2) {
			cotes[i][0] = y2;
			cotes[i][1] = y1;
		}
		else {
			cotes[i][0] = y1;
			cotes[i][1] = y2;
		}

		if(yMin > cotes[i][0]) yMin = cotes[i][0];
		if(yMax < cotes[i][1]) yMax = cotes[i][1];


	}


	lce = newList();
	lcs = newList();
	lcc = newList();
	l = p = q = r = newList();

	for(yc = yMin; yc <= yMax; yc++) {
		for(int i = 0; i < nbCotes; i++) {
			if(cotes[i][0] == yc) {
				lce = insert(lce, i);
			}
			if(cotes[i][1] == yc) {
				lcs = insert(lcs, i);
			}
		}
	}

	p = copyList(lce);
	
	q = copyList(lcs);

	/* parcours de yMin à yMax */

	int countE = 0;
	int countS = 0;
	list tmpP, tmpQ;
	for(yc = yMin; yc <= yMax; yc++) {
		countInter = 0;

		tmpP = copyList(p);
		
		while(p != NULL && cotes[p->val][0] == yc) {
			countE++;
			lcc = insert(lcc, p->val);
			p = p->next;
			
		}

		p = copyList(tmpP);
		while(countE != 0) {
			p = removeFirst(p);
			countE--;
		}

		tmpQ = copyList(q);
		while(q != NULL && cotes[q->val][1] == yc) {
			countS++;
			lcc = removeVal(lcc, q->val);
			q = q->next;
		}
		q = copyList(tmpQ);
		
		while(countS != 0) {
			q = removeFirst(q);
			countS--;
		}

		l = copyList(lcc);


		/* On calcule alors toutes les intersections au yc courant => au LCC courant */
		while(!isEmpty(l)) {

			numCote = l->val;

			/* droite verticale */
			if((dnum = (float)(points[(numCote+1) % nbCotes].x - points[(numCote)].x)) == 0) {
				a = 0;
			} else { /* coefficient directeur */
				num = (float)(points[(numCote+1) % nbCotes].y - points[(numCote)].y);
				a = num / dnum;
			}
			/* ordonnée à l'origine */
			b = (float)(points[(numCote+1) % nbCotes].y) - a * (float)(points[(numCote + 1) % nbCotes].x);

			/* pas d'intersection */
			if(countInter == 0) {
				if(a == 0.0) {
					ax = (float)points[numCote].x;
				} else {
					ax = (yc - b) / a;
				}
				countInter = 1;
			} else {
				if(a == 0.0) {
					bx = (float)points[numCote].x;
				} else {
					bx = (yc - b) / a;
				}
				countInter = 2;
			}

			l = l->next;
		}

		if(countInter == 0)
			continue;
		
		/* il y a au moins une intersection */

		int ibx = (int)bx;
		int iax = (int)ax;
		
		int min, max;

		min = (iax > ibx) ? ibx : iax;
		max = (iax > ibx) ? iax : ibx;
		
		for(i = min; i <= max; i++)
			afficherPixel(i, yc);
		
	}

}

