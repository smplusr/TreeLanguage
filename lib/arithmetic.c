#include "lib.h"


int add (void (***a)) { 
	int b = 0;
	for (int i = 0; a[1][i]; i++) b += (int) ((long) cons (a[1][i]));
	return b;
}
