#include "lib.h"
#include "memory.h"
#include "../src/strio.h"


void fileout (void (****a)) {
	char b[2][256] = {};
	for (int i = 0; a[1][0][i]; i++)
		b[0][i] = (char) ((long) cons (a[1][0][i]));
	for (int i = 0; a[1][1][i]; i++)
		b[1][i] = (char) ((long) cons (a[1][1][i]));
	Write ((char*) b[0], (char*) b[1]);
}
void filesave (void (***a)) {
	char b[256] = "";
	for (int i = 0; a[1][i]; i++)
		b[i] = (char) ((long) cons (a[1][i]));
	Write ((char*) b, (char*) memory);
}
void fileload (void (***a)) {
	char b[256] = "";
	for (int i = 0; a[1][i]; i++)
		b[i] = (char) ((long) a[1][i]);
	Read ((char*) memory, (char*) b);
}
