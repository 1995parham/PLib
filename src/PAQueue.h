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
#ifndef PLIB_PAQUEUE_H
#define PLIB_PAQUEUE_H

#include <stddef.h>
#include <pthread.h>
#include "PNode.h"
#include "PQueue.h"

struct PAQueue {
	struct PQueue *q;
	pthread_mutex_t *qlock;
};

/*
 *
 */
struct PAQueue *plib_aqueue_new(void);

/*
 *
 */
void plib_aqueue_push(struct PAQueue *aq, void *data);

/*
 *
 */
void *plib_aqueue_pop(struct PAQueue *aq);

/*
 *
 */
size_t plib_aqueue_size(struct PAQueue *aq);

/*
 *
 */
void plib_aqueue_foreach(struct PAQueue *aq, void *user_data, PFunc func);


#endif
