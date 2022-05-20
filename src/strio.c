#include "strio.h"


void Input (char a[]) { scanf("%[^\n]", a); }
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
void Remove (char a[], char b[]) {
	for (; *a; *a++) {
		for (int i = 0; b[i]; i++) {
			if (*a == b[i]) {
				for (int j = 0; a[j]; j++)
					a[j] = a[j+1];
				*a--;
			}
		}
	}
}
