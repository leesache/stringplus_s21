#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int count = 0;
  int str_index = 0;

  while (format[count] != '\0') {
    if (format[count] == '%') {
      count++;
      FormatSpec spec = {0, 0, 0, 0, -1, 0, 0};
      int format_length = process_format_spec(&format[count], &spec);
      count += format_length;
      switch (format[count]) {
        case 'c':
          process_c(str, (char)va_arg(args, int), spec, &str_index);
          break;
        case 'd':
          process_d(str, va_arg(args, long long), spec, &str_index);
          break;
        case 'f':
          process_f(str, va_arg(args, double), spec, &str_index);
          break;
        case 's':
          process_s(str, va_arg(args, char *), spec, &str_index);
          break;
        case 'u':
          process_u(str, va_arg(args, unsigned long long), spec, &str_index);
          break;
        case '%':
          str[str_index++] = '%';
          break;
        default:
          printf("ERROR\n");
          break;
      }
      count++;
    } else {
      str[str_index++] = format[count++];
    }
  }
  str[str_index] = '\0';
  va_end(args);
  return str_index;
}

int process_format_spec(const char *format, FormatSpec *spec) {
  int length = 0;
  while (s21_strchr("1234567890+- .hl", *format)) {
    length++;
    if (*format == '-') {
      spec->left_justify = 1;
      format++;
    } else if (*format == '+') {
      spec->plus_sign = 1;
      format++;
    } else if (*format == ' ') {
      spec->space_sign = 1;
      format++;
    } else if (isdigit(*format)) {
      spec->width = s21_atoi(format);
      format++;
      while (isdigit(*format)) {
        length++;
        format++;
      }
      continue;
    } else if (*format == '.') {
      format++;
      if (isdigit(*format)) {
        spec->precision = s21_atoi(format);
        while (isdigit(*format)) {
          format++;
          length++;
        }
      } else {
        spec->precision = 0;
      }
    } else if (*format == 'h') {
      spec->length_h = 1;
      format++;
    } else if (*format == 'l') {
      spec->length_l = 1;
      format++;
    }
  }
  return length;
}

void process_c(char *str, char c, FormatSpec spec, int *index) {
  if (spec.width > 1 && !spec.left_justify) {
    for (int i = 1; i < spec.width; i++) str[(*index)++] = ' ';
  }
  str[(*index)++] = c;
  if (spec.width > 1 && spec.left_justify) {
    for (int i = 1; i < spec.width; i++) str[(*index)++] = ' ';
  }
}

void process_d(char *str, long long d, FormatSpec spec, int *index) {
  if (!spec.length_l && !spec.length_h)
    d = (int)d;
  else if (spec.length_h && (d > SHRT_MAX || d < SHRT_MIN))
    d = (short)d;

  long long absd = d > 0 ? d : -d;
  char *num_str = int_to_str(absd);
  int len = s21_strlen(num_str);
  int precision = MAX(0, spec.precision - len);
  int width = spec.width - len - precision;

  if ((d >= 0 && (spec.plus_sign || spec.space_sign)) || d < 0) width--;

  if (!spec.left_justify && width > 0) {
    for (int i = 0; i < width; i++) {
      str[(*index)++] = ' ';
    }
  }

  if (d >= 0 && (spec.plus_sign || spec.space_sign)) {
    str[(*index)++] = (spec.plus_sign) ? '+' : ' ';
  }

  if (d < 0) str[(*index)++] = '-';

  for (int i = 0; i < precision; i++) {
    str[(*index)++] = '0';
  }

  if (d != 0 || spec.precision != 0) {
    s21_strncpy(&str[*index], num_str, len);
    *index += len;
  }

  if (spec.left_justify && width > 0) {
    for (int i = 0; i < width; i++) {
      str[(*index)++] = ' ';
    }
  }
  free(num_str);
}

void process_u(char *str, unsigned long long u, FormatSpec spec, int *index) {
  if (!spec.length_l && !spec.length_h)
    u = (unsigned)u;
  else if (spec.length_h && (u > USHRT_MAX))
    u = (unsigned short)u;

  char *num_str = int_to_str(u);
  int len = s21_strlen(num_str);
  int precision = MAX(0, spec.precision - len);
  int width = spec.width - len - precision;

  if (spec.plus_sign || spec.space_sign) width--;

  if (!spec.left_justify && width > 0) {
    for (int i = 0; i < width; i++) {
      str[(*index)++] = ' ';
    }
  }

  for (int i = 0; i < precision; i++) {
    str[(*index)++] = '0';
  }

  if (u != 0 || spec.precision != 0) {
    s21_strncpy(&str[*index], num_str, len);
    *index += len;
  }

  if (spec.left_justify && width > 0) {
    for (int i = 0; i < width; i++) {
      str[(*index)++] = ' ';
    }
  }

  free(num_str);
}

void process_f(char *str, double f, FormatSpec spec, int *index) {
  double absf = f > 0 ? f : -f;
  char *num_str = float_to_str(absf, spec.precision != -1 ? spec.precision : 6);
  int len = s21_strlen(num_str);
  char *dot_ptr = s21_strrchr(num_str, '.');
  int len_frac = 0;

  if (dot_ptr != S21_NULL) {
    len_frac = s21_strlen(dot_ptr + 1);
  }

  int precision =
      spec.precision != -1 ? spec.precision - len_frac : 6 - len_frac;
  int width = spec.width - len - precision;

  if ((f >= 0 && (spec.plus_sign || spec.space_sign)) || f < 0) width--;

  if (!spec.left_justify && width > 0) {
    for (int i = 0; i < width; i++) {
      str[(*index)++] = ' ';
    }
  }

  if (f >= 0 && (spec.plus_sign || spec.space_sign)) {
    str[(*index)++] = (spec.plus_sign) ? '+' : ' ';
  }

  if (f < 0) str[(*index)++] = '-';

  s21_strncpy(&str[*index], num_str, len);
  *index += len;

  for (int i = 0; i < precision; i++) {
    str[(*index)++] = '0';
  }

  if (spec.left_justify && width > 0) {
    for (int i = 0; i < width; i++) {
      str[(*index)++] = ' ';
    }
  }
  free(num_str);
}

void process_s(char *str, const char *s, FormatSpec spec, int *index) {
  int len = spec.precision > 0 && (s21_size_t)spec.precision < s21_strlen(s)
                ? (s21_size_t)spec.precision
                : s21_strlen(s);
  len = spec.precision == 0 ? 0 : len;
  int width = spec.width - len;

  if (!spec.left_justify && width > 0) {
    for (int i = 0; i < width; i++) {
      str[(*index)++] = ' ';
    }
  }

  s21_strncpy(&str[*index], s, len);
  *index += len;

  if (spec.left_justify && width > 0) {
    for (int i = 0; i < width; i++) {
      str[(*index)++] = ' ';
    }
  }
}

char *int_to_str(unsigned long long num) {
  int length = (num == 0) ? 1 : 0;
  for (long long n = num; n > 0; n /= 10) {
    length++;
  }

  char *str = (char *)malloc((length + 1) * sizeof(char));
  if (str != S21_NULL) {
    str[length] = '\0';
    for (int i = length - 1; i >= 0; i--) {
      str[i] = (num % 10) + '0';
      num /= 10;
    }
  }

  return str;
}

char *float_to_str(double num, int precision) {
  double temp_frac_part = num - (long long)num;
  if (precision == 0 && temp_frac_part > 0.5) {
    num += 1;
  }

  long long frac_part = round(temp_frac_part * pow(10, precision));
  long long temp_num = frac_part;
  int digits = frac_part ? 0 : 1;
  while (temp_num != 0) {
    temp_num /= 10;
    digits++;
  }

  while (frac_part % 10 == 0 && frac_part != 0) {
    frac_part /= 10;
  }

  char *frac_str = int_to_str(frac_part);
  char *int_str = int_to_str((long long)num);
  int count_zero = precision - digits < 0 ? 0 : precision - digits;
  int total_length = s21_strlen(int_str) +
                     (precision != 0 ? 1 + s21_strlen(frac_str) : 0) +
                     count_zero;
  char *str = (char *)calloc(total_length + 1, sizeof(char));
  if (str != NULL) {
    s21_strncat(str, int_str, s21_strlen(int_str));
    if (precision != 0) {
      s21_strncat(str, ".", 1);
      while (count_zero != 0) {
        s21_strncat(str, "0", 1);
        count_zero--;
      }
      s21_strncat(str, frac_str, s21_strlen(frac_str));
    }
  }

  free(int_str);
  free(frac_str);

  return str;
}

int s21_atoi(const char *str) {
  int result = 0;
  int sign = 1;

  while (isspace(*str)) str++;
  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    sign = 1;
    str++;
  }
  while (isdigit(*str)) {
    result = result * 10 + (*str - '0');
    str++;
  }
  return sign * result;
}