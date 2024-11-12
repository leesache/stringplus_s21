#include "s21_string.h"

/*
Находит первый символ в строке str1, который соответствует любому символу,
указанному в str2.
*/

char* s21_strpbrk(const char* str1, const char* str2) {
  const char* result = S21_NULL;

  for (int i = 0; str1[i] != '\0' && result == S21_NULL; i++) {
    if (s21_strchr(str2, str1[i])) result = &str1[i];
  }

  return (char*)result;
}