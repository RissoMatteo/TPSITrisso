#include <stdio.h>
#include <stdlib.h>

#define DIM 100

void scambio(int *x, int *y){
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

void bubbleSort3(int vett[], int n) {
    int k,sup,sca;
    sup= n-1 ;
    while ( sup>0 ) {
        sca=0 ;
        for (k = 0; k < sup ; k++) {
            if (*(vett + k) > *(vett + k + 1)){
                scambio(vett + k, vett + k + 1);
                sca=k ;
            }
        }
    sup=sca;
    }
}

void caricaVett (int v[], int n){
    for(int k = 0; k < n; k++){
        printf("Pos [%d]", k+1);
        scanf("%d", &*(v + k));
    }
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
    int dim = chiediDim(DIM);
    printf("inserisci la dimensione ");
    caricaVett(v, dim);
    bubbleSort3(v, dim);
    printf("vetore ordinato: \n");
    stampaVett(v, dim);

    return 0;
}