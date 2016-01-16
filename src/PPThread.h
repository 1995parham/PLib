/*
 * In The Name Of God
 * ========================================
 * [] File Name : PPThread.h
 *
 * [] Creation Date : 16-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#ifndef PLIB_PPTHREAD_H
#define PLIB_PPTHREAD_H

#include <pthread.h>
#include "PAQueue.h"

struct PPThread {
	pthread_t *t;
	struct PAQueue *q;
	size_t s;
	pthread_t m;
};

struct PPThread *plib_ppthread_create(size_t size);

void plib_ppthread_start(struct PPThread *pt);

void plib_ppthread_add_work(struct PPThread *pt, void *(*work)(void *), void *data);

void plib_ppthread_wait(struct PPThread *pt);

void plib_ppthread_destroy(struct PPThread *pt);

#endif
