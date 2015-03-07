#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define NBTOURS 5

void getTempsSecteur();
void getTempsTour(int);

main(){
    int i;
    srand(time(NULL));
    for(i=0;i<NBTOURS;i++){
        //printf(" *** Tour %d ***\n\n",i+1);
        getTempsSecteur();
    }
}
void getTempsSecteur(){
    int i,sectorTime,totalLapTime=0;
    for(i=0;i<3;i++){
        sectorTime= ((rand()%11)+30); //rand()% x + n | n = min et n +(x-1) = max.
        //sleep(sectorTime);//Attends le nb de secondes du random avant d'afficher le temps
        //printf("Temps du secteur %d : %d secondes\n",i+1,sectorTime);
        totalLapTime += sectorTime;//Calcule le temps total après chaque tour
    }
    getTempsTour(totalLapTime);
}
void getTempsTour(int totalLapTime){
    int totalTimeMin,totalTimeSec;
    totalTimeMin= (totalLapTime/60);
	totalTimeSec= (totalLapTime%60);
	/*if(totalTimeMin != 0){
        printf("Temps total pour le tour= %d minute(s) %d secondes \n\n",totalTimeMin,totalTimeSec);
	}else{
	    printf("Temps total pour le tour= %d secondes \n\n",totalTimeSec);
	}*/
}