#ifndef MUTEX_H
#define MUTEX_H

#include <stdatomic.h>

typedef struct {
  _Atomic int lock;
} mutex_t;

void mutex_init(mutex_t *mutex);
void mutex_lock(mutex_t *mutex);
void mutex_unlock(mutex_t *mutex);

#endif