#include "s21_string.h"

/*
Копирует символ c в первые n символов строки str
Возвращает указатель на str
*/

void *s21_memset(void *str, int c, s21_size_t n) {
  char *p = str;
  for (s21_size_t i = 0; i < n; i++) {
    p[i] = (char)c;
  }
  return str;
}