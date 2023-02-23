#include "setup.h"
Objet o1 = {0};
Objet o2 = {0};

void setup(int argc, char **argv, char *s) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);
	
	glutCreateWindow(s);
	
	glutDisplayFunc(display);

	glutKeyboardFunc(keyboardInput);

	glutMouseFunc(mouseInput);
	glutMainLoop();

}
