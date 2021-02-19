/*

Candidato Michele Tagliani
Matricola 0000978601

Fondamenti di informatica T1

*/
#include"cash.h"

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

Operazione leggiUnOperazione(FILE * fp){

    Operazione e;
    int i = 0;
    

    i = fscanf(fp, "%d ", &e.id);
    i += fscanf(fp, "%f ", &e.importo);
    i += readField(e.nomeNegozio, ' ', fp);

    if(i==3){
        return e;
    }else{
        e.id = 0;
        return e;
    }
}

Operazione * leggiTutteOperazioni(char * fileName, int * dim){
    Operazione  *tutteOperazioni;
    FILE *fp;
    Operazione toInsert;
    int finito = 0;
    int i=0;
    char ch;
    int lines = 0;

    fp = fopen(fileName, "r");
    if(fp==NULL){
        printf("ERROR\n");
        *dim = 0;
        fclose(fp);
        return NULL;
    }

    while (!feof(fp))
    {
        ch = fgetc(fp);
        if (ch == '\n')
        {
            lines++;
        }
    }

    lines ++;
    rewind(fp);
    
    while(finito!=lines){
        toInsert = leggiUnOperazione(fp);
        if(toInsert.id != 0){
                (*dim)++;
        }
        finito++;
    }

    rewind(fp);
    tutteOperazioni = (Operazione *) malloc((*dim)*sizeof(Operazione));
    
    for(i = 0; i < (*dim); i++){
        toInsert = leggiUnOperazione(fp);
        tutteOperazioni[i] = toInsert;
    }
    
    fclose(fp);
    return tutteOperazioni;
}

list leggiNegozi(char * fileName){
    list negozi = emptyList();
    FILE *fp;
    Negozio toInsert;
    int finito = 0;
    int i=0;
    int lines = 0;

    fp = fopen(fileName, "r");
    if(fp==NULL){
        printf("ERROR\n");
        fclose(fp);
        return negozi;
    }

    while (fscanf(fp, "%s %c", toInsert.nomeNegozio, &toInsert.isVir) == 2)
    {   
        negozi = cons(toInsert, negozi);
    }
    

    fclose(fp);
    return negozi;
}

void stampaOperazioni(Operazione * v, int dim){
    if(dim == 0){
        return;
    }else
    {
        dim--;
        printf("ID: %d importo: %f Negozio: %s\n", v[dim].id, v[dim].importo, v[dim].nomeNegozio);
        stampaOperazioni(v, dim);
    }
    
}

void ordina(Operazione * v, int dim){
    insertSort(v, dim);
}

int negozioFisico(char * nomeNegozio, list negozi){
    while (!empty(negozi))
    {
        if(strcmp(nomeNegozio, head(negozi).nomeNegozio) == 0 && head(negozi).isVir == 'F'){
            return 1;
        }else{
            negozi = tail(negozi);
            negozioFisico(nomeNegozio, negozi);
        }
    }
    return 0;
    
}

Operazione * filtra(Operazione * v, int dim, list negozi, int * dimLog){
    int i;
    Operazione *operazioneFis;
    operazioneFis = (Operazione *) malloc(dim*sizeof(Operazione));
    (*dimLog) = 0;

    for(i = 0; i < dim; i++){
        if(negozioFisico(v[i].nomeNegozio, negozi)==1){
            operazioneFis[(*dimLog)] = v[i];
            (*dimLog)++;
        }
    }

    return operazioneFis;
}

float spesaCliente(int idCliente, Operazione * v, int dim){
    int i;
    float tot = 0;

    for(i = 0; i < dim; i++){
        if(v[i].id == idCliente){
            tot += v[i].importo;
        }
    }

    return tot;
}