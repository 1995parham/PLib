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

#define MAX_BUFF 1000*1000

void plib_sdie(const char *fmt, ...)
{
	char buf[MAX_BUFF];
	va_list args;

	va_start(args, fmt);
	vsprintf(buf, fmt, args);
	va_end(args);

	perror(buf);
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
	exit(EXIT_FAILURE);
}

void plib_slog(const char *fmt, ...)
{
#ifdef DEBUG
	fprintf(stderr, "DEBUG: ");
	fflush(stdout);

	char buf[MAX_BUFF];
	va_list args;

	va_start(args, fmt);
	vsprintf(buf, fmt, args);
	va_end(args);

	perror(buf);
#endif
}

void plib_ulog(const char *fmt, ...)
{
#ifdef DEBUG
	fprintf(stderr, "DEBUG: ");
	fflush(stdout);

	char buf[MAX_BUFF];
	va_list args;

	va_start(args, fmt);
	vsprintf(buf, fmt, args);
	va_end(args);

	size_t len = strlen(buf);

	buf[len] = '\n';
	buf[len + 1] = 0;

	fputs(buf, stderr);
#endif
}