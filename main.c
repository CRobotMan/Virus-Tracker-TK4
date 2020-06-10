#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define PPL 100
#define SPERRE 99999

void dijkstra_algo(int contact[PPL][PPL], int patient_null)
{
    int contmin[PPL][PPL]; //Kontaktminute zwischen zwei Personen
    int pred[PPL];         //Vorgaenger, bei dem man zuvor war
    int mintime[PPL];      //das Minimum an Zeit bei Kontakt
    int visited[PPL];      //welche Nodes schon besucht wurden
    int counted;           //die Zahl der Kontakte, welche bereits gecheckt wurden
    int nextpers;
    int maxtime;
    int i;
    int j;

    for(i=0; i<PPL; i++)    //erstmal beide Matrizen mit 0 initialisieren
    {
        for(j=0; j<PPL; j++)
        {
            contact[i][j]=0;
            contmin[i][j] = contact[i][j];
        }
    }

    for (i=0; i<PPL; i++)
    {
        mintime[i] = contmin[patient_null][i];
        pred[i] = patient_null;
        visited[i] = 0;
    }

    mintime[patient_null] = 0;
    visited[patient_null] = 1;
    counted = 1;


while(counted<PPL-1)
{
    maxtime=SPERRE;

    for(i=0; i<PPL; i++)     //nextpers gibt die Person weiter mit der höchsten Minutenzahl
    {
        if(mintime[i]< maxtime && !visited[i])
        {
            maxtime=mintime[i];
            nextpers=i;
        }

        visited[nextpers]=1;

        for(i=0; i<PPL; i++)
        {
            if(!visited[i])
                if(maxtime+contmin[nextpers][i]<mintime[i])
                {
                    mintime[i]=maxtime+contmin[nextpers][i];
                    pred[i]= nextpers;
                }

            counted++;
        }
    }
}
//print the path and minute of each person
	for(i=0;i<PPL;i++)
		if(i!=patient_null)
		{
			printf("\nMinute of Person%d=%d", i, mintime[i]);
			printf("\nPath=%d",i);

			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=patient_null);
	}
}
int main()
{

    return 0;
}
