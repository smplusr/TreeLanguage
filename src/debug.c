#include "debug.h"



void DEBUG_Lambdas () {
	for (int i = 0; *lambda[i]; i++) {
		printf ("lambda[%i] (%p) = { ", i, lambda[i]);
		for (int j = 0; lambda[i][j]; j++)
			printf ("%p ", (char*) ((long) lambda[i][j]));
		printf ("}\n");
	}
}

void DEBUG_Libraries () {
	for (int i = 0; *library[i]; i++) {
		printf ("library[%i] (%p) = { ", i, library[i]);
		for (int j = 0; j < 2; j++)	
			printf ("%p ", (char*) ((long) library[i][j]));
		printf ("}\n");
	}
}

void DEBUG_Constants () {
	for (int i = 0; *constant[i]; i++)
		printf ("constant[%i] (%p) = { %s }\n", i, constant[i], (char*) ((long) constant[i]));
}
