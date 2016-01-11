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
#ifndef PLIB_LOG_H
#define PLIB_LOG_H

void plib_sdie(const char *fmt, ...)
	__attribute__((format(printf, 1, 2)));

void plib_udie(const char *fmt, ...)
	__attribute__((format(printf, 1, 2)));

void plib_ulog(const char *fmt, ...)
	__attribute__((format(printf, 1, 2)));

void plib_slog(const char *fmt, ...)
	__attribute__((format(printf, 1, 2)));

#endif
