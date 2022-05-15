#include "lang.h"


void (*lambda[256][16]) ();
void *library[256];

int Tokenize (char a[], char b[][256]) {
	int i = 0;
	for (int j = 0, k = 0; *a; *a++, j++) {
		b[i][j] = *a;
		if (*a == '(') k++;
		if (*a == ')') k--;
		if (k == 0) { i++; j = -1; }
	}
	return i;
}
void *Parse (char a[], int p) {	
	int i = 0; for (; a[i]; i++); a[i-1] = '\0';
	for (int i = 0; a[i]; i++) { 
		a[i-1] = a[i]; 
		a[i] = '\0'; 
	} 

	char b[16][256];
	int c = Tokenize (a, b);

	if (b[0][0] != '(') {
		if (!library[b[0][0]]) return b[0][0];	// TODO : Need recast (compiler warning) | Does not work : (*(void**)b[0]);
		return library[b[0][0]];
	}

	while (*lambda[p]) p++;	
	for (int i = 0; i < c; i++) {
		lambda[p][i] = Parse (b[i], p+1);
	}

	for (int i = 0; i < c; i++)
		if (library[b[i][0]]) lambda[p][i] (lambda[p]);
	return lambda[p];
}

