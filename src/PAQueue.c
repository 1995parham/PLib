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
