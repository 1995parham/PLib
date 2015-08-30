/*
 * In The Name Of God
 * ========================================
 * [] File Name : PQueue
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
#include "PQueue.h"

struct PQueue *plib_queue_new(void)
{
	struct PQueue *new = malloc(sizeof(struct PQueue));
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;
	return new;
}

void plib_queue_push(struct PQueue *q, void *data)
{
	struct PNode *nn = malloc(sizeof(struct PNode));

	nn->data = data;
	nn->next = NULL;

	if (!q->tail) {
		q->tail = nn;
		q->head = nn;
	} else {
		q->tail->next = nn;
		q->tail = nn;
	}

	q->size++;
}

void *plib_queue_pop(struct PQueue *q)
{
	if (q->size == 0) {
		return NULL;
	}

	void *data = q->head->data;
	struct PNode *tmp = q->head;

	q->head = q->head->next;

	free(tmp);

	q->size--;

	if (q->size == 1)
		q->tail = q->head;

	return data;
}

void plib_queue_foreach(struct PQueue *q, void *user_data, PFunc func)
{
	struct PNode *c = q->head;
	while (c != NULL) {
		func(c->data, user_data);
		c = c->next;
	}
}

void plib_queue_delete(struct PQueue *q)
{
	struct PNode *c = q->head;
	while (c != NULL) {
		struct PNode *tmp;
		tmp = c;
		c = c->next;
		free(tmp);
	}
	free(q);
}
