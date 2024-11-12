#ifndef C2_S21_STRINGPLUS_1_SRC_S21_STRING_H
#define C2_S21_STRINGPLUS_1_SRC_S21_STRING_H

#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_NULL ((void *)0)
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

typedef struct {
  int left_justify;
  int plus_sign;
  int space_sign;
  int width;
  int precision;
  int length_h;
  int length_l;
} FormatSpec;

typedef unsigned long long s21_size_t;

void *s21_memchr(const void *, int, s21_size_t);
int s21_memcmp(const void *, const void *, s21_size_t);
void *s21_memcpy(void *, const void *, s21_size_t);
void *s21_memset(void *, int, s21_size_t);
char *s21_strncat(char *, const char *, s21_size_t);
char *s21_strchr(const char *, int);
int s21_strncmp(const char *, const char *, s21_size_t);
char *s21_strncpy(char *, const char *, s21_size_t);
s21_size_t s21_strcspn(const char *, const char *);
char *s21_strerror(int);
s21_size_t s21_strlen(const char *);
char *s21_strpbrk(const char *, const char *);
char *s21_strrchr(const char *, int);
char *s21_strstr(const char *, const char *);
char *s21_strtok(char *, const char *);

void *s21_to_upper(const char *);
void *s21_to_lower(const char *);
void *s21_insert(const char *, const char *, s21_size_t);
void *s21_trim(const char *, const char *);

int s21_sprintf(char *, const char *, ...);

void process_c(char *, char, FormatSpec, int *);
void process_d(char *, long long, FormatSpec, int *);
void process_f(char *, double, FormatSpec, int *);
void process_s(char *, const char *, FormatSpec, int *);
void process_u(char *, unsigned long long, FormatSpec, int *);

int process_format_spec(const char *, FormatSpec *);

char *int_to_str(unsigned long long);
char *float_to_str(double, int);
int s21_atoi(const char *);

#endif  // C2_S21_STRINGPLUS_1_SRC_S21_STRING_H
