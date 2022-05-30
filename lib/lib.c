#include "lib.h"


void LoadLib () {
	Library ("print", print);
	Library ("break", (void (*)()) stop);
	Library ("loop", loop);
}
