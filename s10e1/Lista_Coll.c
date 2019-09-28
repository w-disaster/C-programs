#include "Lista_Coll.h"

void Iniz_Lista_coll(Lista_coll **punt_iniz_coll){
    // Inizializzo come vuota la pila
    //(*punt_iniz_coll)->num=NULL;
    (*punt_iniz_coll)=NULL;
}
void Crea_lista_coll(Lista_coll **punt_crea){
    //Se non è stato inserito ancora alcun elemento, testa punta a NULL
    Lista_coll *testa=(*punt_crea);
    //paux viene usato per allocare spazio
    Lista_coll *paux;
    int i,k=0,el,num_el_coll;
    //Se sono già state inserite strutture, allora scorri la pila e ferma la testa quando hai raggiunto l'ultima
    if (testa!=NULL){
        for(;testa->next!=NULL;testa=testa->next,k++);
        //k verrà stampato quando l'utente dovrà inserire i numeri ed indicherà il numero dell'elemento che verrà memorizzato
        k++;
    }

    printf("\nQuanti numeri vuoi inserire?: ");
    scanf("%d",&num_el_coll);
    for (i=0;i<num_el_coll;i++) {
        //Alloco memoria pari a quella che necessita una struttura di tipo lista_coll
        paux= (Lista_coll*)malloc(sizeof(Lista_coll));
        if (paux==NULL){
            printf("\nMemoria insufficiente per l'allocazione di un'altra struttura\n");
            exit(1);
        }
        printf("\nInserisci intero (posizione: %d) : ",k);
        scanf("%d",&el);
        fflush(stdin);
        paux->num_coll=el;
        //Se ho creato la prima struttura in assoluto, il next di questa è NULL (primo e ultimo elemento della pila)
        if (testa==NULL){
            paux->next=testa;
            //La testa originale della pila punta ad il primo elemento creato
            (*punt_crea)=paux;
        } else {
            /*Altrimenti ne è già stata creata una precedentemente perciò: 1) La nuova punta
            alla precedente (NULL) 2) Il next della precedente punta a quella nuova*/
            paux->next=testa->next;
            testa->next=paux;
        }
        //Testa, diversamente quando la pila è vuota punta sempre al penultimo elemento creato. Alla fine del ciclo viene incremenetata
        testa=paux;
        k++;
    }
    printf("\n\nNumero/i inserito/i con successo\n\n");
}
void Stampa_Lista_Coll(Lista_coll *punt_stampa){
    int i;
    printf("\n\n----------------------------------------------------------------------------------");
    printf("\n\t\t\t\tLISTA:\n\n");
    for (i=0;punt_stampa!=NULL;punt_stampa=punt_stampa->next,i++){
        printf("%d) %d  ",i,punt_stampa->num_coll);
    }
    printf("\n\n----------------------------------------------------------------------------------");
}

void Ins_coda_coll(Lista_coll **punt_coda){
    Lista_coll *tmp;
    //Dichiaro un nuovo puntatore a struttura list_coll
    Lista_coll *new_node;
    //Alloco spazio sufficente per contenere una struttura di tipo lista_coll
    new_node=(Lista_coll*)malloc(sizeof(Lista_coll));
    //Controllo che l'allocazione sia terminata con successo
    if (new_node==NULL){
        printf("\nMemoria insufficiente per l'allocazione di un nuovo nodo\n");
        exit(1);
    }
    if (*punt_coda==NULL){
        //Se ho creato la prima struttura in assoluto, il suo next è uguale a NULL
        new_node->next=*punt_coda;
        //La testa della pila punta ad il primo elemento creato
        (*punt_coda)=new_node;
    }
    else {
        //Porto il puntatore passato come parametro all'ultimo nodo della lista
        for(tmp=*punt_coda;tmp->next!=NULL;tmp=tmp->next){
        }
        //Modifico il next del nuovo nodo facendolo puntare a che cosa punta il puntatore dell'ultimo elemento
        new_node->next=tmp->next;
        //Faccio diventare l'ultimo nodo della lista il penultimo
        tmp->next=new_node;
    }
    //Insermiento nuovo numero
    printf("\nNumero da inserire in coda: ");
    scanf("%d",&new_node->num_coll);
    fflush(stdin);
    printf("\nNumero inserito con successo\n\n");
}

void Elimina_dalla_coda_coll(Lista_coll **corr){
    Lista_coll *prec,*cur;
    if (*corr!=NULL){
        //Scorri la pila finchè il next è diverso da null.
        //prec prende il puntatore corrente e successivamente incremento quest'ultimo. NB: prec manterrà sempre il nodo precendete del corrente
        for(prec=NULL,cur=*corr;cur->next!=NULL;prec=cur,cur=cur->next){
        }

        //Elimino il nodo corrente con il next==NULL (fine della pila)
        free(cur);
        if (prec!=NULL){
            //Pongo il last dell'elemento precedente a NULL
            prec->next=NULL;
        } else {
            Iniz_Lista_coll(corr);
        }
        printf("\n\nElemento eliminato con successo\n\n");
    }
    else {
    printf("\n\nNon e'\ stato eliminato alcun elemento perche\' la pila e\' vuota\n\n");
    }
}
