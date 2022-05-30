#include "lang.h"


int Lexe (char a[], char b[][256]) {
	int i = 0;
	for (; *a != '('; *a++);
	for (int j = 0, k = 0; *a; *a++, j++) {
		b[i][j] = *a;
		if (*a == '(') {
			k++;
			for (int m = 0; *a++; m++) {
				if (*a == '(') { *a--; break; }
				if (*a == ')') { 
					for (; m >= 0; m--) *a--;
					break;
				}
			}
		}
		if (*a == ')') {
			k--;
			while (*a++) if (*a == '(' || *a == ')') { *a--; break; }
		}
		if (k == 0) { i++; j = -1; }
	}
	return i - 1;
}

void (**Parse (char a[])) () {	
	int i = 0; for (; a[i]; i++); a[i-1] = '\0';
	for (int i = 0; a[i]; i++) { 
		a[i-1] = a[i]; 
		a[i] = '\0'; 
	} 

	for (int j = 0; ; j++) {
		if (!a[j]) {
			if (!Library (a, 0)) return Constant ((void*) a);	
			return Library(a, 0);
		}
		if (a[i] == '(' || a[j] == ')') break;
	}

	char b[8][256] = {}; void *d[8] = {};
	short int c = Lexe (a, b);
	
	for (; c >= 0; c--)
		d[c] = Parse (b[c]);	
	
	return (void (**)()) Lambda (d);
}

void *Eval (void *(**a)()) {
	if (!islambda (a)) return 0;

	for (int i = 0; a[i]; i++) {
		if (Library ("", a[i]) != 0)
			if (a[i] (a) == (void*)-1) return (void*)-1;

		if (Eval ((void *(**)())a[i]) == (void*)-1) return 0;
	}
}
