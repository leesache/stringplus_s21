#include "s21_string.h"

/*
Выполняет поиск последнего вхождения символа c в строке str.
*/

char* s21_strrchr(const char* str, int c) {
  const char* result = S21_NULL;
  int length = s21_strlen(str);

  for (int i = length; i >= 0 && result == S21_NULL; i--) {
    if (str[i] == c) {
      result = &str[i];
    }
  }
  return (char*)result;
}