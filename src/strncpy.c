#include "s21_string.h"

/*
Копирует до n символов из строки src, в dest.
Возвращает dest
*/

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  for (; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }

  for (; i < n; i++) {
    dest[i] = '\0';
  }
  return dest;
}