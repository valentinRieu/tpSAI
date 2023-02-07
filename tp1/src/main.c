#include "all.h"
#include <time.h>
extern int speed;
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(X_MIN, X_MAX, Y_MIN, Y_MAX, 0, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	
	montreEnSec(0, 0, 250, temps);
	glutSwapBuffers();

}


void setup(int argc, char **argv, char *s) {

		
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(800, 800);
	glutInitWindowPosition(50, 50);
	
	glutCreateWindow(s);
	
	glutDisplayFunc(display);

	glutIdleFunc(update);
	glutMainLoop();


}


int main(int argc, char **argv) {
	time_t now;
	struct tm *tm;
	
	if(argc == 1) {

		now = time(0);
		if((tm = localtime(&now)) == NULL) {
			printf("Problème récupération du temps\n");
			exit(0);
		}
		
		temps += tm->tm_hour * 3600 + tm->tm_min*60 + tm->tm_sec;
		temps %= S_DZ_H;
		
	} else {

		
		if(argv[1][0] == 's') {
			if(argc < 3) {
				usage(argv[0]);
				exit(0);
			}

			speed = atoi(argv[2]);

			if(argc > 3) {

				temps += atoi(argv[3]) * 3600;
				if (argc > 4) {
					temps += atoi(argv[4]) * 60;

					if (argc > 5) {
						temps += atoi(argv[5]);
					}
				}
			} else {
				
				now = time(0);
				if((tm = localtime(&now)) == NULL) {
					printf("Problème récupération du temps\n");
					exit(0);
				}
		
				temps += tm->tm_hour * 3600 + tm->tm_min*60 + tm->tm_sec;
				temps %= S_DZ_H;
			}
		} else {				
			temps += atoi(argv[1]) * 3600;
			
			if(argc > 2) {
				temps += atoi(argv[2]) * 60;

				if(argc > 3) {
					temps += atoi(argv[3]);
				}
			}
			
			temps %= S_DZ_H;
		}
	}

	setup(argc, argv, "montre");

	return 0;
}





