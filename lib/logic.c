
#include "lib.h"


void loop (void (**a)) { Eval ((void ***)a); }
int test (void (***a)) { return cons (a[1][0]) == cons (a[1][1]); }
void *stop (void (****a)) {
	if ((char) ((long) cons ((void *)a[1])) == 0) return 0;
	return (void *)-1;
}
