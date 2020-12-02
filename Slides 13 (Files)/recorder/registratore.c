#include"registratore.h"

int read(FILE *fp, Scontrino *dest){
    return fread(dest,sizeof(dest),1,fp); 
}

int write(FILE *fp, Scontrino src){
    fwrite(&src,sizeof(src),1,fp);
    return 0;
}