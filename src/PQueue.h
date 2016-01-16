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
 *
 */
struct PQueue *plib_queue_new(void);

/*
 *
 */
void plib_queue_push(struct PQueue *q, void *data);

/*
 *
 */
void *plib_queue_pop(struct PQueue *q);

/*
 *
 */
void plib_queue_foreach(struct PQueue *q, void *user_data, PFunc func);


#endif
