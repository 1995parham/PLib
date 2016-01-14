/*
 * In The Name Of God
 * ========================================
 * [] File Name : log.c
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "PLog.h"
#include "PStack.h"

#define MAX_BUFF 1000*1000

static struct PStack *handles;

struct handle {
	PExitHandler handle;
	void *data;
	int free;
};

void plib_sdie(const char *fmt, ...)
{
	char buf[MAX_BUFF];
	va_list args;

	va_start(args, fmt);
	vsprintf(buf, fmt, args);
	va_end(args);

	perror(buf);
	while (handles && handles->size > 0) {
		struct handle *h = plib_stack_pop(handles);
		h->handle(h->data);
		if (h->free)
			free(h->data);
		free(h);
	}
	exit(EXIT_FAILURE);
}

void plib_udie(const char *fmt, ...)
{
	char buf[MAX_BUFF];
	va_list args;

	va_start(args, fmt);
	vsprintf(buf, fmt, args);
	va_end(args);

	size_t len = strlen(buf);

	buf[len] = '\n';
	buf[len + 1] = 0;

	fputs(buf, stderr);
	while (handles && handles->size > 0) {
		struct handle *h = plib_stack_pop(handles);
		h->handle(h->data);
		if (h->free)
			free(h->data);
		free(h);
	}
	exit(EXIT_FAILURE);
}

void plib_slog(const char *fmt, ...)
{
	char buf[MAX_BUFF];
	va_list args;

	va_start(args, fmt);
	vsprintf(buf, fmt, args);
	va_end(args);

	perror(buf);
}

void plib_ulog(const char *fmt, ...)
{
	char buf[MAX_BUFF];
	va_list args;

	va_start(args, fmt);
	vsprintf(buf, fmt, args);
	va_end(args);

	size_t len = strlen(buf);

	buf[len] = '\n';
	buf[len + 1] = 0;

	fputs(buf, stderr);
}

void plib_register_exit_handler(PExitHandler handler, void *data, int free)
{
	if (!handles) {
		handles = plib_stack_new();
	}

	struct handle *h = malloc(sizeof(struct handle));
	h->data = data;
	h->handle = handler;
	h->free = free;

	plib_stack_push(handles, h);
}
