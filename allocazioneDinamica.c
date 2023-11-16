#include <stdio.h>
#include <stdlib.h>
/*
per alloracre dinamicamente un array in memoria usiamo la funzione malloc() -> memory allorcation.
malloc() restituisce un puntatore e non sa che tipo di puntatore gli passiamo quindi returna sempre un puntatore a void, quindi se 
volessimo un arrey di interi dobbiamo fare il casting a int
*/

//esempio:

int main(){
    int *p;
    
    p = (int*) malloc(5 * sizeof(int));
    //(5 * sizeof(int)) -> questo parametro è lo spazio in memoria occupato dall array, NON QUANTO È LUNGO
    //metto size of int perche p è dichiarata in int, fosse una struttura metteremmo in nome di come abbiamo dichiarato la struct
    free(p);
    return 0;
}