#include "s21_string.h"

/*
Побайтно сравнивает 2 области памяти
Возвращает 0, если обе области памяти равны;
Отрицательное число, если первая область памяти меньше второй;
Положительное число, если первая область памяти больше второй
*/

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
  const char* p1 = str1;
  const char* p2 = str2;
  int result = 0;
  for (s21_size_t i = 0; i < n && result == 0; i++) {
    if (p1[i] != p2[i]) {
      result = p1[i] - p2[i];
      if (result > 0) result = 1;
      if (result < 0) result = -1;
    }
  }
  return result;
}