#include "s21_string.h"

/*
Ищет первое вхождение символа в области памяти
Возвращает указатель на этот символ
*/

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *p = str;
  void *result = S21_NULL;
  for (s21_size_t i = 0; i < n && result == S21_NULL; i++) {
    if (p[i] == (char)c) {
      result = (void *)(p + i);
    }
  }
  return result;
}
