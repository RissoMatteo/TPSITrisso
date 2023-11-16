#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_RIGHE 20000
#define DIM_RIGA 200
#define Q_PARTECIPAZIONE 100

typedef struct {
    char* data;
    char* alunno;
    int quota;  
} Segreteria;

int calcolaTot(Segreteria* alunni, int n) {
    int incassi = 0;
    for (int i = 0; i < n; i++) {
        incassi += (alunni + i)->quota;
    }
    return incassi;
}

void trovaNome(Segreteria* alunni, int n, char* io) {
    for (int i = 0; i < n; i++) {
        if (strcmp((alunni + i)->alunno, io) == 0) {
            printf("%s ha pagato %d euro di quota.\n", io, (alunni + i)->quota);
            return; 
        }
    }
    printf("%s non è stato trovato nell'elenco.\n", io);
}

void reportSituazione(Segreteria* alunni, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d", (alunni + i)->alunno, (alunni + i)->quota);
        if ((alunni + i)->quota != Q_PARTECIPAZIONE) {
            printf(" DA CONTROLLARE\n");
        } else {
            printf("\n");
        }
    }
}

int main() {
    char nomeFile[DIM_RIGA] = "4AROB_GITA.csv";
    char* riga = (char*)malloc(DIM_RIGA * sizeof(char));
    FILE* fp;
    int counter = 0;
    char* campo;

    Segreteria* alunni = malloc(NUM_RIGHE * sizeof(Segreteria));

    fp = fopen(nomeFile, "r");
    if (fp == NULL) {
        printf("Errore sull'apertura del file\n");
        exit(1);
    }

    while (fgets(riga, DIM_RIGA, fp)) {
        campo = strtok(riga, ";");
        (alunni + counter)->data = strdup(campo);

        campo = strtok(NULL, ";");
        (alunni + counter)->alunno = strdup(campo);

        campo = strtok(NULL, ";");
        (alunni + counter)->quota = atoi(campo);

        counter++;
    }

    fclose(fp);

    int tot_incassi = calcolaTot(alunni, counter);
    printf("Il totale degli incassi è: %d\n", tot_incassi);

    if (tot_incassi < 2200) {
        int mancanti = 2200 - tot_incassi;
        printf("Manca un importo di %d euro\n", mancanti);
    }

    char* io = "Risso";
    trovaNome(alunni, counter, io);

    printf("situazione:\n");
    reportSituazione(alunni, counter);

    free(alunni);
    free(riga);

    return 0;
}
