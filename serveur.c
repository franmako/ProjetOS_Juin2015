#include "serveur.h"

int main(int argc, char *argv[])
{
    key_t key;
    int shmid;
    void* data;

    int mode= SHM_WRITE;
    printf("%d",mode);
    double test= 30.5;

    if (mode > SHM_WRITE) {
        fprintf(stderr, "usage: shmdemo [data_to_write]\n");
        exit(1);
    }

    /* make the key: */
    if ((key = ftok("shared_memory", 'R')) == ERROR) {
        perror("ftok");
        exit(1);
    }

    /* connect to (and possibly create) the segment: */
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == ERROR) {
        perror("shmget");
        exit(1);
    }

    /* attach to the segment to get a pointer to it: */
    data = shmat(shmid, (void*)0, 0);
    if (data == (void*)(ERROR)) {
        perror("shmat");
        exit(1);
    }

    /* read or modify the segment, based on the command line: */
    if (mode == SHM_WRITE) {
        printf("Ecriture dans le segment: \"%2.3f\"\n", test);
        memcpy(data, &test, SHM_SIZE);

        //strncpy(data, test, SHM_SIZE);
    } else
        printf("Le segment contiens: \"%2.3f\"\n", *(double*)data);

    /* detach from the segment: */
    if (shmdt(data) == ERROR) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}
#include "serveur.h"

int main(int argc, char *argv[])
{
    key_t key;
    int shmid;
    char *data;
    int mode= SHM_WRITE;
    char *test= "Test 22!!";

    if (argc > 2) {
        fprintf(stderr, "usage: shmdemo [data_to_write]\n");
        exit(1);
    }

    /* make the key: */
    if ((key = ftok("shared_memory", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    /* connect to (and possibly create) the segment: */
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }

    /* attach to the segment to get a pointer to it: */
    data = shmat(shmid, (void *)0, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    /* read or modify the segment, based on the command line: */
    if (mode == 2) {
        printf("Ecriture dans le segment: \"%s\"\n", test);
        strncpy(data, test, SHM_SIZE);
    } else
        printf("Le segment contiens: \"%s\"\n", data);

    /* detach from the segment: */
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}
