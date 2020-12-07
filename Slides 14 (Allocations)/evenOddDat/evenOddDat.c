#include<stdio.h>
#include<stdlib.h>

int isEven(int d){
    if (d%2 == 0){
        return 1;
    }else
    {
        return 0;
    }
}

int writeRandom(FILE *fp){
    int i;
    int numbers[] = {2, 6, 77, 83, 44, 22, 12, 65, 95, 32};
    for(i = 0; i < 10; i++){
        fwrite(&numbers[i],sizeof(int),1,fp);
    }
    return 0;
}

int findTot(FILE *fp, int *even, int *odd){
    int num;
    while(fread(&num,sizeof(int),1,fp) == 1){
        if(isEven(num)){
                (*even)++;
            }else{
                (*odd)++;
            }
    }
    
    return *even + *odd; 
}

int read(FILE *fp, int even, int list[]){
    int num;
    int i = 0;
    int j = 0;
    while(fread(&num,sizeof(int),1,fp) == 1){
        if(isEven(num)){
                list[i] = num;
                i++;
        }else
        {
             list[even + j] = num;
             j++;
        }
    }
    return 0;
}

int main(void){
    FILE *fp;
    int even;
    int odd;
    int tot;
    int i;

    //fp = fopen("valori.dat", "rb+");
    printf("i read a dat file i allocate memory and i will print first even than odd\n");
    fp = fopen("values.dat", "rb+");
    if(fp==NULL){
        printf("ERROR\n");
        return 0;
    }

    writeRandom(fp);

    rewind(fp);

    tot = findTot(fp, &even, &odd);
    printf("Even: %d\n", even);
    printf("Odd: %d\n", odd);

    rewind(fp);

    int *p;
    p = (int *) malloc(tot*sizeof(int));
    read(fp, even, p);

    for(i=0; i<tot; i++){
        printf("Number: %d\n", p[i]);
    }

    fclose(fp);
    free(p);

}