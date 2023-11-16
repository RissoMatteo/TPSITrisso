#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int valore;
    struct node* next;
    
}Node ;

int calcolaLunghezza(Node* l) {
    int lunghezza = 0;
    while (l != NULL) {
        lunghezza++;
        l = l->next;
    }
    return lunghezza;
}

int main(){

    int n;
    Node* lista = NULL;
    Node* l;

    do{
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (Node*) malloc(sizeof(Node));
                l = lista;
            }else{
                l->next = (Node*) malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    
    }while (n>=0);
    
    l = lista;
    
    int lungh = calcolaLunghezza(lista);

    printf("Numeri inseriti: \n");
    while (l != NULL)
    {
        printf("%d - %p \n", l ->valore, l ->next);
        l = l->next;
    }
    printf("\n");

    printf("I numeri inseriti sono: %d", lungh);

    return 0;
} 