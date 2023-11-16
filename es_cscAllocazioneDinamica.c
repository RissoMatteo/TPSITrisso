/*
author:
date:
es:
testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_RIGHE 100
#define DIM_RIGA 200

typedef struct{
    int numero;
    char* titolo;   //char 10
    char* genere;
    int anno;
    char* disponibilita;
}film;

int main()
{
    char nomeFilm[] = "listafilm.csv";
    FILE *fp;
    char* campo;
    char riga = (char*) malloc (DIM_RIGA * sizeof(char));
    film* array_film = malloc(NUM_RIGHE * sizeof(film));
    int counter = 0;

    fp = fopen(nomeFilm, "r");
    if(fp == NULL){
        printf("Il file %s non esiste\n", nomeFilm);
        exit(1);
    }
    while(fgets(riga, DIM_RIGA, fp))
    {
        campo = strtok(riga, ",");
        (array_film + counter)->numero = atoi(campo);  //atoi trasforma una stringa in numero int quindi il primo campo che � un numero lo traformiamo, atof converte stringa in numero float

        campo = strtok(NULL, ",");
        (array_film + counter)->titolo = strdup(campo); //returna la copia della stringa

        campo = strtok(NULL, ",");
        (array_film + counter)->genere = strdup(campo);

        campo = strtok(NULL, ",");
        (array_film + counter)->anno = atoi(campo);

        campo = strtok(NULL, ",");
        (array_film + counter)->disponibilita = strdup(campo);

        printf("%d %s %s %d %s\n", (array_film + counter)->numero,(array_film + counter)->titolo, (array_film + counter)->genere, (array_film + counter)->anno, (array_film + counter)->disponibilita);
        counter++;
    }
        printf("Il numero di righe e: %d", counter);

    fclose(fp);
    return 0;
}