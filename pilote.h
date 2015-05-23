#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <math.h> //Pour l'utilisation de fmod pour le calcul des modulo pour float
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define ERROR -1
#define NBTRSCOURSE 5
#define NBTRSMAXESSAIS 10
#define NBTRSMAXQUALIF 5
#define NBSECTORS 3
#define SEC_MIN 30.0
#define SEC_MAX 40.0
#define SHM_WRITE 2
#define ESSAI_P1 0
#define ESSAI_P2 1
#define ESSAI_P3 2
#define TRUE 1
#define FALSE 0
#define MIN_DNF 0
#define MAX_DNF 100
#define DNFPROB 80


/* -- STRUCTURES -- */
typedef struct{
    int minutes;
    double secondes;
}FTime;

typedef struct{
    double tempsTour;
    double tbTempsSect[NBSECTORS];
}TTour;

typedef struct{
    int nbTrsEssais[3];
    int nbTrsQualif;
    int nbTrsCourse;
    //Essais
    int isOut;
    int isStand;
    int lapPit;
    int DNF;
    int lapDNF;
    TTour P1[NBTRSMAXESSAIS];
    TTour P2[NBTRSMAXESSAIS];
    TTour P3[NBTRSMAXESSAIS];
    //Qualifs
    TTour qualif[NBTRSMAXQUALIF];
    TTour course[NBTRSCOURSE];
}TWECourse;

typedef struct{
    int pid;
    int nbPilote;
    TWECourse GPrix;
}TPilote;

/* -- PROTOTYPES -- */
int getRandomInt(int,int);
double getRandomFloat(double,double);
void getSectorEssais(TPilote*,int,int);
void sharedMem(int,TPilote*,int);


