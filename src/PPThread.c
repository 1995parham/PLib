/*
 * In The Name Of God
 * ========================================
 * [] File Name : PPThread.c
 *
 * [] Creation Date : 16-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <pthread.h>
#include <stddef.h>
#include <stdlib.h>
#include <signal.h>
#include "PPThread.h"
#include "PAQueue.h"

struct PWork {
	void *(*work)(void *);

	void *data;
};

static void *plib_ppthread_main(void *p)
{
	struct PPThread *pt = (struct PPThread *) p;
	int i;

	while (1) {
		while (plib_aqueue_size(pt->q) == 0);
		for (i = 0; i < pt->s; i++) {
			if (pthread_kill(pt->t[i], 0) != 0) {
				pthread_join(pt->t[i], NULL);
				struct PWork *w = plib_aqueue_pop(pt->q);
				pthread_create(&(pt->t)[i], NULL, w->work,
					w->data);
				free(w);
			}
		}
	}
}

struct PPThread *plib_ppthread_create(size_t size)
{
	struct PPThread *new = malloc(sizeof(struct PPThread));
	new->q = plib_aqueue_new();
	new->s = size;
	new->t = malloc(size * sizeof(pthread_t));
	return new;
}

void plib_ppthread_start(struct PPThread *pt)
{
	pthread_create(&pt->m, NULL, plib_ppthread_main, pt);
}

void plib_ppthread_add_work(struct PPThread *pt, void *(*work)(void *),
	void *data)
{
	struct PWork *w = malloc(sizeof(struct PWork));
	w->work = work;
	w->data = data;
	plib_aqueue_push(pt->q, w);
}

void plib_ppthread_wait(struct PPThread *pt)
{
	pthread_cancel(pt->m);
	pthread_join(pt->m, NULL);
	int i;
	for (i = 0; i < pt->s; i++) {
		pthread_join(pt->t[i], NULL);
	}
}

void plib_ppthread_destroy(struct PPThread *pt)
{
	plib_ppthread_wait(pt);
	free(pt->t);
	while (plib_aqueue_size(pt->q) > 0) {
		void *data = plib_aqueue_pop(pt->q);
		free(data);
	}
	plib_aqueue_delete(pt->q);
	free(pt);
}
