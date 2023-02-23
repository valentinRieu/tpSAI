#ifndef ALL_H
#define ALL_H

#include "common.h"

#include "utils.h"
#include "events.h"
#include "bresenham.h"
#include "setup.h"
#define X_MIN 0
#define X_MAX 200
#define Y_MIN 0
#define Y_MAX 200


#define NS 200
#define NP 128

typedef int Objet[NS][2][2];

extern int pixels[NP][2];

extern Objet o1;
extern Objet o2;
#endif
