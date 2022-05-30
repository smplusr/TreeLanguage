#define DEBUG

#include <stdio.h>

#include "debug.h"
#include "lang.h"
#include "strio.h"

#include "../lib/lib.h"


void main (int argc, char *argv[]) {
	LoadLib();

	char s[4096] = "";
	static int i = 1;

	if (!argv[1]) { Input (s); Eval (Parse (s)); DEBUG }
	for (; argv[i]; i++) {
		if (argv[i][0] == '-' && argv[i][1]) {
			switch (argv[i][1]) {
				case 'i':
					Input (s);
					Eval (Parse (s));
					break;
				case 'f':
					Read (s, argv[i+1]);
					Eval (Parse (s));
					break;
				case 'd':
					DEBUG
					break;
				default:
					break;
			}
		}
	}
}
