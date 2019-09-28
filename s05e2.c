#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    //dichiarazione variabili
    unsigned char v[100], *p_v, err[100], *p_err, *p_v_uno;
    bool flag;
    //inizializzazione variabili
    flag=1;
    p_v=v;
    p_err=err;

    printf("Inserisci testo della canzone: ");
    //esegui un ciclo while che analizza i caratteri di inserimento uno ad uno fino a che premo invio
    while ((*p_v=getchar())!='\n'){
        /*se l'elemento a cui p_v punta è un numero intero allora lo assegno al vettore err,
        incremento allora p_err per rendere il vettore eventualmente disponibile per un nuovo numero che verrà inserito */
        if (isdigit(*p_v)!=0){
        //flag decide se stampare il testo in maiuscolo senza spazi o segnalare un errore dovuto all'inserimento di numeri
        flag=0;
        *p_err=*p_v;
        p_err++;
        // inserisco f alla posizione incrementata che mi permetterà in seguito di eseguire un ciclo fino a che *p_err!='f' (vedi r.58)
        *p_err='f';
        }
    //incremento la posizione del vettore v
    p_v++;
    }

    //rinizializzo le variabili
    p_v=v;
    p_err=err;
    //se flag==1 non sono stati inseriti numeri
    if (flag==1){
        // esegui un ciclo while finchè la posizione n del vettore è uguale a \n (invio)
        while (*p_v!='\n'){
            /* se il carattere che ho inserito è uno spazio o un segno di punteggiatura, inizializzo
            un altro puntatore che da questa posizione fino alla fine del vettore v scorre i caratteri a sinistra */
            while (isspace(*p_v)||ispunct(*p_v)){
            p_v_uno=p_v;
                while (*p_v_uno!='\n'){
                *p_v_uno=*(p_v_uno+1);
                p_v_uno++;
                }
            }
        // stampo il carattere in maiuscolo
        printf("%c",toupper(*p_v));
        p_v++;
        }
    }
    /* se flag=false hai inserito un/dei numero/i. Stampo (indirettamente) il vettore err che contiene i numeri memorizzati
    dal primo while fino a che l'elemento è uguale a f */
    else {
    printf("I numeri non sono supportati. Hai inserito: ");
       while (*p_err!='f'){
        printf("%c ",*p_err);
        p_err++;
        }
    }
    return 0;

}
