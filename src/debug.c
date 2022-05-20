#include "debug.h"


void DEBUG_PrintLambda (void (*a[][24])()) {
	for (int i = 0; a[i][0]; i++) {
		printf ("lambda[%i] (%p) = { ", i, a[i]);
		for (int j = 0; a[i][j]; j++) 
			printf ("%p ", a[i][j]);
		printf ("}\n");
	}
}
