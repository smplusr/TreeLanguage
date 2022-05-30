#include "lib.h"


void *memory[256];

void *memoryget (void (***a)) { return memory[(char) ((long) cons (a[1]))]; }
void memoryset (void (****a)) { 
	for (int i = 0; a[1][1][i]; i++)
		memory[(char) ((long) cons (a[1][0])) + i] = (void *) ((long) cons (a[1][1][i]));
}
int intraw (void (***a)) {
	char b = (char) ((long) cons (a[1]));
	if (b >= '0' && b <= '9') b -= '0';
	return b;
}
