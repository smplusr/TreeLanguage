#include "type.h"


void (*lambda[256][8]) ();	// NEEDED FOR DEBUG
void *constant[256][256];
void *library[256][2];

void *Constant (void *a[]) {
	int i = 0; for (; *constant[i]; i++)
		if (strequ (a, constant[i])) return constant[i];

	for (int j = 0; *a; *a++, j++) constant[i][j] = *a;
	return constant[i];
}


void *Lambda (void *a[]) {
	int i = 0, j = 0; for (; *lambda[i]; i++)
		if ((void (*)())lambda[i] == (void (*)())a) return (void (*)())lambda[i];
	for (; a[j]; j++) lambda[i][j] = (void (*)())a[j];

	return (void (*)())lambda[i];
}

void *Library (char *a, void (*b)()) {
	int i = 0; for (; library[i][0]; i++)
		if (strequ (library[i][0], a) || library[i][1] == b)
			return library[i][1];

	if (!b || !*a) return 0;

	library[i][0] = a; library[i][1] = b;
	return library[i][1];
}
