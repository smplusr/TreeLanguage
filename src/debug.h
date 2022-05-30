#pragma once

#include <stdio.h>
#include "type.h"


#define DEBUG\
	printf ("\n");\
	DEBUG_Constants ();\
	printf ("\n");\
	DEBUG_Libraries ();\
	printf ("\n");\
	DEBUG_Lambdas ();\
	printf ("\n");


void DEBUG_Lambdas ();
void DEBUG_Libraries ();
void DEBUG_Constants ();
