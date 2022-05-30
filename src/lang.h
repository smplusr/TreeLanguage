#pragma once


#include "ext.h"

extern void *(*lambda[256][8]);
extern void *library[256];

int Tokenize (char a[], char b[][256]);
void *Parse (char a[], int p);
void *Eval (void *(**a));
