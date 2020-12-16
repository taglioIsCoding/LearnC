#include"element.h"

typedef struct list_element { 
        Element value;
       struct list_element *next;
} item;
typedef item *list;
list emptyList(void);
boolean empty(list l);
Element head(list l);
list tail(list l);
list cons(Element e, list l);
void showList(list l);
boolean member(Element e, list l);