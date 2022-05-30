#include "lib.h"


//void print (void ***a) { printf ("%s\n", (char*) ((long) a[1][0])); }
void print (void ***a) { 
	for (int i = 0; a[1][i]; i++)
		printf ("%s\n", a[1][i]);
}
