#include <stdio.h>
#include <stdlib.h>
#include "Funzioni_generali.h"
#include "Lista_Coll.h"
#include "Lista_Din.h"
#include "Lista_Statica.h"

int main()
{
    int sc,con;
    //Definizione e inizializzazione dei puntatori
    Lista_dinamica *punt_din=&LISTA_DIN;
    Lista_statica *punt_stat=&LISTA_STAT;
    Lista_coll *punt_coll=NULL;
    //Tramite Scelta() l'utende piò decidere che tipo di pila utilizzare
    sc=Scelta();

    switch (sc){
        system(CLEAR);
        case 1:
            //Inizializzazione della pila
            Inizializz_Lista_Statica(&punt_stat);
            Stampa_lista_statica(punt_stat);
            for (;;){
                con=Controllo();
                switch (con){
                    case 1:
                        //Inserimento di n numeri
                        Inserimento(&punt_stat);
                        Continua();
                        Stampa_lista_statica(punt_stat);
                        continue;
                    case 2:
                        //Inserimento di un solo elemento
                        Ins_coda(&punt_stat);
                        Continua();
                        Stampa_lista_statica(punt_stat);
                        continue;
                    case 3:
                        //Cancellazione di un solo elemento
                        Elimina_dalla_coda(punt_stat);
                        Continua();
                        Stampa_lista_statica(punt_stat);
                        continue;
                    case 4:
                        //Uscita dall'esecuzione del programma
                        Stampa_lista_statica(punt_stat);
                        exit(1);
                }
        break;

        case 2:
            //Inizializzazione della pila
            Inizializz_Lista_Dinamica(&punt_din);
            Stampa_lista_dinamica(punt_din);
            for (;;){
                con=Controllo();
                switch (con){
                    case 1:
                        //Inserimento n numeri
                        Inserimento_lista_din(&punt_din);
                        Continua();
                        Stampa_lista_dinamica(punt_din);
                        break;
                    case 2:
                        //Aggiunta di un numero in coda
                        Ins_coda_din(&punt_din);
                        Continua();
                        Stampa_lista_dinamica(punt_din);
                        break;
                    case 3:
                        //Cancellazione di un elemento
                        Elimina_dalla_coda_din(&punt_din);
                        Continua();
                        Stampa_lista_dinamica(punt_din);
                        break;
                    case 4:
                        //Uscita dall'esecuzione del programma
                        Stampa_lista_dinamica(punt_din);
                        exit(1);
                }

            }
        break;

        case 3:
            //Punt coll è sempre la testa della pila
            Iniz_Lista_coll(&punt_coll);
            Stampa_Lista_Coll(punt_coll);
            for (;;){
                con=Controllo();
                switch (con){
                    case 1:
                        //Funzione inserimento n numeri
                        Crea_lista_coll(&punt_coll);
                        Continua();
                        Stampa_Lista_Coll(punt_coll);
                        break;
                    case 2:
                        //Funzione inserimento in coda
                        Ins_coda_coll(&punt_coll);
                        Continua();
                        Stampa_Lista_Coll(punt_coll);
                        break;
                    case 3:
                        //Funzione elimina dalla coda
                        Elimina_dalla_coda_coll(&punt_coll);
                        Continua();
                        Stampa_Lista_Coll(punt_coll);
                        break;

                    case 4:
                        //Stampa ed uscita
                        Stampa_Lista_Coll(punt_coll);
                        exit(1);
                }
            }
        break;
        }
    }

    return 0;
}
