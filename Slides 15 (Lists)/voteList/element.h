#include "elementdef.h"
#ifndef ELEMENT
#define ELEMENT
int compare(Element e1, Element e2);
void swap(Element *e1, Element *e2);
void assign(Element *lvalue, Element rvalue); void printElement(Element e);
void printStatistics();
 #endif