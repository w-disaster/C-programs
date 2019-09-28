#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define NUM_ESAMI 10
#define MATR 10
#define STUD 10

int main()
{
    //_____________________________________________________________________________________________________________________________________________________________________
    //                                                                 STRUCTS
    //_____________________________________________________________________________________________________________________________________________________________________
    //Creo un nuovo tipo di variabile contenente le seguenti variabili
    struct esami
    {
        char ins[25];
        int vote;
    };
    //Creo un nuovo tipo di variabile contenente le seguenti variabili
    struct stud
    {
        char matr[MATR], name[25], surname[25];
        //I declare a variable of type struct esami
        struct esami course[MATR];
        int year;
    };
    //var struct stud
    struct stud student[STUD];//Se il voto==0 allora l'esame non è stato ancora sostenuto
     //temp_uno memorizza il numero degli studenti inseriti, temp_due conta quante materie sono state inserite per studente
    int i,k, temp_uno, temp_due[STUD];
    //variabili conferma
    char choose, choose_es, choose_search, choose_mod;
    //variabili rispettivamente per cerca studente ed aggiunta di un voto
    char el[MATR], el_uno[MATR];
    i=0;
    k=0;
    choose='y';
    choose_es='y';
    //_____________________________________________________________________________________________________________________________________________________________________
    //                                                                 INSERIMENTO STUDENTI
    //_____________________________________________________________________________________________________________________________________________________________________
    printf("-----------------------------------------------------STUDENT DATA ENTRY------------------------------------------------------------------\n\n");
    //eseguzione ciclo while finchè vuoi inserire un altro studente e i< massimo numero di studenti che posso inserire
    while (i<STUD&&(choose=='y'||choose=='Y'))
    {
        choose='y';
        choose_es='y';

        //registration number
        printf("Insert the registration number of student n.%d: ",i+1);
        scanf("%s",student[i].matr);
        fflush(stdin);
        //se i>o cioè hai già inserito uno studente, controlla che la matricola che hai appena inserito non sia uguale a quella degli studenti inseriti precedentemente
        if (i>0){
            for (int j=i-1;j>=0;j--){
                if (strcmp(student[i].matr,student[j].matr)==0){
                    printf("\nStudent already entered, reinsert: ");
                    scanf("%s",student[i].matr);
                    fflush(stdin);
                    j=i;
                }
            }
        }

       //Inserisci il nome
        printf("\nInsert the first name (student n.%s) ",student[i].matr);
        scanf("%s",student[i].name);
        fflush(stdin);

        //inserisci il cognome
        printf("\nInsert the surname (student n.%s) ",student[i].matr);
        scanf("%s",student[i].surname);
        fflush(stdin);

        //Inserisci l'anno di immatricolazione
        printf("\nInsert the year of matriculation (student n.%s) ",student[i].matr);
        scanf("%d",&student[i].year);
        fflush(stdin);

        //Inserisci il nome di studio, in particolare: Materia e voto corrispondente
        printf("\nInsert the study course (student n.%s)",student[i].matr);
        k=0;
        while (k<NUM_ESAMI&&(choose_es=='y'||choose_es=='Y')){
            //Inserisci la materia
            printf("\n\n\tInsert the subject n.%d: ",k+1);
            scanf(" %s",student[i].course[k].ins);
            fflush(stdin);
            //Inserisci il voto
            printf("\n\tInsert %s vote: ",student[i].course[k].ins);
            scanf(" %d",&student[i].course[k].vote);
            fflush(stdin);
            //Se il voto è <0 o >30 non è valido quindi reinserisci
            while (isdigit(student[i].course[k].vote)!=0||(student[i].course[k].vote>30||student[i].course[k].vote<0)){
                printf("\n\t%sVote not valid, reinsert: ",student[i].course[k].ins);
                scanf(" %d",&student[i].course[k].vote);
                fflush(stdin);
            }
            //temp_due[i] prende k cioè il numero di materie (==voti) che hai inserito
            temp_due[i]=k;
            //Vuoi inserire un altra materia?
            printf("\n\tDo you want to insert subject n.%d? Type y/n: ",k+2);
            scanf(" %c",&choose_es);
            fflush(stdin);
            k++;
        }
        //Vuoi inserire un altro studente?
        printf("\nContinue with student n.%d? Type y/n: ",i+2);
        scanf(" %c",&choose);
        fflush(stdin);
        //Se sul controllo precedente non hai inserito i caratteri che compaiono nell'argomento del while allora il formato non è valido quindi reinserire
        while (choose!='y'&&choose!='Y'&&choose!='n'&&choose!='N'){
        printf("\nInvalid input, reinsert: ");
        scanf(" %c",&choose);
        fflush(stdin);
        }
        //temp_uno conta il numero di studenti che hai inserito
        temp_uno=i;
        i++;
        printf("\n");
    }

    if (i==STUD){
    printf("You achieved the max number of students permitted\n");
    }

     //_____________________________________________________________________________________________________________________________________________________________________
    //                                                                 CERCA STUDENTE
    //_____________________________________________________________________________________________________________________________________________________________________

    printf("\n---------------------------------------------------STUDENT SEARCH---------------------------------------------------------------\n");
    //Vuoi cercare uno studente?
    printf("Do you want to search a student? type y/n: ");
    scanf(" %c",&choose_search);
    fflush(stdin);
    //controllo il choose_search
    while (choose_search!='y'&&choose_search!='y'&&choose_search!='n'&&choose_search!='N'){
        //inserisci il numero di matricola
        printf("\nInvalid input, reinsert: ");
        scanf(" %c",&choose_search);
        fflush(stdin);
    }
    while (choose_search=='Y'||choose_search=='y'){
        //Inserisci il numero di matricola
        printf("\nInsert a registration number to search a student: ");
        scanf("%s",el);

        k=0, i=0;
        while (i<=temp_uno){
            //Se c'è corrispondenza:
            if (strcmp(el,student[i].matr)==0){
                printf("\nStudent n.%d\n\n",i+1);
                printf("\tNumber of registration: %s\n\n",student[i].matr);
                printf("\tName: %s\n\n",student[i].name);
                printf("\tSurname: %s\n\n",student[i].surname);
                printf("\tYear of matriculation: %d\n\n",student[i].year);

                printf("Exams:\n\n");
                //Esegui il ciclo fino a temp_due[i] cioè fino al numero delle materie/voti immessi nello studente student[i]
                while (k<=temp_due[i]){
                printf("\tSubject: %s ",student[i].course[k].ins);
                //Se il voto==0 allora l'esame non è stato ancora sostenuto
                if (student[i].course[k].vote==0){
                    printf("\tExam not sustained\n\n");
                }
                else {
                    printf("\t%s vote: %d\n\n",student[i].course[k].ins,student[i].course[k].vote);
                }
                k++;
                }
                break;
            }
        //Incrementa la posizione nel vettore student
        i++;
        //Se i ha raggiunto il massimo+1 degli studenti immessi allora non è stata trovata alcuna corrispondenza, quindi reinserire il numero di matricola
        if (i==temp_uno+1){
            printf("\nStudent not found, reinsert the registration number: ");
            scanf("%s",el);
            i=0;
        }
        }
    //Vuoi cercare un altro studente?
    printf("Do you want to look for another student? type y/n: ");
    scanf(" %c",&choose_search);
    fflush(stdin);
    }


    //___________________________________________________________________________________________________________________________________________________________________________
    //                                                                       AGGIUNTA VOTO
    //___________________________________________________________________________________________________________________________________________________________________________


    printf("\n--------------------------------------------------ADDING A VOTE-------------------------------------------------------------\n");
    //Vuoi aggiungere un voto?
    printf("\nDo you want to add a new vote? type y/n: ");
    scanf(" %c",&choose_mod);
    fflush(stdin);
    //controllo il choose_mod
    while (choose_mod!='y'&&choose_mod!='y'&&choose_mod!='n'&&choose_mod!='N'){
        //inserisci il numero di matricola
        printf("\nInvalid input, reinsert: ");
        scanf(" %c",&choose_mod);
        fflush(stdin);
    }
    while (choose_mod=='y'||choose_mod=='y'){
        //inserisci il numero di matricola
        printf("\nInsert the student registration number: ");
        scanf("%s",el_uno);
        fflush(stdin);
        //Esegui costrutto while finchè i non ha raggiunto temp_uno-1 (il numero degli studenti immessi
        while (i<=temp_uno){
            //Se c'è corrispondenza:
            if (strcmp(el_uno,student[i].matr)==0){
                temp_due[i]=temp_due[i]+1;
                        //Inserisci la nuova materia
                        printf("\n\n\tInsert the subject n.%d: ",temp_due[i]+1);
                        scanf(" %s",&student[i].course[temp_due[i]].ins);
                        fflush(stdin);
                        //Inserisci il suo voto corrispondente
                        printf("\n\tInsert %s vote: ",student[i].course[temp_due[i]].ins);
                        scanf(" %d",&student[i].course[temp_due[i]].vote);
                        fflush(stdin);
                        //(Come prima)Controllo che il voto sia >=0 e <=30. In caso contrario reinserirlo
                        while (isdigit(student[i].course[k].vote)!=0||(student[i].course[temp_due[i]].vote>30||student[i].course[temp_due[i]].vote<0)){
                            printf("\n\t%s vote not valid, reinsert: ",student[i].course[temp_due[i]].ins);
                            scanf(" %d",&student[i].course[temp_due[i]].vote);
                            fflush(stdin);
                        }
                       break;
            }
        i++;
        //Se i ha raggiunto il massimo+1 degli studenti immessi allora non è stata trovata alcuna corrispondenza, quindi reinserire il numero di matricola
        if (i==temp_uno+1){
            printf("\nStudent not found, reinsert the registration number: ");
            scanf("%s",el_uno);
            i=0;
        }

    }
     //Vuoi aggiungere un altro voto?
    printf("\nDo you want to add another vote? type y/n: ");
    scanf(" %c",&choose_mod);
    fflush(stdin);
    }

    //___________________________________________________________________________________________________________________________________________________________________________
    //                                                                       LISTA STUDENTI
    //___________________________________________________________________________________________________________________________________________________________________________

    printf("\n---------------------------------------------------LIST OF STUDENTS---------------------------------------------------------------\n");
    i=0;
    k=0;
    //Esegui costrutto while finchè i non ha raggiunto temp_uno-1 (il numero degli studenti immessi
    while (i<=temp_uno){
        printf("\nStudent n. %s\n",student[i].matr);
        printf("\n\tName: %s\n",student[i].name);
        printf("\n\tSurname: %s\n",student[i].surname);
        printf("\n\tYear of matriculation: %d\n",student[i].year);
        printf("\nExams:\n\n");
        //Esegui il ciclo fino a temp_due[i] cioè fino al numero delle materie/voti immessi nello studente student[i]
        while (k<=temp_due[i]){
            printf("\tSubject: %s",student[i].course[k].ins);
            //Se il voto==0 allora l'esame non è stato ancora sostenuto
            if (student[i].course[k].vote==0){
                printf("\tExam not taken\n\n");
            }
            else {
                printf("\t%s vote: %d\n\n",student[i].course[k].ins,student[i].course[k].vote);
            }
            k++;
        }
        printf("\n-------------------------------------------------------\n");

        k=0;
    i++;
    }


    return 0;
}
