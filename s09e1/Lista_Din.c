#include "Lista_Din.h"
#define RADD 4
//FUNZIONI LISTA DINAMICA


numeri_din Crea_lista_dinamica(int num_el_din){
    // Inizializzo le variabili della struttura
    numeri_din temp={NULL,0,0};
    //Alloco spazio pari al numero di elementi che vuole inserire l'utente
    temp.num_din=(tipoel*)malloc(num_el_din*sizeof(tipoel));
    //Controllo che l'allocazione sia terminata con successo
    if (temp.num_din==NULL){
        printf("Spazio insufficiente per l'allocazione di %d elementi\n",num_el_din);
    }
    else {
        temp.size_din=num_el_din;
    }
    return temp;
}

void Inserimento_lista_din(numeri_din *punt_inserimento_din,int fine){
    int el,tempo;
    /*Ho scelto di usare come contatore l'intero last della lista dinamica e un intero "fine" che passerà il numero di elementi che si vuole inserire.
    La funzione è così riutilizzabile per l'inserimento quando il vettore num_din sarà reallocato.
    Perchè ho usato "fine" invece che size? Alla prima chiamata di questa funzione, "fine" è uguale a size, ma alla seconda (quando si vuole espandere il vettore)
    size raddoppia di dimensione e l'utente può non voler aggiungere tutta la seconda metà del vettore, ecco perchè ho bisogno di una variabile d'appoggio. . */
    tempo=punt_inserimento_din->last_din+fine;
    while (punt_inserimento_din->last_din<tempo){

        //Inserimento nuovo elemento
        printf("\nInserisci intero da inserire nella posizione %d: ",punt_inserimento_din->last_din);
        scanf("%d",&el);
        fflush(stdin);
        punt_inserimento_din->num_din[punt_inserimento_din->last_din]=el;

        //Incremento il last: dalla seconda chiamata in poi di questa funzione verranno aggiunti "fine" elementi dopo il last
        punt_inserimento_din->last_din++;
    }
}

bool Raddoppio_din(numeri_din *punt_lista_din){
    tipoel *punt_radd;

    /* Realloco il vettore raddoppiando la dimensione: la realloc è un'operazione costosa quindi invece che reallocare ogni volta che si vuole inserire in
    testa/coda/dopo un certo elemento,lo faccio una volta sola */
    //Se size <=2 anche raddoppio lo spazio, non basterebbe per le altre operazioni quindi aggiungo un valore fisso uguale a 4
    if (punt_lista_din->size_din<=2){
        punt_radd=realloc(punt_lista_din->num_din,((punt_lista_din->size_din*2)+RADD)*sizeof(tipoel));
    }
    else {
        punt_radd=realloc(punt_lista_din->num_din,((punt_lista_din->size_din*2)*sizeof(tipoel)));
    }
    //Se la reallocazione è terminata con successo: espandi size, il vettore num e return true. Return false altrimenti
    if (punt_radd!=NULL){
        punt_lista_din->size_din*=2;
        punt_lista_din->num_din=punt_radd;
        return true;
    }else return false;
}

void Ins_testa_din(numeri_din *punt_ins_testa_din){
    int el_ins_testa, conta_din;
    // Inserimento elemento
    printf("Elemento da inserire in testa: ");
    scanf("%d",&el_ins_testa);
    fflush(stdin);

    for (conta_din=punt_ins_testa_din->last_din;conta_din>0;conta_din--){
        punt_ins_testa_din->num_din[conta_din]=punt_ins_testa_din->num_din[conta_din-1];
    }
    //Terminato il ciclo conta_din è uguale 0 quindi posso inserire il nuovo elemento
    punt_ins_testa_din->num_din[conta_din]=el_ins_testa;
    //Incremento il last di una posizione
    punt_ins_testa_din->last_din++;

    printf("\nElemento inserito con successo\n");
}
void Ins_coda_din(numeri_din *punt_ins_coda_din){
    int el_ins_coda;
    // Inserimento elemento
    printf("\nElemento da inserire in coda: ");
    scanf("%d",&el_ins_coda);
    fflush(stdin);
    //Inserisco l'elemento nel last e successivamente lo incremento
    punt_ins_coda_din->num_din[punt_ins_coda_din->last_din]=el_ins_coda;
    punt_ins_coda_din->last_din++;

    printf("\nElemento inserito con successo\n");
}

void Elimina_dalla_testa_din(numeri_din *punt_elimina_da_testa_din){
    int i;
    /*L'elemento corrente (partendo dal primo) prende il successivo:
    il valore del primo elemento non viene assunto da nessuno*/
    for (i=0;i<punt_elimina_da_testa_din->last_din;i++){
        punt_elimina_da_testa_din->num_din[i]=punt_elimina_da_testa_din->num_din[i+1];
    }
    //Il penultimo elemento è uguale all'ultimo quindi porto a 0 l'ultimo elemento e decremento il last
    punt_elimina_da_testa_din->num_din[i]=0;
    punt_elimina_da_testa_din->last_din--;

    printf("\nElemento eliminato con successo\n");
}

void Elimina_dalla_coda_din(numeri_din *punt_elimina_da_coda_din){
    // Prendo il vettore alla posizione last-1 (corrispondente all'ultimo elemento) e lo pongo a NULL
    punt_elimina_da_coda_din->num_din[punt_elimina_da_coda_din->last_din-1]=0;
    // Decremento il last
    punt_elimina_da_coda_din->last_din--;
    printf("\nElemento eliminato con successo\n");
}

void Ins_da_posizione_din(numeri_din *punt_posiz_din){
    int i, el_nuovo_din, el_pos_din;
    printf("\nInserisci elemento gia\' presente: ");
    scanf("%d",&el_pos_din);
    fflush(stdin);
    printf("\nInserisci nuovo elemento: ");
    scanf("%d",&el_nuovo_din);
    fflush(stdin);
    for (i=0;i<punt_posiz_din->last_din;i++){
        if (punt_posiz_din->num_din[i]==el_pos_din){
            for (int t=punt_posiz_din->last_din;t>i;t--){
                punt_posiz_din->num_din[t]=punt_posiz_din->num_din[t-1];
            }
            punt_posiz_din->num_din[i+1]=el_nuovo_din;
            break;
        }
    }
    if (i==punt_posiz_din->last_din){
        printf("\nL'elemento %d non e\' presente nel vettore\n",el_pos_din);
    }
    else {
        printf("\nL'elemento %d e\' stato trovato e %d e\' stato aggiunto alla posizione %d\n",el_pos_din,el_nuovo_din,i);
        punt_posiz_din->last_din++;
    }
}

void Elimina_prima_occorrenza_din(numeri_din *punt_elimina_prima_occ_din){
    int i,k,el_da_canc_din;
    printf("\nInserisci il numero all'interno della lista da eliminare: ");
    scanf("%d",&el_da_canc_din);
    fflush(stdin);
    for (i=0;i<punt_elimina_prima_occ_din->last_din;i++){
        if (punt_elimina_prima_occ_din->num_din[i]==el_da_canc_din){
            for (k=i;k<punt_elimina_prima_occ_din->last_din;k++){
                punt_elimina_prima_occ_din->num_din[k]=punt_elimina_prima_occ_din->num_din[k+1];
            }
            break;
        }
    }
    if (i==punt_elimina_prima_occ_din->last_din){
        printf("\nL'elemento %d non e\' presente nel vettore\n",el_da_canc_din);
    }
    else{
        printf("\nL'elemento %d (posizione: %d) e\' stato eliminato\n",el_da_canc_din,i);
        punt_elimina_prima_occ_din->last_din--;
    }
}

void Stampa_lista_dinamica(numeri_din *lista_dinamica){
    printf("\n\n----------------------------------------------------------------------------------");
    printf("\n\t\t\t\tLISTA:\n\n");
    printf("\tVettore: ");
    for (int i=0;i<lista_dinamica->last_din;i++){
        printf("%d) %d\t",i,lista_dinamica->num_din[i]);
    }
    printf("\n\tLast: %d",lista_dinamica->last_din);
    printf("\n\tDimensione: %d\n",lista_dinamica->size_din);
    printf("\n\n----------------------------------------------------------------------------------");
}

