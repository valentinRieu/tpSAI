#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "GL/gl.h"
#include "GL/glut.h"


typedef struct {
	int x;
	int y;
} point;

extern point sommets[128];
extern int nbPoints;
#endif
