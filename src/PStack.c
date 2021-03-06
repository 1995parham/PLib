/*
 * In The Name Of God
 * ========================================
 * [] File Name : PStack.c
 *
 * [] Creation Date : 28-12-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <stdlib.h>
#include <string.h>
#include "PStack.h"

struct PStack *plib_stack_new()
{
	struct PStack *new = malloc(sizeof(struct PStack));
	new->head = NULL;
	new->size = 0;
	return new;
}

void plib_stack_push(struct PStack *s, void *data)
{
	struct PNode *nn = malloc(sizeof(struct PNode));

	nn->data = data;

	nn->next = s->head;
	s->head = nn;

	s->size++;
}

void *plib_stack_pop(struct PStack *s)
{
	if (s->size == 0)
		return NULL;

	void *data = s->head->data;
	struct PNode *tmp = s->head;

	s->head = s->head->next;

	free(tmp);

	s->size--;

	return data;
}

void plib_stack_foreach(struct PStack *s, void *user_data, PFunc func)
{
	struct PNode *c = s->head;
	while (c != NULL) {
		func(c->data, user_data);
		c = c->next;
	}
}

void plib_stack_delete(struct PStack *s)
{
	struct PNode *c = s->head;
	while (c != NULL) {
		struct PNode *tmp;
		tmp = c;
		c = c->next;
		free(tmp);
	}
	free(s);
}
