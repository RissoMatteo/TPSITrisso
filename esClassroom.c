/*
author: risso
date:
es: 1
testo:
Scrivere un programma in C che calcoli la somma degli
elementi di un array utilizzando l'aritmetica dei puntatori. Nel programma deve
essere implementata una funzione calcolaSomma()
che riceva due argomenti (la lunghezza dell'array e un puntatore), calcola la
somma degli elementi dell'array utilizzando un puntatore e
restituisce la somma calcolata. Il main()
dichiara un array, utilizza la funzione calcolaSomma() e stampa il risultato
restituito dalla funzione.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

void caricaVett(int v[], int n){
    for(int k = 0; k < n; k++){
        printf("Pos [%d]", k+1);
        scanf("%d", &*(v + k));
    }
}

int calcolaSomma(int v[], int n){
    int s = 0;
    for(int k = 0; k < n; k++){
        s += *(v + k);
    }
    return s;
}

int chiediDim(int n){
    int x;
    do{
        printf("maggiore di zero\n");
        scanf("%d", &x);
    }while(x < 0 || x > n);

    return x;
}

int main(){

    int vett[DIM];
    printf("Inserisci il numero di numeri ");
    int dim = chiediDim(DIM);
    caricaVett(vett, dim);
    int somma = calcolaSomma(vett, dim);

    printf("la somma e': %d", somma);
    return 0;
}
