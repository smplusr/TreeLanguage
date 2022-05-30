#include "util.h"


int strequ (char a[], char b[]) { for (; *a; *a++, *b++) if (*a != *b) return 0; return 1; }
int islambda (void *a) { for (int i = 0; *lambda[i]; i++) if (a == lambda[i]) return 1; return 0; }
