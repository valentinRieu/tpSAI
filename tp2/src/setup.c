#include "setup.h"
point sommets[128];
int nbPoints;
void setup(int argc, char **argv, char *s) {

	if(argc == 1) {
		usage(argv[0]);
		exit(-1);
	}
	if(argc % 2 == 0) {
		usage(argv[0]);
		exit(0);
	}
		
	int j;
	for(nbPoints = 0, j = 1; j < argc; j += 2, nbPoints++) {

		sommets[nbPoints] = (point){atoi(argv[j]), atoi(argv[j+1])};
		printf("%d : %d, %d\n", nbPoints, sommets[nbPoints].x, sommets[nbPoints].y);
	}
	printf("%d\n", nbPoints);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(800, 800);
	glutInitWindowPosition(50, 50);
	
	glutCreateWindow(s);
	
	glutDisplayFunc(display);

	glutMainLoop();


}
