#include <stdio.h>
#include <stdlib.h>

#define DIM 100

void caricaVett(int v[], int n){
    int *p = v;
    for(p = v; p < v + n; p++){
        scanf("%d", p);
    }
}

int sommaVett(int v[], int n){
    int somma = 0;
    int *p = v;
    for(p = v; p < v + n; p++){
        somma += *p;
    }

    return somma;
}

int chiediDim(int n){
    int x;
    do{
        printf("maggiore di zero\n");
        scanf("%d", &x);
    }while(x < 0 || x > n);

    return x;
}

void stampaVett(int v[], int n){
    for(int k = 0; k < n; k++){
        printf("%d", *(v + k));
    }
}

int main(){
    int v[DIM];
    printf("inserisci la dimensione ");
    int dim = chiediDim(DIM);
    printf("Carica il vettore: \n");
    caricaVett(v, dim);
    int somma = sommaVett(v, dim);
    printf("La somma e': %d", somma);
    return 0;
}