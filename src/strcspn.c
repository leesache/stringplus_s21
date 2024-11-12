#include "s21_string.h"

/*
Вычисляет длину начального сегмента str1, который полностью состоит из символов,
не входящих в str2.
*/

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  int found = 0;
  for (s21_size_t i = 0; str1[i] != '\0' && !found; i++) {
    for (s21_size_t j = 0; str2[j] != '\0' && !found; j++) {
      if (str1[i] == str2[j]) {
        found = 1;
      }
    }
    if (!found) result++;
  }
  return result;
}