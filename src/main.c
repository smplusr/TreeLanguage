#include "debug.h"
#include "strio.h"
#include "lang.h"


int main (int argc, char *argv[]) {
	LoadLib ();

	char s[4096];

	if (!argv[1]) { Input (s); Remove (s, "	 "); Parse (s, 0); DEBUG_PrintLambda (lambda); }
	for (int i = 0; argv[i]; i++) {
		if (argv[i][0] == '-' && argv[i][1]) {
			switch (argv[i][1]) {
				case 'i':
					Input (s); 
					Remove (s, "	 "); 
					Parse (s, 0);
					break;
				case 'f':
					Read (s, argv[i+1]);
					Remove (s, "\n	"); 
					Parse (s, 0);
					Run (lambda[0]);
					break;
				case 'd':
					DEBUG_PrintLambda (lambda);
					break;
				default:
					break;
			}
		}
	}
}
