#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Scrivi un programma in linguaggio C che
gestisca un archivio di libri. Il programma deve utilizzare una struttura Libro per rappresentare ciascun libro, con le seguenti
informazioni:
-Titolo (massimo 100 caratteri)
-Autore (massimo 100 caratteri)
-Anno di pubblicazione
Il programma deve consentire all'utente
di eseguire le seguenti operazioni:
-Stampare l'archivio dei libri:
-Stampa tutte le informazioni sui libri presenti nell'archivio.
-Stampa l’archivio dei libri pubblicati in un certo anno.
-Stampa tutti i libri pubblicati in ordine di anno.
Assicurati che il programma gestisca
correttamente la memoria dinamica e che non ci siano perdite di memoria.
Inoltre, gestisci eventuali errori nell'apertura del file CSV.
Ricorda di fornire un'interfaccia utente
chiara e intuitiva per consentire all'utente di eseguire queste operazioni.
*/
#define LUNG 100;
#define MAX_RIGHE 100;

struct
{
    char Titolo[LUNG];
    char Autore[LUNG];
    char AnnoDiPubblicazione[LUNG];
}Libro;

int main(){
    char nomeFile[] = "listalibri.csv";
    char riga = (char*) malloc (MAX_RIGHE * sizeof(char));
    Libro* archivio = malloc(MAX_RIGHE * sizeof(Libro));

    
    fp = fopen(nomeFile, "r");
    if(fp == NULL){
        printf("Il file %s non esiste\n", nomeFile);
        exit(1);
    }
    while(fgets(riga, MAX_RIGHE, fp))
    {
        campo = strtok(riga, ",");
        (archivio + counter)->Titolo = strdup(campo);

        campo = strtok(NULL, ",");
        (archivio + counter).Autore = strdup(campo);

        campo = strtok(NULL, ",");
        (archivio + counter)->AnnoDiPubblicazione = atoi(campo); 

        counter++;
    }
    fclose(fp);
    
    do{
    printf("Scegli:\n");
    printf("0-Stampare l'archivio dei libri\n");
    printf("1-Stampa tutte le informazioni sui libri presenti nell'archivio\n");
    printf("2-Stampa l’archivio dei libri pubblicati in un certo anno\n");
    printf("3-Stampa tutti i libri pubblicati in ordine di anno\n");
    printf("4-esci\n");
    int scelta = 0;
    scanf("%d", &scelta);
    }while (scelta != 0);
    
    


    return 0;
}

