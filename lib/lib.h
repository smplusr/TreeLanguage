#pragma once


#include <stdio.h>
#include <stdlib.h>

#include "../src/lang.h"
#include "../src/ext.h"


extern void *memory[256];

void loop (void (**a));
int test (void (***a));
void *stop (void (****a));

void *memoryget (void (***a));
void memoryset (void (****a));
int intraw (void (***a));

int add (void (***a));

void command (void (****a));

void fileout (void (****a));
void filesave (void (***a));
void fileload (void (***a));
