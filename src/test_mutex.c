#include <stdio.h>
#include "mutex.h"
#include <pthread.h>

mutex_t mutex;
int counter = 0;

void *example_thread_func(void *arg) {
    int i;
    int thread_id = *(int *)arg;
    for (i = 0; i < 10000; i++) {
        mutex_lock(&mutex);
        counter++;
        printf("TID %d: %d\n", thread_id, counter);
        mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int thread1_id, thread2_id;
    thread1_id = 10;
    thread2_id = 20;


    mutex_init(&mutex);

    pthread_create(&thread1, NULL, example_thread_func, &thread1_id);
    pthread_create(&thread2, NULL, example_thread_func, &thread2_id);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}