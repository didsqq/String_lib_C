#include "s21_string.h"

int s21_sprintf(char* str, const char* format, ...) {
  va_list arg;
  va_start(arg, format);

  for (int i = 0; i <= s21_strlen(format); i++) str[i] = '\0';

  str_parser(str, format, arg);
  int count_symbols = s21_strlen(str);
  va_end(arg);
  return count_symbols;
}

void str_parser(char* str, const char* format, va_list arg) {
  while (*format != '\0') {
    if (*format == '%') {
      format++;
      flags flags = {0};
      format = flags_parser(format, &flags);
      format = string_to_int(format, &flags);
      format = accuracy_parser(format, &flags);
      format = length_parser(format, &flags);
      str = specificator_parser(str, arg, *format, flags);
    } else {
      *str++ = *format;
    }
    format++;
  }
}

const char* string_to_int(const char* format, flags* flags) {
  char* number = calloc(BUF, sizeof(char));
  int int_number = 0, i = 0;
  if (number != s21_NULL) {
    while (*format > 47 && *format < 58) {
      number[i] = *format;
      i++;
      format++;
    }
    for (int i = 0, j = s21_strlen(number) - 1; i < s21_strlen(number);
         i++, j--) {
      int_number += ((int)number[j] - '0') * pow(10, i);
    }
    if (!flags->accuracy_bool) {
      flags->width = int_number;
    } else if (flags->accuracy_bool) {
      flags->accuracy = int_number;
    }
  }
  safe_free(number);
  return format;
}

int int_to_string(char* str, long int number, int flag_minus, flags flags,
                  int int_part) {
  int i = 0, number_size = 0, space_count = 0;
  long int j = number;
  for (; j > 0; j /= 10) {
    number_size++;
  }
  if (number == 0) {
    number_size++;
  }
  if (flags.minus) {
    space_count += space_count_when_minus(flags, number_size);
    i = width_shift(flags, int_part, str, i, space_count);
    i = int_add_to_string(number, int_part, str, i, flags, number_size);
    i = sign_add(flags, flag_minus, str, i, int_part);
  } else {
    i = int_add_to_string(number, int_part, str, i, flags, number_size);
    i = sign_add(flags, flag_minus, str, i, int_part);
    space_count += flags.width - s21_strlen(str);
    i = width_shift(flags, int_part, str, i, space_count);
  }
  reverse_str(str);
  return i;
}

int space_count_when_minus(flags flags, int number_size) {
  int space_count = 0;
  if (flags.accuracy_bool == 0) {
    space_count += flags.width - number_size;
  } else if (number_size < flags.accuracy) {
    space_count += flags.width - flags.accuracy;
  } else {
    space_count += flags.width - number_size;
  }
  if (flags.space) {
    space_count--;
  }
  if (flags.plus) {
    space_count--;
  }
  return space_count;
}

int sign_add(flags flags, int flag_minus, char* str, int i, int int_part) {
  if (int_part) {
    if (flag_minus == 1) {
      str[i++] = '-';
    } else if (flags.plus) {
      str[i++] = '+';
    } else if (flags.space) {
      str[i++] = ' ';
    }
  }
  return i;
}

int width_shift(flags flags, int int_part, char* str, int i, int space_count) {
  if (flags.accuracy_bool && flags.width != 0 && int_part &&
      !flags.number_not_integer) {
    while (space_count > 0 && space_count <= flags.width - flags.accuracy) {
      str[i++] = ' ';
      space_count--;
    }
  } else if (flags.width != 0 && int_part && !flags.number_not_integer) {
    while (space_count > 0) {
      str[i++] = ' ';
      space_count--;
    }
  }
  return i;
}

int int_add_to_string(long int number, int int_part, char* str, int i,
                      flags flags, int number_size) {
  if (number == 0 && !int_part) {
    for (int j = 0; j < 6 && j < flags.accuracy; j++) {
      str[i++] = '0';
    }
  } else if (number == 0 && int_part && !flags.number_not_integer &&
             flags.accuracy_bool) {
    for (int j = 0; j < flags.accuracy; j++) {
      str[i++] = '0';
    }
  } else if (number == 0 && int_part) {
    str[i++] = '0';
  } else {
    int j;
    if (flags.accuracy < number_size) {
      j = number_size;
    } else {
      j = flags.accuracy;
    }
    for (; number > 0 && j > 0; number /= 10, j--) {
      str[i++] = number % 10 + '0';
    }
    if (flags.number_not_integer) {
      for (; flags.accuracy - number_size > 0 && !int_part; flags.accuracy--) {
        str[i++] = '0';
      }
    } else {
      for (; flags.accuracy - number_size > 0 && int_part; flags.accuracy--) {
        str[i++] = '0';
      }
    }
  }
  return i;
}

char* spec_f(char* str, va_list arg, flags flags) {
  char* buf_int = calloc(BUF, sizeof(char));
  char* buf_not_int = calloc(BUF, sizeof(char));
  char* buf_str = calloc(BUF, sizeof(char));
  if (buf_int != s21_NULL && buf_not_int != s21_NULL && buf_str != s21_NULL) {
    int str_shift = 0, flag_minus = 0;
    double v = va_arg(arg, double);
    if (v < 0) {
      v *= -1;
      flag_minus = 1;
    }
    long int int_part = (int)v;
    double non_int_part = v - int_part;
    if (flags.accuracy_bool) {
      non_int_part *= pow(10, flags.accuracy);
    } else {
      non_int_part *= 1000000;
    }
    str_shift += int_to_string(buf_int, int_part, flag_minus, flags, INT_PART);
    if (!(flags.accuracy == 0 && flags.accuracy_bool)) {
      buf_int[str_shift++] = '.';
    }
    str_shift += int_to_string(buf_not_int, (long int)round(non_int_part), 0,
                               flags, FLOAT_PART);
    if (v - int_part == 0) {
      for (int i = 0; i < 6; i++) {
        buf_int[str_shift++] = '0';
      }
    }
    for (int i = 0, space_add = flags.width - s21_strlen(buf_int) -
                                s21_strlen(buf_not_int);
         space_add > 0; space_add--) {
      buf_str[i++] = ' ';
      str_shift++;
    }
    s21_strncat(buf_str, buf_int, s21_strlen(buf_int));
    s21_strncat(buf_str, buf_not_int, s21_strlen(buf_not_int));
    s21_strncat(str, buf_str, s21_strlen(buf_str));
    for (; str_shift > 0; str_shift--) {
      str++;
    }
  }
  safe_free(buf_not_int);
  safe_free(buf_int);
  safe_free(buf_str);
  return str;
}
char* spec_d(char* str, va_list arg, flags flags) {
  char* buf = calloc(BUF, sizeof(char));
  if (buf != s21_NULL) {
    int flag_minus = 0, str_shift = 0;
    long int v = va_arg(arg, long int);
    if (flags.l_length) {
      v = (long int)v;
    } else if (flags.h_length) {
      v = (short int)v;
    } else {
      v = (int)v;
    }
    if (v < 0) {
      v *= -1;
      flag_minus = 1;
    }
    if (!(v == 0 && flags.accuracy_bool && flags.accuracy == 0)) {
      str_shift = int_to_string(buf, v, flag_minus, flags, INT_PART);
    }
    s21_strncat(str, buf, s21_strlen(buf));
    for (; str_shift > 0; str_shift--) {
      str++;
    }
  }
  safe_free(buf);
  return str;
}
char* spec_u(char* str, va_list arg, flags flags) {
  char* buf = calloc(BUF, sizeof(char));
  if (buf != s21_NULL) {
    int flag_minus = 0;
    unsigned long int v = va_arg(arg, unsigned long int);
    if (flags.h_length) {
      v = (unsigned short int)v;
    } else if (flags.l_length) {
      v = (unsigned long int)v;
    } else {
      v = (unsigned int)v;
    }
    int str_shift = int_to_string(buf, v, flag_minus, flags, INT_PART);
    s21_strncat(str, buf, s21_strlen(buf));
    for (; str_shift > 0; str_shift--) {
      str++;
    }
  }
  safe_free(buf);
  return str;
}

char* spec_s(char* str, va_list arg, flags flags) {
  if (flags.l_length) {
    wchar_t* wc = va_arg(arg, wchar_t*);
    if (wc != s21_NULL) {
      int limit = flags.accuracy_bool ? flags.accuracy : (int)wcslen(wc);
      for (int i = 0; i < limit && flags.minus; i++) {
        *str++ = wc[i];
      }
      for (int i = 0; i < flags.width - limit; i++) {
        *str++ = ' ';
      }
      for (int i = 0; i < limit && !flags.minus; i++) {
        *str++ = wc[i];
      }
    }
  } else {
    char* buf = va_arg(arg, char*);
    if (buf != s21_NULL) {
      int limit = flags.accuracy_bool ? flags.accuracy : s21_strlen(buf);
      for (int i = 0; i < limit && flags.minus; i++) {
        *str++ = buf[i];
      }
      for (int i = 0; i < flags.width - limit; i++) {
        *str++ = ' ';
      }
      for (int i = 0; i < limit && !flags.minus; i++) {
        *str++ = buf[i];
      }
    }
  }
  *str = '\0';
  return str;
}

char* spec_c(char* str, va_list arg, flags flags) {
  if (flags.minus) {
    char c = va_arg(arg, int);
    *str++ = c;
  }
  for (int i = 0; i < flags.width - 1; i++) {
    *str = ' ';
    str++;
  }
  if (!flags.minus) {
    char c = va_arg(arg, int);
    *str++ = c;
  }
  return str;
}

char* spec_percent(char* str, flags flags) {
  if (flags.minus) {
    *str++ = '%';
  }
  for (int i = 0; i < flags.width - 1; i++) {
    *str = ' ';
    str++;
  }
  if (!flags.minus) {
    *str++ = '%';
  }
  return str;
}

void reverse_str(char* buf) {
  for (int i = 0, j = s21_strlen(buf) - 1; i < j; i++, j--) {
    char c = buf[i];
    buf[i] = buf[j];
    buf[j] = c;
  }
}

void safe_free(char* str) {
  if (str != NULL) {
    free(str);
  }
}

char* specificator_parser(char* str, va_list arg, char c, flags flags) {
  if (c == 'c') {
    str = spec_c(str, arg, flags);
  } else if (c == 'd') {
    str = spec_d(str, arg, flags);
  } else if (c == 'f') {
    flags.number_not_integer = 1;
    str = spec_f(str, arg, flags);
  } else if (c == 's') {
    str = spec_s(str, arg, flags);
  } else if (c == 'u') {
    str = spec_u(str, arg, flags);
  } else if (c == '%') {
    str = spec_percent(str, flags);
  }
  return str;
}

const char* accuracy_parser(const char* format, flags* flags) {
  if (*format == '.') {
    flags->accuracy_bool = 1;
    format++;
    format = string_to_int(format, flags);
  }
  return format;
}
const char* length_parser(const char* format, flags* flags) {
  if (*format == 'l') {
    flags->l_length = 1;
    format++;
  } else if (*format == 'h') {
    flags->h_length = 1;
    format++;
  }
  return format;
}
const char* flags_parser(const char* format, flags* flags) {
  while (*format == '+' || *format == '-' || *format == ' ') {
    if (*format == '+') {
      flags->plus = 1;
    }
    if (*format == '-') {
      flags->minus = 1;
    }
    if (*format == ' ' && !flags->plus) {
      flags->space = 1;
    }
    if (flags->space && flags->plus) {
      flags->space = 0;
    }
    format++;
  }
  return format;
}