#include "s21_string.h"

/*
Копирует n символов из src в dest
Возвращает dest
*/

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *pdest = dest;
  const char *psrc = src;
  for (s21_size_t i = 0; i < n; i++) {
    pdest[i] = psrc[i];
  }
  return dest;
}
