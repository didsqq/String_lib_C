#ifndef S21_STRING_H
#define S21_STRING_H

#define s21_size_t unsigned long long
#define s21_NULL (void *)0
#define FLOAT_PART 0
#define INT_PART 1
#define BUF 1000

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int s21_strlen(const char *str);
int s21_strcspn(const char *str1, const char *str2);
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strstr(const char *haystack, const char *needle);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strerror(int errnum);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
int left_trim(const char *trim_chars, char *buff, int n);

// sprintf
int s21_sprintf(char *str, const char *format, ...);

typedef struct {
  int minus;
  int plus;
  int space;
  int width;
  int accuracy;
  int accuracy_bool;
  int h_length;
  int l_length;
  int number_not_integer;
  wchar_t wc;
} flags;

// parsers
void str_parser(char *str, const char *format, va_list arg);
char *specificator_parser(char *str, va_list arg, char c, flags flags);
const char *flags_parser(const char *format, flags *flags);
const char *length_parser(const char *format, flags *flags);
const char *accuracy_parser(const char *format, flags *flags);
// specifiers
char *spec_c(char *str, va_list arg, flags flags);
char *spec_d(char *str, va_list arg, flags flags);
char *spec_f(char *str, va_list arg, flags flags);
char *spec_s(char *str, va_list arg, flags flags);
char *spec_u(char *str, va_list arg, flags flags);
char *spec_percent(char *str, flags flags);

int int_to_string(char *str, long int number, int flag_minus, flags flags,
                  int flag_f);
const char *string_to_int(const char *format, flags *flags);
int width_shift(flags flags, int flag_f, char *str, int i, int str_space);
int int_add_to_string(long int number, int flag_f, char *str, int i,
                      flags flags, int number_size);
int sign_add(flags flags, int flag_minus, char *str, int i, int flag_space);
int space_count_when_minus(flags flags, int number_size);
void reverse_str(char *buf);
void safe_free(char *str);

#endif