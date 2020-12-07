#include"peopleDo.h"

int readText(FILE *p, Person list[]){
    Person personToInsert;
    int i=0;
    while (fscanf(p, "%s %s %d/%d/%d %c\n", personToInsert.surname , personToInsert.name, &personToInsert.day, &personToInsert.month, &personToInsert.year, &personToInsert.sex) != EOF)
    {   
        list[i] = personToInsert;
        i++;
    }
    return i;
}