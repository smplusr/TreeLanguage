#include "lang.h"


void *(*lambda[256][8]);
void *library[256];

int Lexe (char a[], char b[][256]) {
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

	char b[8][256];
	int c = Lexe (a, b);

	if (b[0][0] != '(') {
		if (!library[b[0][0]]) return (void *) (long) b[0][0];
		return library[b[0][0]];
	}

	while (*lambda[p]) p++;	
	for (int i = 0; i < c; i++) {
		lambda[p][i] = Parse (b[i], p+1);
	}

	return lambda[p];
}
void *Eval (void *(**a)) {
	if (!islib ((void **)a) && a > (void *(**))256) {
		for (int i = 0; a[i]; i++) {
			if (islib (a[i])) {
				void *(*f)() = (void *(*)())a[i];
				if (f) if (f (a) == (void *(**))-1) return (void *(**))-1;
			}
			if (Eval ((void ***) a[i]) == (void *(**))-1) return 0;
		}
	}
}
