#include "lib.h"


void command (void (****a)) { 
	char b[256] = "";
	for (int i = 0; a[1][i]; i++)
		b[i] = (char) ((long)cons (a[1][i]));
	system (b);
}
