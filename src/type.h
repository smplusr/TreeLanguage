#pragma once

#include "util.h"


extern void (*lambda[256][8]) ();	// NEEDED FOR DEBUG_Lambda
extern void *constant[256][256];
extern void *library[256][2];


void *Lambda (void *a[]);
void *Constant (void *a[]);
void *Library (char *a, void (*b)());
