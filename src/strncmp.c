#include "s21_string.h"

/*
Сравнивает не более первых n байтов str1 и str2
Возвращает 0, если обе области памяти равны;
Отрицательное число, если первая область памяти меньше второй;
Положительное число, если первая область памяти больше второй
*/

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n && result == 0; i++) {
    if (str1[i] != str2[i]) result = str1[i] - str2[i];
  }
  return result;
}