#include "strio.h"


void Input (char a[]) { for (; (*a = getchar ()) != 27; *a++); }
void Read (char a[], char *b) {
	FILE *f = fopen (b, "r");
	if (f == NULL) return;
	for (int c; (c = fgetc(f)) != EOF; *a++ = (char)c);
	*a = '\0';
}
void Write (char *a, char b[]) {
	FILE *f = fopen (a, "w+");
	if (f) fputs (b, f);
	fclose (f);
}
