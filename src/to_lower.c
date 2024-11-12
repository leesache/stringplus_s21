#include "s21_string.h"

/*
Возвращает копию строки (str), преобразованной в нижний регистр.
В случае какой-либо ошибки следует вернуть значение S21_NULL.
*/

void *s21_to_lower(const char *str) {
  void *result = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t length = s21_strlen(str);

    char *lower_str = (char *)malloc((length + 1) * sizeof(char));
    if (lower_str != S21_NULL) {
      for (s21_size_t i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          lower_str[i] = str[i] + ('a' - 'A');
        } else {
          lower_str[i] = str[i];
        }
      }
      lower_str[length] = '\0';
      result = (void *)lower_str;
    }
  }
  return result;
}