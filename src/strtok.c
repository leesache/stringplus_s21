#include "s21_string.h"

/*
Разбивает строку str на ряд токенов, разделенных delim.
*/

char *s21_strtok(char *str, const char *delim) {
  static char *token = S21_NULL;
  if (str) {
    token = str;
    while (*token && s21_strchr(delim, *token)) token++;
  }

  if (token != S21_NULL) {
    if (*token != '\0') {
      str = token;
      while (*token && !s21_strchr(delim, *token)) ++token;
      while (*token && s21_strchr(delim, *token)) *token++ = '\0';
    } else {
      str = S21_NULL;
    }
  } else {
    str = S21_NULL;
  }
  return str;
}
