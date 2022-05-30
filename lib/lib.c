#include "lib.h"


#include <stdio.h>
#include <stdlib.h>

void LoadLib () {	
	library['&'] = loop;
	library['='] = test;
	library['?'] = stop;
	
	library['<'] = memoryget;
	library['>'] = memoryset;
	library[';'] = intraw;

	library['+'] = add;

	library['%'] = command;

	library['@'] = fileout;
	library[']'] = filesave;
	library['['] = fileload;
}
