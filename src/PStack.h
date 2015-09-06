/*
 * In The Name Of God
 * ========================================
 * [] File Name : PStack.h
 *
 * [] Creation Date : 28-12-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef PLIB_PSTACK_H
#define PLIB_PSTACK_H

#include <stddef.h>
#include "PNode.h"

struct PStack {
	struct PNode *head;
	size_t size;
};

/*
 *
 */
struct PStack *plib_stack_new();

/*
 *
 */
void plib_stack_push(struct PStack *s, void *data);

/*
 *
 */
void *plib_stack_pop(struct PStack *s);

/*
 *
 */
void plib_stack_foreach(struct PStack *s, void *user_data, PFunc func);

/*
 *
 */
void plib_stack_delete(struct PStack *s);

#endif
