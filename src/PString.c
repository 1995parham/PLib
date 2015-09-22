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

#include "PString.h"

int plib_string_tokenizer(const char *source, const char *token)
{
	char *x;
	char **result;
	int index = 0;
	while ((x = strstr(source, token)) != NULL) {

	}
	return 0;
}

char *string_tokenizer(char *a, char *b)
{
	char *x = strstr(a, b);
	if (x == NULL)
		return a;
	char **result;
	result = (char **) malloc(sizeof(char *));
	int i = 1;
	result[0] = (char *) malloc(sizeof(char) * 20);
	strncpy(result[0], a, x - a);
	result[0][x - a] = '\0';
	a = strlen(b) + x;
	while (strstr(a, b) != NULL) {
		i++;
		x = strstr(a, b);
		result = realloc(result, sizeof(char *) * i);
		result[i - 1] = (char *) malloc(sizeof(char) * 20);
		strncpy(result[i - 1], a, x - a);
		result[i - 1][x - a] = '\0';
		a = strlen(b) + x;
	}
	i++;
	result = realloc(result, sizeof(char *) * i);
	result[i - 1] = (char *) malloc(sizeof(char) * 20);
	strncpy(result[i - 1], a, a - x);
	result[i - 1][a - x] = '\0';
	int j, h;
	for (j = 0; j < i - 1; j++) {
		printf("%s\n", result[j]);
	}

}

int main()
{
	char *s = "a123bb123ccc123dddd123eeeee123fffffffffff123fff";
	char *token = "123";
	string_tokenizer(s, token);
	return 0;
}
