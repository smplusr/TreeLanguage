#include "ext.h"


void *cons (void *(*a)) { 
	if (a <= (void (*(*)))0xff) return a;
	for (int i = 0; a[i]; i++) {
		if (islib (a[i])) { void *(*f)() = (void *(*)())a[i]; return f (a); }
		return cons (a[i]);
	}
}

int islib (void *(*a)) {
	for (int i = 0; i < 256; i++)
		if (a == library[i]) return 1;
	return 0;
}
void *func (void *(*a)) {
	if (a <= (void (*(*)))256) return 0;
	if (islib (a)) return a;
	for (int i = 0; a[i]; i++) return func (a[i]);
}
