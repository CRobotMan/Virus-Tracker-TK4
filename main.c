

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define PPL 100  //maximale personenanzahl
#define KANTEN 500 //maximale kontakte zweier personen
#define SPERRE 99999




int dijkstra_algo(int contact[PPL][PPL], int patient_null)
{
    int contmin[PPL][PPL]; //Kontaktminute zwischen zwei Personen
    int pred[PPL];         //Vorgaenger, bei dem man zuvor war
    int mintime[PPL];      //die Minuten an Zeit bei Kontakt
    int visited[PPL];      //welche Nodes schon besucht wurden
    int counted;           //die Zahl der Kontakte, welche bereits gecheckt wurden
    int nextpers;
    int maxtime;
    int i;
    int j;
    int v=0;
    //hier kommen die Deklarierungen fuer die Werte der Matrix
    int conID;
    int pers_a;
    int pers_b;
    int min;

    for(i=0; i<PPL; i++)    //erstmal beide Matrizen mit 0 initialisieren
    {
        for(j=0; j<PPL; j++)
        {
            contact[i][j]=0;
            contmin[i][j] = contact[i][j];
        }
    }
    FILE* interaction;
    interaction = fopen("interactions.csv","r");
    if(interaction == NULL)
    {
        printf("Datei nicht gefunden!");
        return -1;
    }
    while(fscanf(interaction,"%d | %d | %d | %d", &conID, &pers_a, &pers_b, &min)!=EOF)
    {
        contmin[pers_a][pers_b]=min;
        contmin[pers_b][pers_a]=contmin[pers_a][pers_b];
        //printf("%3d | %3d | %3d | %4d\n", conID, pers_a, pers_b, min);

    }
//printf("%d",contmin[52][]);
    contact = contmin;

    fclose(interaction);
    for(i=0; i<=PPL; i++)
    {
        mintime[i]=0;
        visited[i]=0;
    }

/*
for(i=1; i<=PPL; i++) //alle nicht besuchte nodes sind auf 0 initialisiert visited[]=0
{
    mintime[i]=mintime[i-1];
    if(mintime[i]<contmin[patient_null][i])
    {
        //printf("IF min time %d\n", mintime[i]);
        v=i;
        mintime[i]=contmin[patient_null][v];
        //printf("AFTER min time %d\n", mintime[i]);

    }
}*/
for(j=1; j<=PPL; j++)
{
    for(i=1; i<PPL; i++) //alle nicht besuchte nodes sind auf 0 initialisiert visited[]=0
    {
        mintime[i]=mintime[i-1];
        if(mintime[i]<contmin[patient_null][i] && visited[i]==0)
        {
            //printf("IF min time %d\n", mintime[i]);
            v=i;
            mintime[i]=contmin[patient_null][v];
            //printf("AFTER min time %d\n", mintime[i]);

        }
    }
    printf("%d -> %d\n",patient_null, v);
    printf("%d_\n", mintime[v]);
    visited[patient_null]=1;
    visited[v]=1;
    patient_null = v;


}
printf("ENDE %d\n", v);
printf("ENDE %d_\n", mintime[v]);

//printf("%d\n", v);
//printf("%d_\n", mintime[v]);

//hier setze alles auf 0
//visited[patient_null]=1;
//mintime[patient_null]=0;
//printf("%d", visited[patient_null]);

/*for(j=2; j<=PPL; j++)
{


    for(i=1; i<=PPL; i++) //alle nicht besuchte nodes sind auf 0 initialisiert visited[]=0
    {
        mintime[i]=mintime[i-1];
        if(mintime[i]<contmin[patient_null][i] && visited[i]==0)
        {
            printf("IF min time %d\n", mintime[i]);
            v=i;
            mintime[i]=contmin[patient_null][v];
            //visited[v]=1;
            printf("AFTER min time %d\n", mintime[i]);
        }
        visited[v]=1;
        for(i=1; i<=KANTEN;i++)
        {

                if(mintime[v]+contmin[v][i]>mintime[i])
                {
                    mintime[j]=contmin[v][i]+mintime[v];
                }

        }
    }
}*/
//printf("%d\n", v);
//printf("%d_\n", mintime[v]);

//HIER DRUNTER IST IRGENDWO DER FEHLER

/*
for(i=2; i<=PPL; i++)
{
printf("test %d", contmin[patient_null][i]);
    for(j=1; j<=PPL; j++)
    {
        if(mintime[j]<contmin[patient_null][i] && visited[j]==0)
        {
            contmin[patient_null][i]=mintime[j];
            v=j;
        }
        visited[v]=1;
        for(j=1; j<=KANTEN; j++)
        {
            if(mintime[v]+contmin[v][j]>mintime[j])
            {
                mintime[j]=contmin[v][j]+mintime[v];
            }
        }
    }
}
//printf("%d", mintime[j]);
printf("\nDie Uebertragung der Krankheit ueber den Personen findet wie folgt statt:\n");
for(i=1; i<=KANTEN; i++)
{
  if(i!=patient_null)
  {
      printf("%d\n", contmin[i]);
  }
}

*/
}

int main()
{

    int erstpers;
    int infect[PPL][PPL];

    printf("Bitte geben Sie die ID der ersten infizierten Person ein.(1-100)\n");
    scanf("%d", &erstpers);

    dijkstra_algo(infect, erstpers);

    int i,j;

    return 0;
}

