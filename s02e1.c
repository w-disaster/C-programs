#include <stdio.h>
#include <stdlib.h>
/*scrivere un programma che chieda all'utente di immettere il proprio orario di arrivo all'aeroporto
(espresso in ore e minuti utilizzando il formato a 24 ore). Il programma deve visualizzare gli
orari di partenza e di arrivo del primo volo che sarà possibile prendere (quello il cui orario
di partenza è immediatamente successivo rispetto a quello immesso dall'utente).*/
int main()
{
int ore, minuti;
char c;
//inserimento stima orario di arrivo
printf("inserisci stima ora di arrivo in aeroporto in formato 24h: ");
scanf("%d%c%d", &ore, &c, &minuti);

//pulizia buffer
fflush(stdin);

//esegui un ciclo finchè non viene inserito l'orario in modo corretto
while (ore>24||ore<0 || minuti>60||minuti<0){
    printf("Ore e/o minuti errati, reinserire orario ");
    scanf("%d%c%d", &ore, &c, &minuti);
}

// analizza le ore e poi i minuti individuando il primo volo disponibile dopo l'orario di arrivo
switch (ore){
case 22: case 23: case 24: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
    printf("orario partenza: 8:00 AM, orario arrivo: 10:16 AM\n");
    break;
case 8:
    printf("orario partenza: 9:43 AM, orario arrivo: 11:52 AM\n");
    break;
case 9:
    if (minuti<43){
       printf("orario partenza: 9:43 AM, orario arrivo: 11:52 AM\n");
       break;
    }
    else {
        printf("orario partenza: 11:19 AM, orario arrivo: 1:31 PM\n");
        break;
    }
case 10:
    printf("orario partenza: 11:19 AM, orario arrivo: 1:31 PM\n");
    break;
case 11:
    if (minuti<19){
       printf("orario partenza: 11:19 AM, orario arrivo: 1:31 PM\n");
       break;
    }
    else {
        printf("orario partenza: 12:47 AM, orario arrivo: 3:00 PM\n");
        break;
    }
case 12:
    if (minuti<47){
        printf("orario partenza: 12:47 AM, orario arrivo: 3:00 PM\n");
        break;
    }
    else {
        printf("orario partenza: 2:00 PM, orario arrivo: 4:08 PM\n");
        break;
    }
case 13:
    printf("orario partenza: 2:00 PM, orario arrivo: 4:08 PM\n");
    break;
case 14:
    printf("orario partenza: 3:45 PM, orario arrivo: 5:55 PM\n");
    break;
case 15:
    if (minuti<45) {
        printf("orario partenza: 3:45 PM, orario arrivo: 5:55 PM\n");
        break;
    }
    else{
        printf("orario partenza: 7:00 PM, orario arrivo: 9:20 PM\n");
        break;
    }
case 16: case 17: case 18:
    printf("orario partenza: 7:00 PM, orario arrivo: 9:20 PM\n");
    break;
case 19: case 20:
    printf("orario partenza: 9:45 PM, orario arrivo: 11:58 PM\n");
    break;
case 21:
    if (minuti<45) {
        printf("orario partenza: 9:45 PM, orario arrivo: 11.58 PM\n");
        break;
    }
    else{
        printf("orario partenza: 8:00 AM, orario arrivo: 10:16 AM\n");
        break;
    }
}

return 0;
}
