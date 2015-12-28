/*
 * In The Name Of God
 * ========================================
 * [] File Name : stack
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

struct PNode {
	void *data;
	struct PNode *next;
};

struct PStack {
	struct PNode *head;
	size_t size;
};

/*
 * Specifies the type of functions passed to plib_stack_foreach().
 */
typedef void (*PFunc)(void *data, void *user_data);

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

#endif
