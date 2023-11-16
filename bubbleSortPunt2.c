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
    int k, sup, sca;
    int *p = vett;

    sup = n - 1;

    while (sup > 0) {
        sca = 0;

        for (p = vett; p < vett + sup; p++) {
            if (*p > *(p + 1)) {
                scambio(p, p + 1);
                sca = p - vett;  //quante celle ho fatto dall inizio del vettore
            }
        }

        sup = sca;
    }
}

void caricaVett(int v[], int n){
    int *p = v;
    for(p = v; p < v + n; p++){
        scanf("%d", p);
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
    int *p = v;
    for(p = v; p < (v + n); p++){
        printf("%d", *p);
    }
}

int main(){
    int v[DIM];
    printf("inserisci la dimensione ");
    int dim = chiediDim(DIM);
    caricaVett(v, dim);
    bubbleSort3(v, dim);
    printf("vetore ordinato: \n");
    stampaVett(v, dim);

    return 0;
}