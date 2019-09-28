#include "Funzioni_generali.h"
#define N 10
int Controllo(){
    int choose;
    //Per ogni valore preso stampo in base alla parte di programma a cui mi riferisco
    printf("\n\tOperazioni\n\n");

    printf("\t1- Inserimento insieme di elementi\n\n");
    printf("\t2- Inserimento di un solo elemento\n\n");
    printf("\t3- Cancellazione di un elemento\n\n");
    printf("\t4- Uscita dal programma\n\n");
    printf("\tScelta: ");
    scanf("%d",&choose);
    fflush(stdin);
    while (choose!=1&&choose!=2&&choose!=3&&choose!=4){
        printf("\nNumero scelta inesistente, reinserire: ");
        scanf(" %d",&choose);
        fflush(stdin);
    }
    return (choose);
}

int Scelta(){
    int scelta;
    printf("Inserisci il tipo di lista:\n\n\t1-Indicizzata con vettore statico\n\n\t2-Indicizzata con vettore dinamico\n\n\t3-Collegata\n\nNumero scelta: ");
    scanf("%d",&scelta);
    fflush(stdin);
    while (scelta<=0||scelta>3){
        printf("\nScelta non valida, reinserire: ");
        scanf("%d",&scelta);
        fflush(stdin);
    }
    return scelta;
}

int Elementi_da_inserire(int par){
    int num_iniz;
    if (par==1){
        printf("\nQuanti numeri vuoi inserire? (min 1 max %d): ",N);
        scanf("%d",&num_iniz);
        fflush(stdin);
        printf("\n");
        //Controllo che l'utente inserisca un numero compreso tra 1 e 10
        while (num_iniz>N||num_iniz<=0){
            printf("\nNumero non valido, reinserire: ");
            scanf("%d",&num_iniz);
            fflush(stdin);
        }
    }
    else if (par==2||par==3) {
        printf("\nQuanti elementi vuoi inserire?: ");
        scanf("%d",&num_iniz);
        fflush(stdin);
        while (num_iniz<=0){
            printf("\nNumero non valido, reinserire: ");
            scanf("%d",&num_iniz);
            fflush(stdin);
        }
    }

    return num_iniz;
}
void Continua(){
    printf("\n\nPremi un tasto per continuare. . .\n");
    getchar();
    system(CLEAR);
}

