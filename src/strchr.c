#include "s21_string.h"

/*
Выполняет поиск первого вхождения символа c в строке str
Возвращает указатель на этот символ
*/

char *s21_strchr(const char *str, int c) {
  const char *result = S21_NULL;

  for (int i = 0; result == S21_NULL && (str[i] != '\0' || c == '\0'); i++) {
    if (str[i] == c) {
      result = &str[i];
    }
  }
  return (char *)result;
}