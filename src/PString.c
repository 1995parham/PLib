/*
 * In The Name Of God
 * ========================================
 * [] File Name : PString.c
 *
 * [] Creation Date : 06-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <termios.h>

#include "PString.h"
#include "PStack.h"
#include "PLog.h"

int plib_string_tokenizer(const char *source, const char *token,
	char ***result)
{
	const char *end;
	const char *start = source;
	size_t tkn_size = strlen(token);
	struct PStack *buffer = plib_stack_new();
	int index = 0;

	while ((end = strstr(source, token)) != NULL) {
		index++;
		char *str = malloc((end - source + 1) * sizeof(char));
		str[end - source] = 0;
		for (; start < end; start++) {
			str[start - source] = *start;
		}
		start += tkn_size;
		source = start;
		plib_stack_push(buffer, str);
	}

	*result = malloc(index * sizeof(char *));
	while (buffer->size > 0) {
		char *str = plib_stack_pop(buffer);
		(*result)[buffer->size] = str;
	}

	return index;
}

char *plib_fgetpass(char *s, int size, FILE *stream)
{
	struct termios old_flags, new_flags;

	/* disabling echo */
	tcgetattr(fileno(stream), &old_flags);
	new_flags = old_flags;
	new_flags.c_lflag &= ~ECHO;
	new_flags.c_lflag |= ECHONL;

	if (tcsetattr(fileno(stream), TCSANOW, &new_flags) != 0)
		plib_sdie("terminal set attribute:");

	s = fgets(s, size, stream);

	/* restore terminal */
	if (tcsetattr(fileno(stream), TCSANOW, &old_flags) != 0)
		plib_sdie("terminal set attribute:");

	return s;
}
