/*

Candidato Michele Tagliani
Matricola 0000978601

Fondamenti di informatica T1

*/
#include"element.h"

typedef struct list_element { 
        Element value;
       struct list_element *next;
} item;
typedef item *list;
list emptyList(void);
boolean empty(list);
Element head(list);
list tail(list);
list cons(Element, list);
void showList(list);
boolean member(Element, list);