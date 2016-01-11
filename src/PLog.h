/*
 * In The Name Of God
 * ========================================
 * [] File Name : log.h
 *
 * [] Creation Date : 18-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef PLIB_PLOG_H
#define PLIB_PLOG_H

typedef void (*PExitHandler)(void *data);

void plib_register_exit_handler(PExitHandler handler, void *data, int free);

void plib_sdie(const char *fmt, ...)
	__attribute__((format(printf, 1, 2)));

void plib_udie(const char *fmt, ...)
	__attribute__((format(printf, 1, 2)));

void plib_ulog(const char *fmt, ...)
	__attribute__((format(printf, 1, 2)));

void plib_slog(const char *fmt, ...)
	__attribute__((format(printf, 1, 2)));

#endif
