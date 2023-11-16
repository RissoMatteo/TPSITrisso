/*
author:
date:
es:
testo:
*/

#include <stdio.h>
#include <stdlib.h>
#define LUNG 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    // Apri il file in modalit� di lettura
    FILE *file = fopen("listafilm.csv", "r");

    // Verifica se il file � stato aperto correttamente
    if (file == NULL) {
        perror("Impossibile aprire il file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    // Leggi il file linea per linea
    while (fgets(line, sizeof(line), file)) {
        // Utilizza strtok per suddividere la linea in token basati su uno spazio
        char *token = strtok(line, " ");

        // Stampa ciascun token
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, " ");
        }
    }

    // Chiudi il file
    fclose(file);

    return 0;
}
