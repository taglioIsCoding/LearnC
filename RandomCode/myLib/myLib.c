#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//#include"list.h"
#include"element.h"
//#include"binary.h"
#include"text.h"
#include"order.h"


/*gcc myLib.c list.c element.c binary.c text.c order.c -o myLib;*/



int main(void){
    /*
        //READ WRITE ELEMENTS FROM A BINARY FILE
    
    FILE *fp;
    Element toWrite;
    Element toRead;
    int i =0;
    fp = fopen("example.dat", "wb");
    if(fp==NULL){
        printf("ERROR\n");
        return false;
    }

    for(i = 0; i < 10; i++){
        toWrite.id = i;
        strcpy(toWrite.name, "Ciao\0");
        toWrite.num = 11;
        toWrite.rate = 4.0 * i;
        toWrite.type = 'P';
        writeB(fp, toWrite);
    }
    fclose(fp);

    fp = fopen("example.dat", "rb");
    if(fp==NULL){
        printf("ERROR\n");
        return false;
    }

    while(readB(fp, &toRead) > 0){
        printf("Name %s Id %d\n", toRead.name, toRead.id);
    }
    fclose(fp); 
    */

    /*
       // READ WRITE LIST BINARY;

    list test;
    test = emptyList();
    FILE *fp;
    Element toWrite;
    Element toRead;
    int i =0;
    fp = fopen("example.dat", "wb");
    if(fp==NULL){
        printf("ERROR\n");
        return false;
    }

    for(i = 0; i < 10; i++){
        toWrite.id = i;
        strcpy(toWrite.name, "Ciao\0");
        toWrite.num = 11;
        toWrite.rate = 4.0 * i;
        toWrite.type = 'P';
        test = cons(toWrite, test);
    }
    writeList(fp, test);
    fclose(fp);

    fp = fopen("example.dat", "rb");
    if(fp==NULL){
        printf("ERROR\n");
        return false;
    }
    test = emptyList();
    readList(fp, &test);
    showList(test);

    fclose(fp);
    */
    
    

        //READ WRITE TXT FILE

    FILE *fp;
    Element toWrite;
    Element toRead;
    int i =0;
    fp = fopen("example.txt", "w");
    if(fp==NULL){
        printf("ERROR\n");
        return false;
    }

    for(i = 0; i < 10; i++){
        toWrite.id = i;
        strcpy(toWrite.name, "Ciao\0");
        toWrite.num = 11;
        toWrite.rate = 4.0 * i;
        toWrite.type = 'P';
        writeT(fp, toWrite);
    }
    fclose(fp);

    fp = fopen("example.dat", "rb");
    if(fp==NULL){
        printf("ERROR\n");
        return false;
    }

    while(readT(fp, &toRead) > 0){
        printf("Name %s Id %d\n", toRead.name, toRead.id);
    }
    fclose(fp); 

}