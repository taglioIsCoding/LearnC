#define element int

typedef struct list_element { 
        element value;
       struct list_element *next;
} item;
typedef item *list;
list emptyList(void);
int empty(list);
element head(list);
list tail(list);
list cons(element, list);
void showList(list);
int member(element, list);