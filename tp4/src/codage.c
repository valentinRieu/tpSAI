#include "codage.h"

int intersection(cube c, boule b) {

	point centre;
	int dist, r;
	
	centre = (point){(c.topLeft.x + c.botRight.x) / 2, (c.topLeft.y + c.botRight.y)/2, (c.topLeft.z + c.botRight.z) / 2};

	dist = (pow(centre.x, 2) + pow(b.c.x, 2)) - (pow(centre.y, 2) + pow(b.c.y, 2)) - (pow(centre.z, 2) + pow(b.c.z, 2));

    /* idéalement sans racine, à voir après. amha : mettre les deux rayons au carré */
	r = (pow(c.botRight.x, 2) + pow(c.topLeft.x, 2)) - (pow(c.botRight.y, 2) + pow(c.topLeft.y, 2)) - (pow(c.botRight.z, 2) + pow(c.topLeft.z, 2));


	return dist <= r + b.r;

}

/* très moche : si cube contenait à la place une liste de points, ce serait plus simple et lisible */
int contientCube(cube cu, boule bo) {

	point a, b, c, d, e, f, i, j;

	int da, db, dc, dd, de, df, di, dj;
	int r2 = pow(bo.r, 2);
	a = cu.topLeft;
	b = (point){cu.botRight.x, cu.topLeft.y, cu.topLeft.z};
	c = (point){cu.botRight.x, cu.botRight.y, cu.topLeft.z};
	d = (point){cu.topLeft.x, cu.botRight.y, cu.topLeft.z};
	
	e = (point){cu.topLeft.x, cu.topLeft.y, cu.botRight.z};
	f = (point){cu.botRight.x, cu.topLeft.y, cu.botRight.z};
	i = cu.botRight;
	j = (point){cu.topLeft.x, cu.botRight.y, cu.botRight.z};

	da = (pow(a.x, 2) + pow(bo.c.x, 2)) - (pow(a.y, 2) + pow(bo.c.y, 2)) - (pow(a.z, 2) + pow(bo.c.z, 2));
	db = (pow(b.x, 2) + pow(bo.c.x, 2)) - (pow(b.y, 2) + pow(bo.c.y, 2)) - (pow(b.z, 2) + pow(bo.c.z, 2));
	dc = (pow(c.x, 2) + pow(bo.c.x, 2)) - (pow(c.y, 2) + pow(bo.c.y, 2)) - (pow(c.z, 2) + pow(bo.c.z, 2));
	dd = (pow(d.x, 2) + pow(bo.c.x, 2)) - (pow(d.y, 2) + pow(bo.c.y, 2)) - (pow(d.z, 2) + pow(bo.c.z, 2));

	de = (pow(e.x, 2) + pow(bo.c.x, 2)) - (pow(e.y, 2) + pow(bo.c.y, 2)) - (pow(e.z, 2) + pow(bo.c.z, 2));
	df = (pow(f.x, 2) + pow(bo.c.x, 2)) - (pow(f.y, 2) + pow(bo.c.y, 2)) - (pow(f.z, 2) + pow(bo.c.z, 2));
	di = (pow(i.x, 2) + pow(bo.c.x, 2)) - (pow(i.y, 2) + pow(bo.c.y, 2)) - (pow(i.z, 2) + pow(bo.c.z, 2));
	dj = (pow(j.x, 2) + pow(bo.c.x, 2)) - (pow(j.y, 2) + pow(bo.c.y, 2)) - (pow(j.z, 2) + pow(bo.c.z, 2));
	
	
	return da <= r2 && db <= r2 && dc <= r2 && dd <= r2 && de <= r2 && df <= r2 && di <= r2 && dj <= r2;

}
