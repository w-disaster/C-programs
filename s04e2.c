#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int main()
{
//dichiarazione variabili
char p1[31];
char p2[31], p3[31], p4[31];
char gt;
int i=0, k=0;
bool method;
bool c=false;

//scelta tra metodo uno e metodo due
printf("Inserire 0 per metodo uno o 1 per metodo 2: ");
scanf("%d", &method);
//se metodo uno esegui:
if (method==0){
    //inserisci 1 parola
    printf("inserire parola n 1 (max 30 caratteri)");
    scanf("%s", p1);
    //inserisci seconda parola
    printf("inserire parola n 2 (max 30 caratteri)");
    scanf("%s", p2);

    printf("Parola con eventuali occorrenze: ");
        //esegui fino a che un carattere di p1 è =='\0' (terminatore di stringa)
        while (p1[i]!='\0'){
                //esegui fino a che un carattere di p2 è =='\0' (terminatore di stringa)
                while (p2[k]!='\0'){
                    //se gli elementi sono uguali allora prendi true
                    if (p1[i]==p2[k]){
                        i++;
                        k++;
                        c=true;
                    }
                    /*altrimenti prendi false e se l'elemento i-esimo della prima parola non è il
                    terminatore di stringa stampa il primo carattere della prima parola */
                    else{
                        c=false;
                        if (p1[i]=='\0'){
                            break;
                        }
                        else{
                            i=i-k;
                            printf("%c", p1[i]);
                            k=0;
                            i++;
                        }

                    }

                }
        k=0;

        if (c==true){
            printf("*");
        }

        }

    }
    //metodo 2 (con librerie)
    else if (method==1){
    //dichiarazione variabili
    int len=0, ret;
    char *pos;
    char p5[31];
    int L3, L3a, L4, posizione;
    bool v;
    //inserire parola 1
    printf("inserire parola n 1 (max 30 caratteri)");
    scanf("%s", p3);
    //inserisci parola 2
    printf("inserire parola n 2 (max 30 caratteri)");
    scanf("%s", p4);


    printf("Parola con eventuali occorrenze: ");
    strcpy(p5, p3);

    L3=strlen(p3);
    L4=strlen(p4);
    v=true;
    while (v==true){
        //cerco la corrispodenza sul primo char
        pos=strchr(p3,p4[0]);
            if (pos!=NULL){
                 //detrmino la posizione nella stringa della corrispondenza primo char;
                 posizione=(pos-p3);
                //assegno a p5 i caratteri della sringa p3 dall'occorenza alla fine
                for (i=0;i<=(L3-posizione);i++){
                    p5[i]=p3[posizione+i];
                }
                //cerco corrispndenza con i primi caratteri di p4
                ret= strncmp(p5,p4,L4);

                if (ret==0){
                    //stampo i caratteri prima della corrispondenza
                    for (i=0;i<posizione;i++){
                    printf("%c",p3[i]);
                    }
                    printf("*");

                    L3a=strlen(p3);
                    strcpy(p3,"");
                    //assegno a p3 la stringa dalla fine della corrispondeza fino alla fine della stringa
                    for (i=0;i<=(L3a-posizione-L4);i++){
                    p3[i]=p5[L4+i];
                    }
                }
                else {
                    if ((strlen(p3)-posizione)<=L4){
                        v=false;
                        printf("%s",p3);
                    }
                    else{
                    L3a=strlen(p3);
                    strcpy(p3,"");
                    for (i=0;i<=(L3a-posizione-L4);i++){
                    p3[i]=p5[L4+i];
                    }
                    }
                }
            }
            else{
                v=false;
                printf("%s",p3);
            }
    }



    /*int v[30], k;
    bool h;
    char *occ;
    while (p4[i]!='\0'){
    occ= strchr(p3,p4[i]);
    //printf("%d",occ-p3);
    if (occ!=NULL){
        h=true;
        k=0;
        v[k]=occ;
        k++;
    }

    else {
        break;
    }
    i++;

    i=0;
    while (h==true&&p3[i]!='\0'){
    v[v[i]]='*';
    i++;
    }
    printf("%s",v);
    }


    }
    */


}
return 0;
}
