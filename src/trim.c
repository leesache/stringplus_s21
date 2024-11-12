#include "s21_string.h"

/*
Возвращает новую строку, в которой удаляются все начальные и конечные вхождения
набора trim_chars из строки src. В случае какой-либо ошибки следует вернуть
значение S21_NULL.
*/

void *s21_trim(const char *src, const char *trim_chars) {
  void *result = S21_NULL;

  if (src != S21_NULL && trim_chars != S21_NULL) {
    s21_size_t src_length = s21_strlen(src);
    s21_size_t start_index = 0;
    s21_size_t end_index = src_length > 0 ? src_length - 1 : 0;

    while (src[start_index] != '\0' &&
           s21_strchr(trim_chars, src[start_index]) != S21_NULL) {
      start_index++;
    }

    while (end_index > start_index &&
           s21_strchr(trim_chars, src[end_index]) != S21_NULL) {
      end_index--;
    }

    s21_size_t trimmed_length = end_index - start_index + 1;

    char *trimmed_str = (char *)malloc((trimmed_length + 1) * sizeof(char));
    if (trimmed_str != S21_NULL) {
      s21_strncpy(trimmed_str, src + start_index, trimmed_length);
      trimmed_str[trimmed_length] = '\0';
      result = (void *)trimmed_str;
    }
  }
  return result;
}
