#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


typedef struct {
	int x;
	int y;
	int z;
} point;


typedef struct {
	point topLeft;
	point botRight;
} cube;


typedef struct {
	point c;
	int r;
} boule;


#include "GL/gl.h"
#include "GL/glut.h"


#endif
