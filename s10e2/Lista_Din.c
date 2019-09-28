#include "Lista_Din.h"
#define RADD 4
//FUNZIONI LISTA DINAMICA
void Inizializz_Lista_Dinamica(Lista_dinamica **punt_iniz){
(*punt_iniz)->num_din=NULL;
(*punt_iniz)->last_din=-1;
(*punt_iniz)->size_din=NULL;
}
void Crea_lista_dinamica(Lista_dinamica *punt_crea,int num_el_din){
    punt_crea->last_din=-1;
    //Alloco spazio pari al numero di elementi che vuole inserire l'utente
    if (num_el_din>10){
        punt_crea->num_din=(tipoel*)malloc(20*sizeof(tipoel));
    }
    else{
        punt_crea->num_din=(tipoel*)malloc(10*sizeof(tipoel));
    }
    //Controllo che l'allocazione sia terminata con successo
    if (punt_crea->num_din==NULL){
        printf("Spazio insufficiente per l'allocazione di %d elementi\n",num_el_din);
    }
    else {
        if (num_el_din>10)
            punt_crea->size_din=20;
        else
            punt_crea->size_din=10;
    }
    Stampa_lista_dinamica(punt_crea);
}

void Inserimento_lista_din(Lista_dinamica *punt_ins){
    int el,pos,tmp;
    int n_el;
    printf("\nQuanti numeri vuoi inserire?: ");
    scanf("%d",&n_el);
    fflush(stdin);
    while (n_el<1){
        printf("\nNumero troppo piccolo, reinserire: ");
        scanf("%d",&n_el);
        fflush(stdin);
    }
    //Funzione che alloca la lista in memoria se l'utente non ha inserito alcun numero (last==-1)
    if (punt_ins->last_din==-1){
        Crea_lista_dinamica(punt_ins,n_el);
    }
    if (punt_ins->last_din+n_el>=punt_ins->size_din){
        if (Raddoppio_din(punt_ins)!=true){
            printf("Spazio in memoria insufficiente per l'allocazione di altri %d numeri",n_el);
            exit(1);
        }
    }
    if (n_el!=0){
        if (punt_ins->last_din==-1){
            punt_ins->last_din=n_el-1;
            tmp=punt_ins->last_din;
        }
        else {
            /*Dato che inseriamo sempre in testa, dobbiamo scorrere tutti gli elementi già presenti
            di n posizioni con n pari al numero di elementi che vogliamo inserire, quindi:
            1) viene preso il last corrente (pos) ed il last incrementato del nuovo numero di elementi ancora
            da inserire (tmp); 2) eseguo un ciclo dove il vettore alla posizione tmp prende il numero alla
            posizione pos, decrementandoli alla fine di una istanza.*/
            pos=punt_ins->last_din;
            punt_ins->last_din+=n_el-1;
            for (tmp=punt_ins->last_din;pos>=0;tmp--,pos--){
                punt_ins->num_din[tmp]=punt_ins->num_din[pos];
            }
            //Incremento infine tmp perchè è la posizione dove finalmente posso aggiungere i nuovi numeri
            tmp++;
        }
        for (;tmp>=0;tmp--){
            printf("\nInserisci numero (indice: %d) ",tmp);
            scanf("%d",&punt_ins->num_din[tmp]);
            fflush(stdin);
        }
        printf("\n\nNumero/i inserito/i con successo\n\n");
    }

}

bool Raddoppio_din(Lista_dinamica *punt_real){
    tipoel *punt_radd;
    punt_radd=realloc(punt_real->num_din,punt_real->size_din*2*sizeof(tipoel));
    //Se la reallocazione è terminata con successo: espandi size, il vettore num e return true. Return false altrimenti
    if (punt_radd!=NULL){
        punt_real->size_din*=2;
        punt_real->num_din=punt_radd;
        return true;
    }else return false;
}

void Ins_testa_din(Lista_dinamica *punt_testa){
    int el_ins_testa,i;
    // Inserimento elemento
    printf("\nElemento da inserire in coda: ");
    scanf("%d",&el_ins_testa);
    fflush(stdin);
    if (punt_testa->last_din==-1){
        Crea_lista_dinamica(punt_testa,1);
    }
    //Controllo che non sia esaurito lo spazio nel vettore. Se si raddoppio le dimensioni
    if (punt_testa->last_din+1>punt_testa->size_din){
        if (Raddoppio_din(punt_testa)!=true){
            printf("Spazio in memoria insufficiente per l'allocazione di un altro numero");
            exit(1);
        }
    }
    //Incremento il last
    punt_testa->last_din++;
    //Pongo l'i-esimo elemento del vettore al suo precedente e successivamente decremento i
    for (i=punt_testa->last_din;i>0;i--){
        punt_testa->num_din[i]=punt_testa->num_din[i-1];
    }
    //i alla fine del ciclo è ==0 quindi posso inserire qui il nuovo numero
    punt_testa->num_din[i]=el_ins_testa;

    printf("\nElemento inserito con successo\n");
}

void Elimina_dalla_coda_din(Lista_dinamica **punt_elimina){
    // Prendo il vettore alla posizione last-1 (corrispondente all'ultimo elemento) e lo pongo a NULL
    (*punt_elimina)->num_din[(*punt_elimina)->last_din]=0;
    // Decremento il last
    (*punt_elimina)->last_din--;
    printf("\nElemento eliminato con successo\n");
}

void Stampa_lista_dinamica(Lista_dinamica *lista_dinamica){
    printf("\n\n----------------------------------------------------------------------------------");
    printf("\n\t\t\t\tLISTA:\n\n");
    printf("\tVettore: ");
    for (int i=0;i<=lista_dinamica->last_din;i++){
        printf("%d  ",lista_dinamica->num_din[i]);
    }
    printf("\n\tLast: %d",lista_dinamica->last_din);
    printf("\n\tDimensione: %d\n",lista_dinamica->size_din);
    printf("\n\n----------------------------------------------------------------------------------");
}

