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
#include <pthread.h>
#include "PStack.h"
#include "PQueue.h"
#include "PString.h"
#include "PTypes.h"
#include "PAQueue.h"
#include "PPThread.h"

#include "PConfig.h"

void *reader(void *p)
{
	struct PAQueue *aq = (struct PAQueue *) p;
	while (!plib_aqueue_size(aq));
	printf("reader: %d\n", POINTER_TO_INT(plib_aqueue_pop(aq)));
	pthread_exit(NULL);
}

void *writer(void *p)
{
	struct PAQueue *aq = (struct PAQueue *) p;
	plib_aqueue_push(aq, INT_TO_POINTER(10));
	pthread_exit(NULL);
}

void *hello(void *p)
{
	int integer = POINTER_TO_INT(p);
	printf("Hello from %d\n", integer);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	int i;

	/* PLib version information :D */
	{
		printf("In the name of God\n");
		printf("Welcome to PLib %d.%d\n", PLib_MAJOR_VERSION, PLib_MINOR_VERSION);
	}

	/* PStack Power :) */
	{
		struct PStack *s = plib_stack_new();
		plib_stack_push(s, INT_TO_POINTER(10));
		plib_stack_push(s, INT_TO_POINTER(20));
		plib_stack_push(s, INT_TO_POINTER(30));
		printf("%d\n", POINTER_TO_INT(plib_stack_pop(s)));
	}

	/* PQueue Power :) */
	{
		struct PQueue *q = plib_queue_new();
		plib_queue_push(q, INT_TO_POINTER(10));
		plib_queue_push(q, INT_TO_POINTER(20));
		plib_queue_push(q, INT_TO_POINTER(30));
		printf("%d\n", POINTER_TO_INT(plib_queue_pop(q)));
	}

	/*PAQueue Power :) */
	{
		struct PAQueue *aq = plib_aqueue_new();
		pthread_t t1, t2;

		pthread_create(&t1, NULL, reader, aq);
		pthread_create(&t2, NULL, writer, aq);
		pthread_join(t1, NULL);
		pthread_join(t2, NULL);
	}

	/* PPThread Power :) */
	{
		struct PPThread *pt = plib_ppthread_create(2);
		plib_ppthread_add_work(pt, hello, INT_TO_POINTER(1));
		plib_ppthread_add_work(pt, hello, INT_TO_POINTER(2));
		plib_ppthread_add_work(pt, hello, INT_TO_POINTER(3));
		plib_ppthread_add_work(pt, hello, INT_TO_POINTER(4));
		plib_ppthread_start(pt);
		plib_ppthread_wait(pt);
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
		printf("U enter: %s\n", password);
	}
}
