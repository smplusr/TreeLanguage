
#include "lib.h"


void loop (void (**a)) { Run (a); }
void *test (void (***a)) { return (char)cons (a[1][0]) == (char)cons (a[1][1]); }
void *stop (void (****a)) {
	if ((char)cons (a[1]) == 0) return 0;
	return -1;
}
