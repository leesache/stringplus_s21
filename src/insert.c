#include "s21_string.h"

/*
Возвращает новую строку, в которой строка str вставлена в позицию start_index в
строке src. В случае какой-либо ошибки следует вернуть значение S21_NULL.
*/

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  void *result = S21_NULL;

  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t src_length = s21_strlen(src);
    s21_size_t str_length = s21_strlen(str);

    if (start_index <= src_length) {
      char *new_str =
          (char *)malloc((src_length + str_length + 1) * sizeof(char));
      if (new_str != S21_NULL) {
        s21_strncpy(new_str, src, start_index);
        s21_strncpy(new_str + start_index, str, str_length);
        s21_strncpy(new_str + start_index + str_length, src + start_index,
                    src_length - start_index);

        new_str[src_length + str_length] = '\0';
        result = (void *)new_str;
      }
    }
  }
  return result;
}
