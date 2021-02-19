#include"pego.h"


int readField(char buffer[], char sep, FILE *f)
{
    int i = 0;
    char ch = fgetc(f);
    while (ch != sep && ch != 10 && ch != EOF ) {
        if(ch != '_'){
            buffer[i] = ch;
            i++;
        }else{
            buffer[i] = ' ';
            i++;
        }
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

Set leggiUnSet(FILE *fp){
    Set e;
    int i = 0;
    

    i = fscanf(fp, "%d ", &e.id);
    i += readField(e.desc, ' ', fp);
    i += readField(&e.type, ' ', fp);
    i += fscanf(fp, "%d ", &e.avaible);
    i += fscanf(fp, "%f\n", &e.cost);

    if(i==5){
        return e;
    }else{
        e.id = -1000;
        return e;
    }
}

list leggiTutti(char * fileName){
    list sets;
    FILE *fp;
    Set toInsert;
    int finito = 0;
    sets = emptyList();

    fp = fopen(strcat(fileName, ".txt"), "r");
    if(fp==NULL){
        printf("ERROR\n");
        fclose(fp);
        return sets;
    }

    while(!finito){
        toInsert = leggiUnSet(fp);
        if(toInsert.id != -1000){
            sets = cons(toInsert, sets);
        }else
        {
            finito = 1;
        } 
    }
    fclose(fp);
    return sets;
}

Complex leggiUnComplex(FILE * fp){
    Complex c;
    int i = 0;
    int k = 0;
    int num;
    
    k = fscanf(fp, "%d ", &c.idC);
    while(fscanf(fp, "%d ", &num) == 1 && num != -1000){
        c.idParts[i]= num;
        i++;
    }

    k += i;
    c.dimParts = i;
    if(k > 1){
        return c;
    }else
    {
        c.idC = -1000;
        return c;
    }
}

Complex trovaComplex(char * fileName, int target){
    int trovato = 0;
    int i;
    Complex temp;
    FILE *fp;
    
    fp = fopen(fileName, "r");
    if(fp==NULL){
        printf("ERROR\n");
        fclose(fp);
        temp.idC = -1000;
        return temp;
    }    

    while(!trovato){
        temp = leggiUnComplex(fp);
        if(temp.idC == target){
            trovato = 1;
        }
    }

    fclose(fp);

    if(trovato){
        quickSort(temp.idParts, 0, temp.dimParts-1);
        return temp;
    }else
    {
        temp.idC = -1000;
        return temp;
    }    
}

int check(list elenco, int target){

     int trovato = 0;
     int i = 0;
     int total;
     list temp;
     Complex c;

    temp = elenco;  

    while (temp->next != NULL)
    {
        if(temp->value.id == target && temp->value.avaible > 0){
            trovato = 1;
            return 10; //vero
        }else if (temp->value.id == target && temp->value.avaible == 0){
            trovato = 1;
            return -10; //falso
        }
        temp = tail(temp);
    }

    
    return -10;
}

int disp(list elenco, int target, char * fileName){
     FILE *fp;
     int trovato = 0;
     int i = 0;
     int total;
     int flag;
     list temp;
     Complex c;

    temp = elenco;

    //printf("fileName %s", fileName);
    fp = fopen(fileName, "r");
    if(fp==NULL){
        printf("ERRORS\n");
        fclose(fp);
        return -10;
    }    

    while (!empty(temp))
    {
        if(temp->value.id == target && temp->value.avaible > 0){
            trovato = 1;
            return 10; //vero
        }else if (temp->value.id == target && temp->value.avaible == 0 && temp->value.type == 'S'){
            trovato = 1;
            return -10; //falso
        }else if (temp->value.id == target && temp->value.avaible == 0 && temp->value.type == 'C'){
            c = trovaComplex(fileName, temp->value.id);
            total = 0;
            if(c.idC != -1000){
                for(i = 0; i < c.dimParts; i++){
                    total += check(elenco, c.idParts[i]);
                }
                flag = c.dimParts ++;
                if(total == (flag * 10)){
                    return 10;
                }
            }
            return -10;
        }
        temp = tail(temp);
    }

    
    return -10;
    
}