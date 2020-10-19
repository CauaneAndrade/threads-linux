#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid)
{
    printf("Hello World. Greeting from thread %p\n", tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUMBER_OF_THREADS];
    long status, i;

    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf("Main here. Greeting thread %ld\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void*) i);

        if (status != 0)
        {
            printf("Oops, pthread_create returned error code %ld\n", status);
            exit(-1);
        }
    }
    exit(-1);
}

/*
Em `#define NUMBER_OF_THREADS 10` está sendo definido a quantidade máxima de Threads a serem criadas <br>
na função `main`, o `pthread_t threads[NUMBER_OF_THREADS];` está sendo definido um valor que permite identificar a Thread <br>

No loop `for` é iterado sobre a quantidade máxima de Threads que será criada. <br>
A função `pthread_create` é utilizada para inicializar um thread, e recebe como argumento o endereço de um `pthread_t` que será inicializado

as funções `pthread_t` e `pthread_create` pertencem ao módulo `pthread`
*/