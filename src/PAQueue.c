/*
 * In The Name Of God
 * ========================================
 * [] File Name : PAQueue
 *
 * [] Creation Date : 14-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <stdlib.h>
#include <pthread.h>
#include "PQueue.h"
#include "PAQueue.h"

struct PAQueue *plib_aqueue_new(void)
{
	struct PAQueue *new = malloc(sizeof(struct PAQueue));
	new->qlock = malloc(sizeof(pthread_mutex_t));
	new->q = plib_queue_new();
	pthread_mutex_init(new->qlock, NULL);
	return new;
}

void plib_aqueue_push(struct PAQueue *aq, void *data)
{
	pthread_mutex_lock(aq->qlock);
	plib_queue_push(aq->q, data);
	pthread_mutex_unlock(aq->qlock);
}

void *plib_aqueue_pop(struct PAQueue *aq)
{
	void *data;
	pthread_mutex_lock(aq->qlock);
	data = plib_queue_pop(aq->q);
	pthread_mutex_unlock(aq->qlock);
	return data;
}

size_t plib_aqueue_size(struct PAQueue *aq)
{
	size_t size;
	pthread_mutex_lock(aq->qlock);
	size = aq->q->size;
	pthread_mutex_unlock(aq->qlock);
	return size;
}

void plib_aqueue_delete(struct PAQueue *aq)
{
	pthread_mutex_lock(aq->qlock);
	plib_queue_delete(aq->q);
	pthread_mutex_unlock(aq->qlock);
	pthread_mutex_destroy(aq->qlock);
	free(aq->qlock);
	free(aq);
}
