#include<stdio.h>
#include<string.h>
#include"order.h"

int swap_count = 0;
int comp_count = 0;
void incSwap() { swap_count++; }
void incComp() { comp_count++; }
void resetCounters()
{
    swap_count = 0;
    comp_count = 0;
}
void printCounters()
{
    printf("Numero di confronti effettuati: %d\n", comp_count);
    printf("Numero di scambi effettuati: %d\n", swap_count);
}

void assignT(toOrder *lvalue, toOrder rvalue)
{
    *lvalue = rvalue;
}

void swapOrder(toOrder * a, toOrder * b){
    toOrder tmp;
    assignT(&tmp, *a);
    assignT(a, *b);
    assignT(b, tmp);
    incSwap();
}

int compareT(toOrder a, toOrder b){
    if(a > b){
        return 1;
    }else if(a < b){
        return -1;
    }else{
        return 0;
    }
}

// n
void bubbleSort(toOrder v[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)     
        for (j = n - 1; j > i; j--)
            if (compareT(v[j], v[j + 1]) > 0)   
                swapOrder(&v[j], &v[j + 1]);
}

void insOrd(toOrder v[], int pos){
    int i = pos - 1;
    toOrder x = v[pos];
    while (i >= 0 && compareT(x, v[i]) < 0)
    {
        v[i + 1] = v[i];
        i--;
    }
    v[i + 1] = x;
}

//n + 1
void insertSort(toOrder v[], int n){
    int k;
    for (k = 1; k < n; k++)
        insOrd(v, k);
}

void merge(toOrder v[], int i1, int i2, int fine, toOrder vout[]){
    int i = i1, j = i2, k = i1;

    while (i <= i2 - 1 && j <= fine)
    {
        if (compareT(v[i], v[j]) < 0){
            vout[k] = v[i];
            i++;
        }
        else{
            vout[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= i2 - 1)
    {
        vout[k] = v[i];
        i++;
        k++;
    }
    while (j <= fine)
    {
        vout[k] = v[j];
        j++;
        k++;
    }
    for (i = i1; i <= fine; i++){
        v[i] = vout[i];
    }
    return;
}

// n (give a dimension to vout)
void mergeSort(toOrder v[], int iniz, int fine, toOrder vout[])
{
    int mid;
    if (iniz < fine)
    {
        mid = (fine + iniz) / 2;
        mergeSort(v, iniz, mid, vout);
        mergeSort(v, mid + 1, fine, vout);
        merge(v, iniz, mid + 1, fine, vout);
    }
}

//used in quicksort
// n
// int checkequals(toOrder a, toOrder b){
//     if(strcmp(a.in, b.in) == 0 && strcmp(a.out, b.out) == 0 && a.costo == b.costo)
//         return 1;
//     else
//         return -1;
    
// }

unsigned int partition(toOrder* array, int p, int q, int pivotLocation) {	
	toOrder pivot;
	unsigned int i, j;
	
	pivot = array[pivotLocation];
	swapOrder(&array[pivotLocation], &array[q]);
	i = p;
	for(j = p; j < q; j++) if(compareT(array[j],  pivot) <= 0) swapOrder(&array[i++], &array[j]);
	swapOrder(&array[q], &array[i]);
	return i;
}

void quickSort(toOrder* array, int start, int end) {
	int r, pivot;
	if(start < end) {
		pivot = (end+start)/2;
		r = partition(array, start, end, pivot);
		if( r > start ) {
			quickSort(array, start, r-1);
		}
		quickSort(array, r+1, end);
	}
}