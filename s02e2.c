#include <stdio.h>
#include <stdlib.h>
/* Scrivere un programma C che, preso in input un valore numero_studenti, permetta l’inserimento da tastiera
del voto di ciascuno degli studenti e ne calcoli la media utilizzando sia il costrutto for che il costrutto while.
Visualizzare poi un commento in base al voto medio della classe come mostrato in tabella:
< 6: MEDIA INSUFFICIENTE 6-7: MEDIA SUFFICIENTE 7-8: MEDIA DISCRETA 8-9: MEDIA BUONA 9-10: MEDIA OTTIMA
Inserire nel codice il controllo sull’input dell’utente per verificare che il voto inserito non sia <= 0 e > di un valore voto_max.*/

int main()
{
//dichiarazione variabili
int  i, numero_studenti;
float somma, voto, media;
printf("Inserisci il numero di studenti della classe: ");
scanf("%d", &numero_studenti);

somma=0;
//eseguzione costrutto for che provvede a richiedere l'inserimento del voto di ciascuno studente
for (i=1; i<=numero_studenti; i++){
    printf("Voto studente %.2d ", i);
    scanf("%g", &voto);
//eseguzione costrutto while per il controllo dell'input
        while (voto<=0||voto>10){
            printf("reinserire voto studente %.2d ", i);
            scanf("%g", &voto);
        }
    somma+= voto;
}
//calcolo media e visualizzazione a video
media= somma/numero_studenti;
//commento sulla media
printf("La media e\': %g: ", media);
if  (media<6){
    printf("Media Insufficiente");
}
else if (media>=6&&media<7){
    printf("Media Sufficiente");
}
else if (media>=7&&media<8){
    printf("Media Discreta");
}
else if (media>=8&&media<9){
    printf("Media Buona");
}
else {
    printf("Media Ottima");
}

return 0;
}
