#include "lib.h"


void *memory[256];

void *raw (void (***a)) {
	char b = (char)cons (a[1]);
	if (b >= '0' && b <= '9') b -= '0';
	return b;
}

void loop (void (**a)) { Run (a); }

void *equ (void (***a)) { return (char)cons (a[1][0]) == (char)cons (a[1][1]); }
void *end (void (****a)) {
	if ((char)cons (a[1]) == 0) return 0;
	return -1;
}
void *add (void (***a)) { 
	int b = 0;
	for (int i = 0; a[1][i]; i++) b += (int)cons (a[1][i]);
	return b;
}

void set (void (****a)) { 
	for (int i = 0; a[1][1][i]; i++)
		memory[(char)cons (a[1][0]) + i] = (int)cons (a[1][1][i]);
}
void *get (void (***a)) { return memory[(char)cons (a[1])]; }
/*void write (void (****a)) { 
	char b[2][256] = {}; 
	printf ("%i\n", cons (a[1][1][0]));
	for (int j = 0; j < 2; j++)
		for (int i = 0; a[1][j][i]; i++)
			b[j][i] = (char)cons (a[1][j][i]);
	Write (b[0], b[1]);
}*/

void sys (void (****a)) { 
	char b[256] = "";
	for (int i = 0; a[1][i]; i++)
		b[i] = (int)cons (a[1][i]);
	system (b);
}

void LoadLib () {
	library['+'] = add;
	library['&'] = loop;
//	library['@'] = write;
	library['='] = equ;
	library['?'] = end;
	library[';'] = raw;
	library['>'] = set;
	library['<'] = get;
	library['%'] = sys;
}
