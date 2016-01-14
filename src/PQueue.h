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
#ifndef PLIB_PQUEUE_H
#define PLIB_PQUEUE_H

#include <stddef.h>
#include "PNode.h"

struct PQueue {
	struct PNode *tail;
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
struct PQueue *plib_queue_new();

/*
 *
 */
void plib_queue_push(struct PQueue *s, void *data);

/*
 *
 */
void *plib_queue_pop(struct PQueue *s);

/*
 *
 */
void plib_queue_foreach(struct PQueue *s, void *user_data, PFunc func);


#endif
