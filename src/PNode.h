/*
 * In The Name Of God
 * ========================================
 * [] File Name : PNode
 *
 * [] Creation Date : 14-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#ifndef PLIB_PNODE_H
#define PLIB_PNODE_H

struct PNode {
	void *data;
	struct PNode *next;
};

typedef void (*PFunc)(void *data, void *user_data);

#endif
