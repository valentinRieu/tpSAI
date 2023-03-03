#include "setup.h"


void setup(int argc, char **argv, char *s) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(800, 800);
	glutInitWindowPosition(50, 50);
	
	glutCreateWindow(s);
	
	glutDisplayFunc(display);

	glutMainLoop();

}
