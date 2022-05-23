#pragma once


extern void *(*lambda[256][24]) ();
extern void *library[256];

int Tokenize (char a[], char b[][256]);
void *Parse (char a[], int p);
