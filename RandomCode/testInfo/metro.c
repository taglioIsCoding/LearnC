
#include"metro.h"


#define MAX 255


typedef Element Evento;

int readField(char buffer[], char sep, FILE *f)
{
    int i = 0;
    char ch = fgetc(f);
    while (ch != sep && ch != 10 && ch != EOF ) {
        buffer[i] = ch;
        i++;
        ch = fgetc(f);
    }
    buffer[i] = '\0';
    if(i>0){
        return 1;
    }else{   
        return 0;
    }
    //return ch;
}

Evento leggiUno(FILE *fp){
    Evento e;
    int i = 0;
    /*if(fscanf(fp, "%d %[^@]@%s", &e.id, e.in, e.out)== 3){
        return e;
    }   
    else{
        e.id = -1;
        return e;
    }*/

    i = fscanf(fp, "%d ", &e.id);
    i += readField(e.in, '@', fp);
    i += readField(e.out, '\n', fp);

    if(i==3){
        return e;
    }else{
        e.id = -1;
        return e;
    }
}

list leggiTutti(char * fileName){
    list eventi;
    FILE *fp;
    Evento toInsert;
    int finito = 0;
    eventi = emptyList();

    fp = fopen(strcat(fileName, ".txt"), "r");
    if(fp==NULL){
        printf("ERROR\n");
        fclose(fp);
        return eventi;
    }

    while(!finito){
        toInsert = leggiUno(fp);
        if(toInsert.id != -1){
            eventi = cons(toInsert, eventi);
        }else
        {
            finito = 1;
        } 
    }
    fclose(fp);
    return eventi;
}

Tariffa * leggiTariffe(char * fileName, int * dim){
    FILE *fp;
    Tariffa * toUse;
    Tariffa temp;
    char ch;
    int finito = 0, i;
    fp = fopen(fileName, "r");
    if(fp==NULL){
        printf("ERROR\n");
        *dim = 0;
        fclose(fp);
        return NULL;
    }

    /*while (fscanf(fp, "%f\n", &temp.costo) == 1){
        (*dim)++;
    }*/

    while (!feof(fp)){
        ch = fgetc(fp);
        if (ch == '\n')
        {
            (*dim)++;
        }
    }

    //printf("%d, %d\n", (*dim), i);


    rewind(fp);
    toUse = (Tariffa *) malloc(sizeof(Tariffa) * (*dim));



    for(i = 0; i < (*dim) + 1 ; i++){
        readField(temp.in, '@', fp);
        readField(temp.out, '@', fp);
        fscanf(fp, "%f\n", &temp.costo);
        toUse[i] = temp;
    }

    fclose(fp);
    return toUse;
}

float ricerca(Tariffa *v, int dim, char * ingresso, char * uscita){
    int i;
    float fuond = 0;
    for(i =0; i < dim; i++){
        if(strcmp(ingresso, v[i].in) == 0 && strcmp(uscita, v[i].out) == 0){
            fuond = v[i].costo;
        }
    }

    return fuond;
}

void totali(Tariffa * tariffe, int dim, list eventi){
    int i;
    list temp;
    temp = eventi;
    while (eventi->next != NULL)
    {
        temp = eventi;
        int idToCheck = eventi->value.id;
        float total = 0;
        while (temp->next != NULL){
            if(temp->value.id == idToCheck){
                total = total + ricerca(tariffe, dim, temp->value.in, temp->value.out);
            }
            temp = tail(temp);
        }

        printf("L'utente %d ha speso %f\n", idToCheck, total);
        eventi = tail(eventi);
    }
    
}