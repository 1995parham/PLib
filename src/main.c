/*
 * In The Name Of God
 * ========================================
 * [] File Name : main
 *
 * [] Creation Date : 28-12-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include "PStack.h"
#include "types.h"

/*
 * Copyright (c) 2015 Parham Alvani.
*/

int main(int argc, char *argv[])
{
	struct PStack *s = plib_stack_new();
	plib_stack_push(s, INT_TO_POINTER(10));
	plib_stack_push(s, INT_TO_POINTER(20));
	plib_stack_push(s, INT_TO_POINTER(30));
	printf("%d\n", POINTER_TO_INT(plib_stack_pop(s)));
}
