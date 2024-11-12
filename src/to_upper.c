#include "s21_string.h"

/*
Возвращает копию строки (str), преобразованной в верхний регистр.
В случае какой-либо ошибки следует вернуть значение S21_NULL.
*/

void *s21_to_upper(const char *str) {
  void *result = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t length = s21_strlen(str);

    char *upper_str = (char *)malloc((length + 1) * sizeof(char));
    if (upper_str != S21_NULL) {
      for (s21_size_t i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          upper_str[i] = str[i] - ('a' - 'A');
        } else {
          upper_str[i] = str[i];
        }
      }
      upper_str[length] = '\0';
      result = (void *)upper_str;
    }
  }
  return result;
}