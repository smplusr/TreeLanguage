#include "lib.h"


void *stop () { return (void*)-1; }
void loop (void *a) { Eval ((void *(**)())a); }
