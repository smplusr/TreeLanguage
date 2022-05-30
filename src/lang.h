#pragma once

#include "type.h"
#include "util.h"


int Lexe (char a[], char b[][256]);
void (**Parse (char a[])) ();
void *Eval (void *(**a)());
