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
/*
 * Copyright (c) 2015 Parham Alvani.
*/

#include <stdio.h>
#include <string.h>
#include "PStack.h"
#include "PString.h"
#include "types.h"


int main(int argc, char *argv[])
{
	int i;

	/* PStack Power :) */
	{
		struct PStack *s = plib_stack_new();
		plib_stack_push(s, INT_TO_POINTER(10));
		plib_stack_push(s, INT_TO_POINTER(20));
		plib_stack_push(s, INT_TO_POINTER(30));
		printf("%d\n", POINTER_TO_INT(plib_stack_pop(s)));
	}

	/* PString Power :) */
	{
		char *str = "123a123bb123ccc123dddd123eeeee123ffffff123";
		char *token = "123";
		char **result;
		int number = plib_string_tokenizer(str, token, &result);
		for (i = 0; i < number; i++) {
			printf("%s\n", result[i]);
		}

		char password[50];
		printf("Enter your password: ");
		plib_fgetpass(password, sizeof(password), stdin);
		password[strlen(password) - 1] = 0;
		printf("U enter: %s", password);
	}
}
