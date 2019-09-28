#include "Lista_Statica.h"
#include "Lista_Din.h"
#include "Lista_Coll.h"
#include "Funzioni_generali.h"

int main()
{
    //dichiarazione variabili
    int ins,ris;
    bool flag;
    numeri *l, LISTA_STAT;
    numeri_din *l_din, LISTA_DIN;
    int sc;
    /*Dichiaro un puntatore alla struttura.In particolare questo puntatore
    dalla creazione della lista manterrà sempre il collegamento con il primo nodo */
    punt_coll punt_lis;

    //FUNZIONE SCELTA
    sc=Scelta();
    switch (sc){
    //SE HAI SCELTO LISTA INDICIZZATA CON ALLOCAZIONE STATICA
    case (1):

        //Funzione che prende quanti numeri l'utente vuole inserire
        ins=Elementi_da_inserire(1);

        //se inserisco 10 elementi il vettore sarà pieno e non potrò effettuare l'inserimento dopo un certo elemento
        if (Full(ins)==1){
            printf("\nDopo l'inserimento avrai accupato tutto lo spazio disponibile nel vettore");
        }
        LISTA_STAT=Inizializz_Lista_Statica();
        l=&LISTA_STAT;
        Stampa_lista_statica(l);
        // FUNZIONE INSERIMENTO
        Inserimento(ins,l);
        Stampa_lista_statica(l);

        if (!Full(ins)){
            //INSERIMENTO ELEMENTO IN TESTA
            //controllo la correttezza della scelta
            if (Controllo(1)==true){
                //FUNZIONE INSERIMENTO IN TESTA
                Ins_testa(l);
                Stampa_lista_statica(l);
            }

            //INSERIMENTO ELEMENTO IN CODA;
            if (Controllo(2)==true){
                //FUNZIONE INSERISCI IN CODA
                Ins_coda(l);
                Stampa_lista_statica(l);
            }

            //INSERIMENTO NUMERO DOPO UN CERTO ELEMENTO
            if (Controllo(3)==true){
                //FUNZIONE INSERIMENTO DOPO UN ELEMENTO DATO IN INPUT
                ris= Ins_da_posizione(l);
                //ritorna un bool, ed in base all'output decido cosa sampare
                if (ris==true){
                    printf("Elemento inserito correttamente");
                } else printf("L'elemento non è presente nel vettore");
                Stampa_lista_statica(l);
            }

        }
        else {
        printf("Non puoi inserire un elemento in testa/coda perche\' hai esaurito lo spazio nel vettore");
        }

        //CANCELLA DALLA TESTA

        if (Controllo(4)==true){
            //FUNZIONE ELIMINA DALLA TESTA
            Elimina_dalla_testa(l);
            printf("Elemento eliminato correttamente");
            Stampa_lista_statica(l);
        }

        //CANCELLA DALLA CODA
        if (Controllo(5)==true){
            //FUNZIONE ELIMINA DALLA CODA
            Elimina_dalla_coda(l);
            printf("Elemento eliminato correttamente");
            Stampa_lista_statica(l);
        }

        //ELIMINA ELEMENTO ALLA PRIMA OCCORRENZA NEL VETTORE
        if (Controllo(6)==true){
            //FUNZIONE ELIMINA ALLA PRIMA OCCORRENZA
            ris=Elimina_prima_occorrenza(l);
            if (ris==-1){
                printf("\nL'elemento inserito non e\' presente nel vettore\n\n");
            } else printf("\nL'elemento e\' stato trovato all'indice %d ed e\' stato eliminato\n\n",ris);
            Stampa_lista_statica(l);
        }

    break;
    //SE HAI SCELTO LISTA INDICIZZATA CON ALLOCAZIONE DINAMICA
    case (2):
        //Funzione che chiede quanti elementi l'utente inzialmente vuole inserire
        ins=Elementi_da_inserire(2);

        //Creo la lista dinamica con elementi iniziali scelti dall'utente
        LISTA_DIN=Crea_lista_dinamica(ins);
        l_din=&LISTA_DIN;
        Stampa_lista_dinamica(l_din);
        // FUNZIONE INSERIMENTO
        Inserimento_lista_din(l_din,ins);
        Stampa_lista_dinamica(l_din);
        //flag mi servirà per scegliere se reallocare spazio o no
        flag=false;
        //INSERIMENTO ELEMENTO IN TESTA
        if (Controllo(1)==true){

            //FUNZIONE REALLOC CHE RADDOPPIA LO SPAZIO DEL VETTORE
            //Controllo che la riallocazione sia terminata con successo
            flag=Raddoppio_din(l_din);
            if (flag==true){
                printf("\nSpazio reallocato con successo. Dimensione: %d\n\n",l_din->size_din);
            }
            else {
                printf("\nSpazio in memoria insufficiente\n\n");
                break;
            }

            //FUNZIONE INSERIMENTO IN TESTA
            Ins_testa_din(l_din);
            Stampa_lista_dinamica(l_din);
        }

        if (Controllo(2)==true){
            //Se flag==false non è ancora stato reallocato spazio
            if (flag==false){
                flag=Raddoppio_din(l_din);
                if (flag){
                    printf("\nSpazio reallocato con successo. Dimensione: %d\n\n",l_din->size_din);
                }
                else {
                    printf("\nSpazio in memoria insufficiente\n\n");
                    break;
                }
            }
            //FUNZIONE INSERIMENTO IN CODA
            Ins_coda_din(l_din);
            Stampa_lista_dinamica(l_din);
        }
        if (Controllo(3)==true){
            //Se flag==false non è ancora stato reallocato spazio
            if (flag==false){
                flag=Raddoppio_din(l_din);
                if (flag){
                    printf("\nSpazio reallocato con successo. Dimensione: %d\n\n",l_din->size_din);
                }
                else {
                    printf("\nSpazio in memoria insufficiente\n\n");
                    break;
                }
            }
            //FUNZIONE INSERIMENTO INSERIMENTO DOPO UN ELEMENTO
            Ins_da_posizione_din(l_din);
            Stampa_lista_dinamica(l_din);
        }
        if (Controllo(4)==true){
            //Se flag==false non è ancora stato reallocato spazio
            if (flag==false){
                flag=Raddoppio_din(l_din);
                if (flag){
                    printf("\nSpazio reallocato con successo. Dimensione: %d\n\n",l_din->size_din);
                }
                else {
                    printf("\nSpazio in memoria insufficiente\n\n");
                    break;
                }
            }
            //FUNZIONE ELIMINA DALLA TESTA
            Elimina_dalla_testa_din(l_din);
            Stampa_lista_dinamica(l_din);
        }
        if (Controllo(5)==true){
            //FUNZIONE ELIMINA DALLA CODA
            Elimina_dalla_coda_din(l_din);
            Stampa_lista_dinamica(l_din);
        }
        if (Controllo(6)==true){
            //FUNZIONE ELIMINA ALLA PRIMA OCCORRENZA
            Elimina_prima_occorrenza_din(l_din);
        }

    Stampa_lista_dinamica(l_din);

    break;
    case (3):

    //FUNZIONE INIZIALIZZAZIONE STRUTTURA COLLEGATA
    punt_lis=Iniz_Lista_coll();
    //FUNZIONE STAMPA LISTA COLLEGATA
    Stampa_Lista_Coll(punt_lis);

    //Funzione che chiede quanti numeri l'utente vuole inserire
    ins=Elementi_da_inserire(3);

    //FUNZIONE CREA LISTA COLLEGATA
    punt_lis=Crea_lista_coll(ins);
    Stampa_Lista_Coll(punt_lis);

    if (Controllo(1)==true){
        //FUNZIONE INSERISCI IN TESTA
        //punt_lis prende il nuvo elemento inserito in testa
        punt_lis=Ins_testa_coll(punt_lis);
        Stampa_Lista_Coll(punt_lis);
    }
    if (Controllo(2)==true){
        //FUNZIONE INSERISCI IN CODA
        Ins_coda_coll(punt_lis);
        Stampa_Lista_Coll(punt_lis);
    }
    if (Controllo(3)==true){
        //FUNZIONE INSERISCI UN NUMERO DOPO LA PRIMA OCCORRENZA
        if (Ins_da_posizione_coll(punt_lis)==false){
            printf("\nL'elemento inserito non e\' presente nella lista\n\n");
        } else printf("\nIl nuovo elemento e\' stato inserito con successo\n\n");

        Stampa_Lista_Coll(punt_lis);
    }
    if (Controllo(4)==true){
        //FUNZIONE ELIMINA DALLA TESTA
        punt_lis=Elimina_dalla_testa_coll(punt_lis);
        Stampa_Lista_Coll(punt_lis);
    }
    if (Controllo(5)==true){
        //FUNZIONE ELIMINA DALLA CODA
        Elimina_dalla_coda_coll(punt_lis);
        Stampa_Lista_Coll(punt_lis);
    }
    if (Controllo(6)==true){
        //FUNZIONE ELIMINA LA PRIMA OCCORRENZA
        punt_lis=Elimina_prima_occorrenza_coll(punt_lis);
        Stampa_Lista_Coll(punt_lis);
    }


    //Fine switch
    }
    return 0;
}
