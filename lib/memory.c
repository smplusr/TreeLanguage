#include "lib.h"


void *memory[256];

void *memoryget (void (***a)) { return memory[(char)cons (a[1])]; }
void memoryset (void (****a)) { 
	for (int i = 0; a[1][1][i]; i++)
		memory[(char)cons (a[1][0]) + i] = (int)cons (a[1][1][i]);
}
void *intraw (void (***a)) {
	char b = (char)cons (a[1]);
	if (b >= '0' && b <= '9') b -= '0';
	return b;
}
