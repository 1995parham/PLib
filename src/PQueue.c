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

struct PQueue *plib_queue_new()
{
	struct PQueue *new = malloc(sizeof(struct PQueue));
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;
	return new;
}

void plib_queue_push(struct PQueue *s, void *data)
{
	struct PNode *nn = malloc(sizeof(struct PNode));

	nn->data = data;
	nn->next = NULL;

	if (!s->tail) {
		s->tail = nn;
		s->head = nn;
	} else {
		s->tail->next = nn;
		s->tail = nn;
	}

	s->size++;
}

void *plib_queue_pop(struct PQueue *s)
{
	void *data = s->head->data;

	s->head = s->head->next;

	s->size--;

	if (s->size == 1)
		s->tail = s->head;

	return data;
}

void plib_queue_foreach(struct PQueue *s, void *user_data, PFunc func)
{
	struct PNode *c = s->head;
	while (c != NULL) {
		func(c->data, user_data);
		c = c->next;
	}
}
