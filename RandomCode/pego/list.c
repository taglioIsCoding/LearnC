#include <stdio.h>
#include <stdlib.h>
#include"list.h"

/* ---- PRIMITIVE ---- */
list emptyList(void) { return NULL; }
boolean empty(list l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}
Element head(list l)
{
    if (empty(l))
        exit(1);
    else
        return l->value;
}
list tail(list l)
{
    if (empty(l))
        exit(1);
    else
        return l->next;
}
list cons(Element e, list l)
{
    list t;
    t = (list)malloc(sizeof(item));
    t->value = e;
    t->next = l;
    return t;
}

void showList(list l)
{
while (!empty(l)) {
        printf("%d %s type: %c %d cost: %f\n", head(l).id, head(l).desc, head(l).type, head(l).avaible, head(l).cost);
        l = tail(l);
        // NON PRIMITIVE
        //if (!empty(l))
           // printf(", "); } printf("]\n");
    }
}