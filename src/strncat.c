#include "s21_string.h"

/*
Добавляет строку src, в конец строки dest, длиной до n символов.
Возвращает указатель на dest
*/

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *p = dest;
  while (*p != '\0') p++;

  s21_size_t j = 0;
  while (j < n && src[j] != '\0') {
    p[j] = src[j];
    j++;
  }
  p[j] = '\0';
  return dest;
}