#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char surname[20];
    char name[20];
    int day;
    int month;
    int year;
    char sex;
}Person;

int readText(FILE *p, Person list[]);
/*
writeText(){}

readBinary(){}
writeBinary(){}*/