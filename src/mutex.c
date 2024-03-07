#include <stdio.h>
#include <stdatomic.h>

typedef struct {
    _Atomic int lock;
} mutex_t;

void mutex_init(mutex_t *mutex) {
    atomic_init(&mutex->lock, 0);
}

void mutex_lock(mutex_t *mutex) {
    while (atomic_exchange_explicit(&mutex->lock, 1, memory_order_acquire) == 1) {
        // spin until lock is aquired
    }
}

void mutex_unlock(mutex_t *mutex) {
    atomic_store_explicit(&mutex->lock, 0, memory_order_release);
}