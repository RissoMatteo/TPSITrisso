/*
testo:
-Creare un file .csv con COGNOME, NOME, NASCITA (annomesegiorno in formato INT)
-scorrere il file con la funzione FGETS e STRTOK
-stampare in ordine DECRESCENTE (dal più grande al più piccolo)
 utilizzando i puntatori e allocazione dinamica (MALLOC)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_RIGHE 100
#define DIM_RIGA 200

typedef struct{
    int giorno;
    int mese;
    int anno
}Data;


typedef struct{
    char* cognome;
    char* nome;
    Data dataPersona;
}Persona;

void scambiaPersone(Persona *a, Persona *b)
{
    Persona temp = *a;
    *a = *b;
    *b = temp;
}

void ordinaStruttura(Persona *pers, int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if ((pers + j)->dataPersona.anno < (pers + j)->dataPersona.anno){
                scambiaPersone(pers + j, pers + j + 1);
            }
        }
    }
}

int main(){
    char nomeFile[] = "sintesi.csv";
    FILE *fp;
    char* campo;
    char riga[DIM_RIGA];
    Persona* pers= malloc(NUM_RIGHE * sizeof(Persona));
    int counter = 0;

    fp = fopen(nomeFile, "r");
    if(fp == NULL){
        printf("Il file %s non esiste\n", nomeFile);
        exit(1);
    }
    while(fgets(riga, DIM_RIGA, fp))
    {
        campo = strtok(riga, ",");
        (pers + counter)->cognome = strdup(campo);  //atoi trasforma una stringa in numero int quindi il primo campo che � un numero lo traformiamo, atof converte stringa in numero float

        campo = strtok(NULL, ",");
        (pers + counter)->nome = strdup(campo); //returna la copia della stringa

        campo = strtok(NULL, ",");
        (pers+ counter)->dataPersona.giorno = atoi(campo);

        campo = strtok(NULL, ",");
        (pers + counter)->dataPersona.mese = atoi(campo);

        campo = strtok(NULL, ",");
        (pers + counter)->dataPersona.anno = atoi(campo);

        printf("%s %s  %d / %d / %d\n", (pers + counter)->cognome,(pers + counter)->nome, (pers + counter)->dataPersona.giorno, (pers + counter)->dataPersona.mese, (pers + counter)->dataPersona.anno);
        counter++;
    }
    fclose(fp);

    ordinaStruttura(pers, counter);

     for (int i = 0; i < counter; i++){
        printf("%s %s %d / %d / %d\n", (pers + i)->cognome, (pers + i)->nome, (pers + i)->dataPersona.giorno, (pers + i)->dataPersona.mese, (pers + i)->dataPersona.anno);
    }

    for (int i = 0; i < counter; i++) {
        free((pers + i)->cognome);
        free((pers + i)->nome);
    }
    free(pers);

    return 0;
}