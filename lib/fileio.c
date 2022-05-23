#include "lib.h"
#include "memory.h"


void cliout (void (***a)) { for (int i = 0; a[1][i]; i++) printf ("%c", (char)cons (a[1][i])); printf ("\n"); }

void fileout (void (****a)) {
	char b[2][256] = {};
	for (int i = 0; a[1][0][i]; i++)
		b[0][i] = (char)cons (a[1][0][i]);
	for (int i = 0; a[1][1][i]; i++)
		b[1][i] = (char)cons (a[1][1][i]);
	Write (b[0], b[1]);
}
void filesave (void (***a)) {
	char b[256] = "";
	for (int i = 0; a[1][i]; i++)
		b[i] = (char)cons (a[1][i]);	
	Write (b, memory);
}
void fileload (void (***a)) {
	char b[256] = "";
	for (int i = 0; a[1][i]; i++)
		b[i] = a[1][i];
	Read (memory, b);
}
