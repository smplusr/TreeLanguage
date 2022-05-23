#include "lib.h"


void *add (void (***a)) { 
	int b = 0;
	for (int i = 0; a[1][i]; i++) b += (int)cons (a[1][i]);
	return b;
}
