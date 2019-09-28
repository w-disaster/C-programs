#include "Funzioni_generali.h"

bool Controllo(int tipo_out){
    char choose;
    //Per ogni valore preso stampo in base alla parte di programma a cui mi riferisco
    switch (tipo_out){
        case 1:
            printf("\n\nVuoi inserire nuovo libro? (y/n): ");
            break;
        case 2:
            printf("\n\nVuoi cancellare un libro? (y/n): ");
            break;
        case 3:
             printf("\n\nVuoi visualizzare un libro? (y/n): ");
             break;
        case 4:
            printf("\n\nVuoi visualizzare tutti i libri? (y/n): ");
            break;
        case 5:
            printf("\n\nVuoi visualizzare i libri con un certo feedback? (y/n): ");
            break;
    }
    //Se non prendi yes e neanche not, reinserisci
    scanf(" %c",&choose);
    fflush(stdin);
    while (choose!='y'&&choose!='n'){
        printf("\nFormato input non supportato, reinserire: ");
        scanf(" %c",&choose);
        fflush(stdin);
    }
    if (choose=='y'){
        return true;
    }
    else{
    return false;
    }
}



int Elementi_da_inserire(){
    int libri_iniz;
    printf("Quanti libri vuoi inserire?: ");
    scanf("%d",&libri_iniz);
    fflush(stdin);
    //Controllo che l'utente inserisca un numero compreso tra 1 e 10
    while (libri_iniz<=0){
        printf("\nNumero non valido, reinserire: ");
        scanf("%d",&libri_iniz);
        fflush(stdin);
    }
    return libri_iniz;
}

