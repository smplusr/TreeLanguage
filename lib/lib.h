#pragma once


#include <stdio.h>
#include <stdlib.h>

#include "../src/lang.h"
#include "../src/ext.h"


extern void *memory[256];

void loop (void (**a));
void *test (void (***a));
void *stop (void (****a));

void *memoryget (void (***a));
void memoryset (void (****a));
void *intraw (void (***a));

void *add (void (***a));

void command (void (****a));

void cliout (void (***a));
void fileout (void (****a));
void filesave (void (***a));
void fileload (void (***a));
