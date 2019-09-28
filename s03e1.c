#include <stdio.h>
#include <stdlib.h>
#define N_BIT 16
/* Scrivere un programma C che, preso in ingresso un valore intero n, ne effettui la conversione nel corrispondente numero binario
e lo memorizzi in un vettore. Se si decide di effettuare limitazioni al valore di ingresso n, assicurarsi che le stesse siano
gestite a livello di programma. Corredare il programma con gli opportuni commenti. */
int main()
{
    // dichiarazione variabili
    unsigned int num;
    int i, k, v[N_BIT], res, var, half;
    printf("Inserire un numero intero positivo da convertire in binario ");
    scanf("%d", &num);
    fflush(stdin);
    i=0;

    // ciclo per il controllo della positività del numero
    while (num<0) {
        printf("reinserire un numero");
        scanf("%ud", &num);
    }
    //aggiungo 0 alle posizioni del vettore non occupate
    while (i<N_BIT){
        // ciclo per la memorizzazione dei bit nel vettore
        while  (num!=0&&i<N_BIT)
        {
            res=(num%2);
            v[i]=res;
            //printf("%d", v[i]);
            i++;
            num= (num/2);
        }
    v[i]=0;
    i++;
    }

    // controllo sulla dimensione del numero (8 bit massimo)
    if (i>N_BIT){
            printf("il numero NON puo\' essere convertito perche\' superiore a %d bit", N_BIT);
        }
    else {
    //inversione vettore per la trasformazione in definitiva in binario
    half= (i/2);
    for (k=0; k<half ; k++){
    var=v[k];
    v[k]=v[i-1-k];
    v[i-1-k]=var;
    }
    printf("\nNumero convertito in binario:\n");

    //stampo il vettore
    for(k=0;k<i;k++){
    printf("%d",v[k]);
    }
    printf("\n");

    }
    return 0;
}
