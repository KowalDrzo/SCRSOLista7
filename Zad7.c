#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LWATKOW 8
#define PROBY 600

void *wypisz(void *idWatku) {

    int id;
    id = (long)idWatku;

    double x, y;
    int licznik = 0;    

    for(int i=0; i < PROBY; i++) {

        x = drand48();
        y = drand48();

        if(sqrt(x*x+y*y) < 0.5) licznik++;
    }

    double pi = (4.0*licznik)/PROBY;

    printf("Wątek %d uznaje, że liczba pi to: %f\n", id, pi);
    pthread_exit(NULL);
}

int main() {

    pthread_t watek[LWATKOW]; // Utworzenie tablicy wątków

    for(int i = 0; i < LWATKOW; i++)
        if(pthread_create(&watek[i], NULL, wypisz, (void *)(long)i))
            printf("\nBłąd tworzenia wątku!\n");

    pthread_exit(NULL);
}
