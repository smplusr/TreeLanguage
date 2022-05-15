#include "lib.h"


void LoadLib () {
	library['#'] = print;
	library['+'] = add;
}

void hello () { printf ("Hello World !\n"); }
void print (void (***e)) { for (int i = 0; e[1][i]; i++) printf ("%c", (char)e[1][i]); printf ("\n"); }
void add (void (***e)) { int k = 0; for (int i = 0; e[1][i]; i++) k += (int)e[1][i]; e[0] = k; }
