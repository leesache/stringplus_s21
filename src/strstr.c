#include "s21_string.h"

/*
Находит первое вхождение всей строки needle (не включая '\0'), которая
появляется в строке haystack.
*/

char *s21_strstr(const char *haystack, const char *needle) {
  const char *result = S21_NULL;
  if (*needle == '\0') result = haystack;

  for (int i = 0; haystack[i] != '\0' && result == S21_NULL; i++) {
    int j = 0;
    while (needle[j] != '\0' && haystack[i + j] == needle[j]) j++;

    if (needle[j] == '\0') result = &haystack[i];
  }

  return (char *)result;
}