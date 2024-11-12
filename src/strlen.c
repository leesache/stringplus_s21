#include "s21_string.h"

/*
Вычисляет длину строки str без '\0'
*/

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}