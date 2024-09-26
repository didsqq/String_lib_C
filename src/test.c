#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(s21_memchr_test_1) {
  s21_size_t n_byte = 0;
  char str[10] = {""};
  int find_byte = '\0';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(s21_memchr_test_2) {
  s21_size_t n_byte = 7;
  char str[10] = {"string"};
  int find_byte = '\0';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(s21_memchr_test_3) {
  char str[50] = {"Hello w\0orld\0"};
  ck_assert_pstr_eq(memchr(str, 'r', 5), s21_memchr(str, 'r', 5));
}

END_TEST

START_TEST(s21_memchr_test_5) {
  char str3[50] = {'q', 'r', 's', 't', 'w', '\0'};
  ck_assert_pstr_eq(memchr(str3, 's', 5), s21_memchr(str3, 's', 5));
}
END_TEST

START_TEST(s21_memchr_test_6) {
  s21_size_t n_byte = 6;
  char str[10] = {"Atring"};
  int find_byte = 'A';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(s21_memchr_test_7) {
  s21_size_t n_byte = 7;
  char str[10] = {"StringA"};
  int find_byte = 'A';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(s21_memchr_test_8) {
  s21_size_t n_byte = 15;
  char str[16] = {"Str55333222ingA"};
  int find_byte = '3';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(s21_memcmp_test_1) {
  char test_str[50][20] = {"Hello, World!", "Hello", "Hello\0World!"};
  s21_size_t num[50] = {0, 1, 2, 10, 20};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 5; k++) {
        ck_assert_int_eq(s21_memcmp(test_str[i], test_str[j], num[k]),
                         memcmp(test_str[i], test_str[j], num[k]));
      }
}
END_TEST

START_TEST(s21_memcmp_test_2) {
  int test_int[50] = {0, 1, -21, -42, 1234567};
  s21_size_t num[50] = {0, 1};
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      for (int k = 0; k < 2; k++) {
        ck_assert_int_eq(s21_memcmp(&test_int[i], &test_int[j], num[k]),
                         memcmp(&test_int[i], &test_int[j], num[k]));
      }
}
END_TEST

START_TEST(s21_memcmp_test_3) {
  char str1[50] = {"aboba"};
  char str2[50] = {"aboba"};
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(s21_memcmp_test_4) {
  char str1[50] = {"aboba"};
  char str2[50] = {"aboba"};
  int n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(s21_memcmp_test_5) {
  char str1[50] = {"aboba"};
  char str2[50] = {"Aboba"};
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(s21_memcmp_test_6) {
  char str1[50] = {"1"};
  char str2[50] = {"1"};
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(s21_memcmp_test_7) {
  char str1[50] = {"1"};
  char str2[50] = {"1234"};
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(s21_memcmp_test_8) {
  char str1[50] = {"1234"};
  char str2[50] = {"1234"};
  int n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(s21_memcmp_test_10) {
  char str1[100] = {
      "111111111111111111112312312312312312434524563567adsfe 4rafa "
      "ewfseASDASD"};
  char str2[100] = {
      "111111111111111111112312312312312312434524563567adsfe 4rafa "
      "ewfseASDASd"};
  int n = 71;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(s21_memcpy_test_1) {
  char test_str[50][20] = {"Hello, World!", "Hello\0World!\0", "", "\0"};
  s21_size_t num[50] = {0, 1, 2, 10, 20};
  char str_s21[2048] = {""};
  char str_original[2048] = {""};
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 5; j++) {
      ck_assert_pstr_eq(s21_memcpy(str_s21, test_str[i], num[j]),
                        memcpy(str_original, test_str[i], num[j]));
      ck_assert_mem_eq(str_s21, str_original, num[j]);
    }
}
END_TEST

START_TEST(s21_memcpy_test_2) {
  s21_size_t n1 = 3;
  char b1[1024] = {""};
  char b11[1024] = {""};
  char str_1_2[1024] = {"ABOBA THE BEST!"};
  ck_assert_pstr_eq(memcpy(b1, str_1_2, n1), s21_memcpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(s21_memcpy_test_3) {
  s21_size_t n2 = 5;
  char b2[1024] = {""};
  char b22[1024] = {""};
  char str_2_2[1024] = {"THE OF \0BEST!!"};
  ck_assert_pstr_eq(memcpy(b2, str_2_2, n2), s21_memcpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(s21_memcpy_test_4) {
  s21_size_t n3 = 4;
  char b3[1024] = {"777 "};
  char b33[1024] = {"777 "};
  char str_3_2[1024] = {"ABOBA!"};
  ck_assert_pstr_eq(memcpy(b3, str_3_2, n3), s21_memcpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(s21_memcpy_test_5) {
  s21_size_t n4 = 4;
  char b4[1024] = {"ABOBA! 777 "};
  char b44[1024] = {"ABOBA! 777 "};
  ck_assert_pstr_eq(memcpy(b4, b4 + 7, n4), s21_memcpy(b44, b44 + 7, n4));
}
END_TEST

START_TEST(s21_memset_test_1) {
  char str_s21[50] = {"Hello, World!"};
  char str_original[50] = {"Hello, World!"};
  char v = '1';
  int n = 5;
  ck_assert_pstr_eq(s21_memset(str_s21, v, n), memset(str_original, v, n));
  ck_assert_mem_eq(str_s21, str_original, n);
}
END_TEST

START_TEST(s21_memset_test_2) {
  char str_s21[50] = {"Hello, World!"};
  char str_original[50] = {"Hello, World!"};
  char v = '2';
  int n = 0;
  ck_assert_pstr_eq(s21_memset(str_s21, v, n), memset(str_original, v, n));
  ck_assert_mem_eq(str_s21, str_original, n);
}
END_TEST

START_TEST(s21_memset_test_3) {
  char str_s21[50] = {""};
  char str_original[50] = {""};
  char v = '3';
  int n = 0;
  ck_assert_pstr_eq(s21_memset(str_s21, v, n), memset(str_original, v, n));
  ck_assert_mem_eq(str_s21, str_original, n);
}
END_TEST

START_TEST(s21_memset_test_4) {
  char str_s21[50] = {"Hello, World!"};
  char str_original[50] = {"Hello, World!"};
  char v = '/';
  int n = 4;
  ck_assert_pstr_eq(s21_memset(str_s21, v, n), memset(str_original, v, n));
  ck_assert_mem_eq(str_s21, str_original, n);
}
END_TEST

START_TEST(s21_memset_test_5) {
  char res[50] = {"aboba"};
  char expected[50] = {"aboba"};
  char replace = 'A';
  s21_size_t n_byte = 3;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(s21_memset_test_6) {
  char res[50] = {"a1obA"};
  char expected[50] = {"a1obA"};
  char replace = '1';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(s21_memset_test_7) {
  char res[100] = {
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA"};
  char expected[100] = {
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA"};
  char replace = '1';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(s21_memset_test_8) {
  char res[50] = {"aboba"};
  char expected[50] = {"aboba"};
  char replace = 'g';
  s21_size_t n_byte = 0;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(s21_memset_test_9) {
  char res[50] = {""};
  char expected[50] = {""};
  char replace = '\0';
  s21_size_t n_byte = 0;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(s21_memset_test_10) {
  char res[50] = {"aboba"};
  char expected[50] = {"aboba"};
  char replace = 'g';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(s21_strncat_test_1) {
  char test_str[50][64] = {"Hello, World!", "Hello\0World!\0", "", "\0"};
  char str_s21[50][64] = {"Hello, World!", "Hello\0World!\0", "", "\0"};
  char str_original[50][64] = {"Hello, World!", "Hello\0World!\0", "", "\0"};
  size_t num[50] = {0, 1, 10, 30};
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 2; k++) {
        ck_assert_pstr_eq(s21_strncat(str_s21[i], test_str[j], num[k]),
                          strncat(str_original[i], test_str[j], num[k]));
        ck_assert_pstr_eq(str_s21[i], str_original[i]);
      }
}
END_TEST

START_TEST(s21_strncat_test_2) {
  s21_size_t n1 = 2;
  char b1[1024] = {""};
  char b11[1024] = {""};
  char str_1_2[1024] = {"VLASTELINI UTROBI THE BEST!"};
  ck_assert_pstr_eq(strncat(b1, str_1_2, n1), s21_strncat(b11, str_1_2, n1));
}
END_TEST

START_TEST(s21_strncat_test_3) {
  s21_size_t n3 = 2;
  char b3[1024] = {"777"};
  char b33[1024] = {"777"};
  char str_3_2[1024] = {" VLASTELINI UTROBI!"};
  ck_assert_pstr_eq(strncat(b3, str_3_2, n3), s21_strncat(b33, str_3_2, n3));
}
END_TEST

START_TEST(strncat_BIGFLOPPA) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 5;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA2) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA3) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 1;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA4) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 10;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_zero_char) {
  char src[] = "\0";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 1;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(s21_strncat_1) {
  char s1[50] = "Hello world\0";
  char s2[50] = " world\0";
  char s3[50] = "Hello world\0";
  ck_assert_str_eq(s21_strncat(s1, s2, 3), strncat(s3, s2, 3));
}
END_TEST

START_TEST(s21_strncat_2) {
  char s1[50] = "a\n\0";
  char s2[50] = " \n\0";
  char s3[50] = "a\n\0";
  ck_assert_str_eq(s21_strncat(s1, s2, 3), strncat(s3, s2, 3));
}
END_TEST

START_TEST(s21_strncat_3) {
  char s1[50] = " \0";
  char s2[50] = "\n\0";
  char s3[50] = " \0";
  ck_assert_str_eq(s21_strncat(s1, s2, 1), strncat(s3, s2, 1));
}
END_TEST

START_TEST(s21_strncat_4) {
  char s1[50] = "\0";
  char s2[50] = "\n\0";
  char s3[50] = "\0";
  ck_assert_str_eq(s21_strncat(s1, s2, 1), strncat(s3, s2, 1));
}
END_TEST

START_TEST(s21_strchr_test_1) {
  char s1[50] = {"asdf\0"};
  char s3[50] = {"asdf\0"};
  ck_assert_str_eq(s21_strchr(s1, 'a'), strchr(s3, 'a'));
}
END_TEST

START_TEST(s21_strchr_test_2) {
  char src[50] = {"abobasaaaa"};
  char find = 'a';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(s21_strchr_test_3) {
  char src[50] = {"abobasAsa"};
  char find = 'A';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(s21_strchr_test_4) {
  char src[50] = {"abobasA1sa"};
  char find = '1';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(s21_strncmp_test_1) {
  char test_str[50][20] = {"Hello, World!", "Hello", "", "\0", "Hello\0World!"};
  s21_size_t num[50] = {0, 1, 2, 10, 20};
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      for (int k = 0; k < 5; k++) {
        int s21_c = s21_strncmp(test_str[i], test_str[j], num[k]);
        int s_c = strncmp(test_str[i], test_str[j], num[k]);
        if (s21_c > 0)
          s21_c = 1;
        else if (s21_c < 0)
          s21_c = -1;
        if (s_c > 0)
          s_c = 1;
        else if (s_c < 0)
          s_c = -1;
        ck_assert_int_eq(s21_c, s_c);
      }
}
END_TEST

START_TEST(s21_strncmp_test_2) {
  s21_size_t n = 3;
  char *str_1_1 = {"ABOBA!"};
  char *str_1_2 = {"ABOBA!"};
  int s21_c = s21_strncmp(str_1_1, str_1_2, n);
  int s_c = strncmp(str_1_1, str_1_2, n);
  if (s21_c > 0) ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(s21_strncpy_test_1) {
  char test_str[50][20] = {"Hello, World!", "Hello\0World!\0", "", "\0"};
  s21_size_t num[50] = {0, 1, 2, 10, 20};
  char str_s21[2048] = {""};
  char str_original[2048] = {""};
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 5; j++) {
      ck_assert_pstr_eq(s21_strncpy(str_s21, test_str[i], num[j]),
                        strncpy(str_original, test_str[i], num[j]));
      ck_assert_str_eq(str_s21, str_original);
    }
}
END_TEST

START_TEST(s21_strncpy_test_2) {
  s21_size_t n1 = 3;
  char b1[1024] = {"1111111111"};
  char b11[1024] = {"1111111111"};
  char str_1_2[1024] = {"123\0"};
  ck_assert_pstr_eq(strncpy(b1, str_1_2, n1), s21_strncpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(s21_strncpy_test_3) {
  s21_size_t n2 = 5;
  char b2[1024] = {"1111111111"};
  char b22[1024] = {"1111111111"};
  char str_2_2[1024] = {"12345\0006789"};
  ck_assert_pstr_eq(strncpy(b2, str_2_2, n2), s21_strncpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(s21_strncpy_test_4) {
  s21_size_t n3 = 5;
  char b3[1024] = {"11"};
  char b33[1024] = {"11"};
  char str_3_2[1024] = {"12345\0006789"};
  ck_assert_pstr_eq(strncpy(b3, str_3_2, n3), s21_strncpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(s21_strncpy_test_5) {
  s21_size_t n3 = 7;
  char b3[1024] = {"228"};
  char b33[1024] = {"228"};
  char str_3_2[1024] = {"12345\0006789"};
  ck_assert_pstr_eq(strncpy(b3, str_3_2, n3), s21_strncpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(s21_strcspn_test_1) {
  char test_str[50][20] = {"Hello, World!", "Hell", "q+=", "do", "", "\0",
                           "Hello\0World!"};
  for (int i = 0; i < 7; i++)
    for (int j = 0; j < 7; j++)
      ck_assert_int_eq(s21_strcspn(test_str[i], test_str[j]),
                       strcspn(test_str[i], test_str[j]));
}
END_TEST

START_TEST(s21_strcspn_test_2) {
  char str1[50] = {"this is a test"};
  ck_assert_int_eq(strcspn(str1, "ab"), s21_strcspn(str1, "ab"));
}
END_TEST

START_TEST(s21_strcspn_test_3) {
  char str2[50] = {"LOST: 4-8-15-16-23-42"};
  ck_assert_int_eq(strcspn(str2, "1234567890"),
                   s21_strcspn(str2, "1234567890"));
}
END_TEST

START_TEST(s21_strcspn_test_4) {
  char str3[50] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_int_eq(strcspn(str3, "zx"), s21_strcspn(str3, "zx"));
}
END_TEST

START_TEST(s21_strcspn_test_5) {
  char str3[50] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', '\0'};
  ck_assert_int_eq(strcspn(str3, "ZX"), s21_strcspn(str3, "ZX"));
}
END_TEST

START_TEST(s21_strerror_test_1) {
  char *str11 = s21_strerror(10);
  char *str21 = strerror(10);
  ck_assert_str_eq(str11, str21);

  char *str12 = s21_strerror(0);
  char *str22 = strerror(0);
  ck_assert_str_eq(str12, str22);

  char *str14 = s21_strerror(30);
  char *str24 = strerror(30);
  ck_assert_str_eq(str14, str24);

  char *str15 = s21_strerror(11);
  char *str25 = strerror(11);
  ck_assert_str_eq(str15, str25);
}
END_TEST

START_TEST(s21_strerror_test_2) {
  int err_num = 7;
  ck_assert_pstr_eq(strerror(err_num), s21_strerror(err_num));
}
END_TEST

START_TEST(s21_strerror_test_3) {
  int err_num2 = 1;
  ck_assert_pstr_eq(strerror(err_num2), s21_strerror(err_num2));
}
END_TEST

START_TEST(s21_strerror_test_4) {
  int err_num3 = 20;
  ck_assert_pstr_eq(strerror(err_num3), s21_strerror(err_num3));
}
END_TEST

START_TEST(s21_strerror_test_5) {
  int err_num4 = 0;
  ck_assert_pstr_eq(strerror(err_num4), s21_strerror(err_num4));
}
END_TEST

START_TEST(s21_strlen_test_1) {
  char test_str[50][20] = {"Hello, World!", "Hello\0World!\0", "", "\0"};
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(s21_strlen(test_str[i]), strlen(test_str[i]));
}
END_TEST

START_TEST(s21_strlen_test_2) {
  char src[50] = {""};
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_test_3) {
  char src[50] = {"christik"};
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_test_4) {
  char src[50] = {"987623456124678"};
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_test_5) {
  char src[100] = {
      "987623456124678qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"};
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_test_6) {
  char src[50] = {"mama\0ne_ponojet"};
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_test_7) {
  char src[50] = {"dai_mne_pen(321321)...123...123"};
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_test_8) {
  char src[50] = {"Spasibo_papasha"};
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_test_9) {
  char src[50] = {"Pelmeni_eto_vkusno"};
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_test_10) {
  char src[50] = {"floppa"};
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strpbrk_test_1) {
  char test_str[50][20] = {"Hello, World!", "Hell", "q+=", "do", "", "\0",
                           "Hello\0World!"};
  for (int i = 0; i < 7; i++)
    for (int j = 0; j < 7; j++)
      ck_assert_pstr_eq(s21_strpbrk(test_str[i], test_str[j]),
                        strpbrk(test_str[i], test_str[j]));
}
END_TEST

START_TEST(s21_strpbrk_test_2) {
  char str1[50] = {""};
  char str2[50] = {""};
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_3) {
  char str1[50] = {"floppa"};
  char str2[50] = {""};
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_4) {
  char str1[50] = {""};
  char str2[50] = {"floppa"};
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_5) {
  char str1[50] = {"poki doki"};
  char str2[50] = {"o"};
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_6) {
  char str1[50] = {"poki doki"};
  char str2[50] = {"i"};
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_7) {
  char str1[50] = {"poki doki"};
  char str2[50] = {"p"};
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_8) {
  char str1[50] = {"ppppppppppppP"};
  char str2[50] = {"P"};
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_9) {
  char str1[50] = {"ppppppppppppP"};
  char str2[50] = {"\0"};
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strrchr_test_1) {
  char test_str[50][20] = {"Hello, World!", "Hello\0World!\0", "", "\0"};
  int test_char[50] = {'l', '!', '/', '\0', 'q'};
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 5; j++)
      ck_assert_pstr_eq(s21_strrchr(test_str[i], test_char[j]),
                        strrchr(test_str[i], test_char[j]));
}
END_TEST

START_TEST(s21_strrchr_test_2) {
  char str[50] = {"0163456769"};
  ck_assert_pstr_eq(strrchr(str, '6'), s21_strrchr(str, '6'));
}
END_TEST

START_TEST(s21_strrchr_test_3) {
  char str2[50] = {"mcgalinka@gmail.com"};
  ck_assert_pstr_eq(strrchr(str2, 'o'), s21_strrchr(str2, 'o'));
}
END_TEST

START_TEST(s21_strrchr_test_4) {
  char str3[50] = {"mcgalinka@gmail.com"};
  ck_assert_pstr_eq(strrchr(str3, 'h'), s21_strrchr(str3, 'h'));
}
END_TEST

START_TEST(s21_strrchr_test_5) {
  char str4[50] = {""};
  ck_assert_pstr_eq(strrchr(str4, 'd'), s21_strrchr(str4, 'd'));
}
END_TEST

START_TEST(s21_strrchr_test_6) {
  char str5[50] = {""};
  ck_assert_pstr_eq(strrchr(str5, 'z'), s21_strrchr(str5, 'z'));
}
END_TEST

START_TEST(s21_strstr_test_1) {
  char test_str[50][20] = {"Hello, World!", "Hell", "q+=", "d!", "", "\0",
                           "Hello\0World!"};
  for (int i = 0; i < 7; i++)
    for (int j = 0; j < 7; j++)
      ck_assert_pstr_eq(s21_strstr(test_str[i], test_str[j]),
                        strstr(test_str[i], test_str[j]));
}
END_TEST

START_TEST(s21_strstr_test_2) {
  char str[50] = {""};
  ck_assert_pstr_eq(strstr(str, ""), s21_strstr(str, ""));
}
END_TEST

START_TEST(s21_strstr_test_3) {
  char str2[50] = {"john.smith@mic\0rosoft.com"};
  ck_assert_pstr_eq(strstr(str2, "sm"), s21_strstr(str2, "sm"));
}
END_TEST

START_TEST(s21_strstr_test_4) {
  char str3[50] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_pstr_eq(strstr(str3, "woo"), s21_strstr(str3, "woo"));
}
END_TEST

START_TEST(s21_strtok_test_1) {
  char input_s21_strtok_str[50] = {"Тут была christik - абоба."};
  char input_original_strtok_str[50] = {"Тут была christik - абоба."};
  char delim[50] = {",.-"};
  char *out_s21_strtok_pch = s21_strtok(input_s21_strtok_str, delim);
  char *out_original_strtok_pch = strtok(input_original_strtok_str, delim);
  while ((out_s21_strtok_pch != NULL) || (out_original_strtok_pch != NULL)) {
    ck_assert_pstr_eq(out_s21_strtok_pch, out_original_strtok_pch);
    out_original_strtok_pch = strtok(NULL, delim);
    out_s21_strtok_pch = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_null(out_s21_strtok_pch);
  ck_assert_ptr_null(out_original_strtok_pch);
}
END_TEST

START_TEST(s21_strtok_test_2) {
  char input_s21_strtok_str[50] = {"Тут была christik - абоба."};
  char input_original_strtok_str[50] = {"Тут была christik - абоба."};
  char delim[50] = {"%_+="};
  char *out_s21_strtok_pch = s21_strtok(input_s21_strtok_str, delim);
  char *out_original_strtok_pch = strtok(input_original_strtok_str, delim);
  while ((out_s21_strtok_pch != NULL) || (out_original_strtok_pch != NULL)) {
    ck_assert_pstr_eq(out_s21_strtok_pch, out_original_strtok_pch);
    out_original_strtok_pch = strtok(NULL, delim);
    out_s21_strtok_pch = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_null(out_s21_strtok_pch);
  ck_assert_ptr_null(out_original_strtok_pch);
}
END_TEST

START_TEST(s21_strtok_test_3) {
  char input_s21_strtok_str[50] = {"$$$$$$$$$$"};
  char input_original_strtok_str[50] = {"$$$$$$$$$$"};
  char delim[50] = {"$"};
  char *out_s21_strtok_pch = s21_strtok(input_s21_strtok_str, delim);
  char *out_original_strtok_pch = strtok(input_original_strtok_str, delim);
  while ((out_s21_strtok_pch != NULL) || (out_original_strtok_pch != NULL)) {
  }
  ck_assert_ptr_null(out_s21_strtok_pch);
  ck_assert_ptr_null(out_original_strtok_pch);
}
END_TEST

START_TEST(s21_strtok_test_4) {
  char input_s21_strtok_str[50] = {""};
  char input_original_strtok_str[50] = {""};
  char delim[50] = {"%_+="};
  char *out_s21_strtok_pch = s21_strtok(input_s21_strtok_str, delim);
  char *out_original_strtok_pch = strtok(input_original_strtok_str, delim);
  while ((out_s21_strtok_pch != NULL) || (out_original_strtok_pch != NULL)) {
  }
  ck_assert_ptr_null(out_s21_strtok_pch);
  ck_assert_ptr_null(out_original_strtok_pch);
}
END_TEST

START_TEST(s21_strtok_test_5) {
  char input_s21_strtok_str[50] = {"Тут была christik\0 - абоба."};
  char input_original_strtok_str[50] = {"Тут была christik\0 - абоба."};
  char delim[50] = {",.-"};
  char *out_s21_strtok_pch = s21_strtok(input_s21_strtok_str, delim);
  char *out_original_strtok_pch = strtok(input_original_strtok_str, delim);
  while ((out_s21_strtok_pch != NULL) || (out_original_strtok_pch != NULL)) {
    ck_assert_pstr_eq(out_s21_strtok_pch, out_original_strtok_pch);
    out_original_strtok_pch = strtok(NULL, delim);
    out_s21_strtok_pch = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_null(out_s21_strtok_pch);
  ck_assert_ptr_null(out_original_strtok_pch);
}
END_TEST

START_TEST(s21_strtok_test_6) {
  char input_s21_strtok_str[50] = {"Тут была christik\\абоба\\абобус."};
  char input_original_strtok_str[50] = {"Тут была christik\\абоба\\абобус."};
  char delim[50] = {"\\"};
  char *out_s21_strtok_pch = s21_strtok(input_s21_strtok_str, delim);
  char *out_original_strtok_pch = strtok(input_original_strtok_str, delim);
  while ((out_s21_strtok_pch != NULL) || (out_original_strtok_pch != NULL)) {
    ck_assert_pstr_eq(out_s21_strtok_pch, out_original_strtok_pch);
    out_original_strtok_pch = strtok(NULL, delim);
    out_s21_strtok_pch = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_null(out_s21_strtok_pch);
  ck_assert_ptr_null(out_original_strtok_pch);
}
END_TEST

START_TEST(s21_strtok_test_7) {
  char input_s21_strtok_str[50] = {"Тут была christik - абоба."};
  char input_original_strtok_str[50] = {"Тут была christik - абоба."};
  char delim[50] = {""};
  char *out_s21_strtok_pch = s21_strtok(input_s21_strtok_str, delim);
  char *out_original_strtok_pch = strtok(input_original_strtok_str, delim);
  while ((out_s21_strtok_pch != NULL) || (out_original_strtok_pch != NULL)) {
    ck_assert_pstr_eq(out_s21_strtok_pch, out_original_strtok_pch);
    out_original_strtok_pch = strtok(NULL, delim);
    out_s21_strtok_pch = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_null(out_s21_strtok_pch);
  ck_assert_ptr_null(out_original_strtok_pch);
}
END_TEST

START_TEST(s21_strtok_test_8) {
  char str4_1[50] = {"/testing/with/original/string.h/"};
  char str4_2[50] = {"/testing/with/original/string.h/"};
  char del4[3] = {"/"};
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

START_TEST(s21_strtok_test_9) {
  char str4_1[50] = {". . testing with original string.h"};
  char str4_2[50] = {". . testing with original string.h"};
  char del4[3] = {". "};
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

START_TEST(s21_strtok_test_10) {
  char str4_1[50] = {"testing with original string.h"};
  char str4_2[50] = {"testing with original string.h"};
  char del4[3] = {". "};
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

START_TEST(s21_to_upper_test_1) {
  char test_str[100] = {
      "Hello, World! ABCabc..XYZxyz 0123456789 ±!@#$%^&*()_+-=*/"};
  char out_expected[100] = {
      "HELLO, WORLD! ABCABC..XYZXYZ 0123456789 ±!@#$%^&*()_+-=*/"};
  char *out_s21 = s21_to_upper(test_str);
  ck_assert_str_eq(out_s21, out_expected);
  free(out_s21);
}
END_TEST

START_TEST(s21_to_upper_test_2) {
  char test_str[50] = {""};
  char out_expected[50] = {""};
  char *out_s21 = s21_to_upper(test_str);
  ck_assert_str_eq(out_s21, out_expected);
  free(out_s21);
}
END_TEST

START_TEST(s21_to_lower_test_1) {
  char test_str[70] = {
      "Hello, World! ABCabc..XYZxyz 0123456789 ±!@#$%^&*()_+-=*/"};
  char out_expected[70] = {
      "hello, world! abcabc..xyzxyz 0123456789 ±!@#$%^&*()_+-=*/"};
  char *out_s21 = s21_to_lower(test_str);
  ck_assert_str_eq(out_s21, out_expected);
  free(out_s21);
}
END_TEST

START_TEST(s21_to_lower_test_2) {
  char test_str[50] = {""};
  char out_expected[50] = {""};
  char *out_s21 = s21_to_lower(test_str);
  ck_assert_str_eq(out_s21, out_expected);
  free(out_s21);
}
END_TEST

START_TEST(s21_insert_test_1) {
  char test_str[50] = {"Hello, World!"};
  char ins[50] = {"_hop-hey lalaley_"};
  s21_size_t index = 0;
  char out_expected[50] = {"_hop-hey lalaley_Hello, World!"};
  char *out_s21 = (char *)s21_insert(test_str, ins, index);
  ck_assert_str_eq(out_s21, out_expected);
  if (out_s21) free(out_s21);
}
END_TEST

START_TEST(s21_insert_test_2) {
  char test_str[50] = {"Hello, World!"};
  char ins[50] = {"_hop-hey lalaley_"};
  s21_size_t index = 6;
  char out_expected[50] = {"Hello,_hop-hey lalaley_ World!"};
  char *out_s21 = (char *)s21_insert(test_str, ins, index);
  ck_assert_str_eq(out_s21, out_expected);
  if (out_s21) free(out_s21);
}
END_TEST

START_TEST(s21_insert_test_3) {
  char test_str[50] = {"Hello, World!"};
  char ins[50] = {"_hop-hey lalaley_"};
  s21_size_t index = 50;
  char *out_expected = s21_NULL;
  char *out_s21 = (char *)s21_insert(test_str, ins, index);
  ck_assert_pstr_eq(out_s21, out_expected);
  if (out_s21) free(out_s21);
}
END_TEST

START_TEST(s21_insert_test_5) {
  char *test_str = s21_NULL;
  char *ins = s21_NULL;
  s21_size_t index = 10;
  char *out_expected = s21_NULL;
  char *out_s21 = (char *)s21_insert(test_str, ins, index);
  ck_assert_pstr_eq(out_s21, out_expected);
  if (out_s21) free(out_s21);
}
END_TEST

START_TEST(s21_trim_test_1) {
  char test_str[50] = {""};
  char trims[50] = {""};
  char out_expected[50] = {""};
  char *out_s21 = s21_trim(test_str, trims);
  ck_assert_pstr_eq(out_s21, out_expected);
  if (out_s21) free(out_s21);
}
END_TEST

START_TEST(s21_trim_test_2) {
  char test_str[50] = {""};
  char trims[50] = {"@#$<fuck up>$%^"};
  char out_expected[50] = {""};
  char *out_s21 = s21_trim(test_str, trims);
  ck_assert_pstr_eq(out_s21, out_expected);
  if (out_s21) free(out_s21);
}
END_TEST

START_TEST(s21_trim_test_3) {
  char str_trim[] = "\n  ! Hello World ! ,, \n\0";
  char test1[] = "\n !\0";
  char test2[] = "\n !,Hd\0";
  char test3[] = "\n o\0";
  char *str = s21_trim(str_trim, test1);
  if (str) {
    ck_assert_str_eq(str, "Hello World ! ,,\0");
    free(str);
  }
  str = s21_trim(str_trim, test2);
  if (str) {
    ck_assert_str_eq(str, "ello Worl\0");
    free(str);
  }
  str = s21_trim(str_trim, test3);
  if (str) {
    ck_assert_str_eq(str, "! Hello World ! ,,\0");
    free(str);
  }
}
END_TEST

START_TEST(s21_sprintf_test1) {
  char str1[100];
  char str2[100];
  int r1 = sprintf(str1, "%d%s%c%f%u%%%s", 25, "aboba", 'a', 4325.23434, 12345u,
                   "hello my friend");
  int r2 = s21_sprintf(str2, "%d%s%c%f%u%%%s", 25, "aboba", 'a', 4325.23434,
                       12345u, "hello my friend");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test2) {
  char str1[100];
  char str2[100];
  int r1 = sprintf(str1, "%+-25.3d%25.15d%10.f%15d", 252, 243, 256.34, 15);
  int r2 = s21_sprintf(str2, "%+-25.3d%25.15d%10.f%15d", 252, 243, 256.34, 15);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test3) {
  char str1[100];
  char str2[100];
  int r1 = sprintf(str1, "%+34.9f%.10d%15.1u%25.10s", 25.3456, 1234, 4567,
                   "HELLOMYDEARFRIEND");
  int r2 = s21_sprintf(str2, "%+34.9f%.10d%15.1u%25.10s", 25.3456, 1234, 4567,
                       "HELLOMYDEARFRIEND");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test4) {
  char str1[100];
  char str2[100];
  int r1 =
      sprintf(str1, "%24.f%-15.20d%20u", 43253242.4342, 4567899, 43252342u);
  int r2 =
      s21_sprintf(str2, "%24.f%-15.20d%20u", 43253242.4342, 4567899, 43252342u);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
  char str3[50];
  char str4[100];
  int r3 = sprintf(str3, "%.0f", 25432.34345);
  int r4 = s21_sprintf(str4, "%.0f", 25432.34345);
  ck_assert_str_eq(str3, str4);
  ck_assert_int_eq(r3, r4);
}
END_TEST

START_TEST(s21_sprintf_test_d) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(str1, "%-25.10d%-30.2d%10.12d%11d%d%.d%+-25.d%+10.2d%-11.hd",
                   253, 335, 1234, 34, 10, 25, 5, 15, 345);
  int r2 =
      s21_sprintf(str2, "%-25.10d%-30.2d%10.12d%11d%d%.d%+-25.d%+10.2d%-11.hd",
                  253, 335, 1234, 34, 10, 25, 5, 15, 345);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_f) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(
      str1, "%+-10.5f%+10.2f%15.9f%+.10f%.9f%-10f%25f%25.f%+10.f%f", 2546.4324,
      3452.4325, 5678.43256, 456789.243242, 456789123.43245, 12345.6788,
      34.4325432, 4325678.43242, 34567.2345432, 34567.43244);
  int r2 = s21_sprintf(
      str2, "%+-10.5f%+10.2f%15.9f%+.10f%.9f%-10f%25f%25.f%+10.f%f", 2546.4324,
      3452.4325, 5678.43256, 456789.243242, 456789123.43245, 12345.6788,
      34.4325432, 4325678.43242, 34567.2345432, 34567.43244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_u) {
  char str1[1000];
  char str2[1000];
  unsigned short h = 115;
  unsigned long l = 123325242342l;
  int r1 =
      sprintf(str1, "%u%15u%-20u%10u%-15.10u%20u%u%.10u%-20.12lu%19hu", 4321u,
              34567u, 2342u, 12346u, 234542u, 234523u, 2345u, 2432u, l, h);
  int r2 = s21_sprintf(str2, "%u%15u%-20u%10u%-15.10u%20u%u%.10u%-20.12lu%19hu",
                       4321u, 34567u, 2342u, 12346u, 234542u, 234523u, 2345u,
                       2432u, l, h);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_s) {
  char str1[1000];
  char str2[1000];
  wchar_t s[10] = {'h', 'e', 'l', 'l', 'o'};
  // wchar_t s[10] = {'п', 'р', 'и', 'в', 'е', 'т'};
  int r1 = sprintf(str1, "%s%23s%-15s%10.s%15.2s%16s%s%s%15ls%15.3ls", "aboba",
                   "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", "QWERTY",
                   "AAAAABOOOOOBAAA", "ABOBAAAAA", s, s);
  int r2 = s21_sprintf(str2, "%s%23s%-15s%10.s%15.2s%16s%s%s%15ls%15.3ls",
                       "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA",
                       "QWERTY", "AAAAABOOOOOBAAA", "ABOBAAAAA", s, s);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_percent) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(str1, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
  int r2 = s21_sprintf(str2, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

Suite *test_suite_s21_sprintf() {
  Suite *s = suite_create("test_suite_s21_sprintf");
  TCase *tc = tcase_create("test_case_s21_sprintf");

  tcase_add_test(tc, s21_sprintf_test1);
  tcase_add_test(tc, s21_sprintf_test2);
  tcase_add_test(tc, s21_sprintf_test3);
  tcase_add_test(tc, s21_sprintf_test4);
  tcase_add_test(tc, s21_sprintf_test_d);
  tcase_add_test(tc, s21_sprintf_test_f);
  tcase_add_test(tc, s21_sprintf_test_u);
  tcase_add_test(tc, s21_sprintf_test_s);
  tcase_add_test(tc, s21_sprintf_test_percent);

  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_memchr() {
  Suite *s = suite_create("test_suite_s21_memchr");
  TCase *tc = tcase_create("test_case_s21_memchr");
  tcase_add_test(tc, s21_memchr_test_1);
  tcase_add_test(tc, s21_memchr_test_2);
  tcase_add_test(tc, s21_memchr_test_3);
  tcase_add_test(tc, s21_memchr_test_5);
  tcase_add_test(tc, s21_memchr_test_6);
  tcase_add_test(tc, s21_memchr_test_7);
  tcase_add_test(tc, s21_memchr_test_8);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_memcmp() {
  Suite *s = suite_create("test_suite_s21_memcmp");
  TCase *tc = tcase_create("test_case_s21_memcmp");
  tcase_add_test(tc, s21_memcmp_test_1);
  tcase_add_test(tc, s21_memcmp_test_2);
  tcase_add_test(tc, s21_memcmp_test_3);
  tcase_add_test(tc, s21_memcmp_test_4);
  tcase_add_test(tc, s21_memcmp_test_5);
  tcase_add_test(tc, s21_memcmp_test_6);
  tcase_add_test(tc, s21_memcmp_test_7);
  tcase_add_test(tc, s21_memcmp_test_8);
  tcase_add_test(tc, s21_memcmp_test_10);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_memcpy() {
  Suite *s = suite_create("test_suite_s21_memcpy");
  TCase *tc = tcase_create("test_case_s21_memcpy");
  tcase_add_test(tc, s21_memcpy_test_1);
  tcase_add_test(tc, s21_memcpy_test_2);
  tcase_add_test(tc, s21_memcpy_test_3);
  tcase_add_test(tc, s21_memcpy_test_4);
  tcase_add_test(tc, s21_memcpy_test_5);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_memset() {
  Suite *s = suite_create("test_suite_s21_memset");
  TCase *tc = tcase_create("test_case_s21_memset");
  tcase_add_test(tc, s21_memset_test_1);
  tcase_add_test(tc, s21_memset_test_2);
  tcase_add_test(tc, s21_memset_test_3);
  tcase_add_test(tc, s21_memset_test_4);
  tcase_add_test(tc, s21_memset_test_5);
  tcase_add_test(tc, s21_memset_test_6);
  tcase_add_test(tc, s21_memset_test_7);
  tcase_add_test(tc, s21_memset_test_8);
  tcase_add_test(tc, s21_memset_test_9);
  tcase_add_test(tc, s21_memset_test_10);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_strncat() {
  Suite *s = suite_create("test_suite_s21_strncat");
  TCase *tc = tcase_create("test_case_s21_strncat");
  tcase_add_test(tc, s21_strncat_test_1);
  tcase_add_test(tc, s21_strncat_test_2);
  tcase_add_test(tc, s21_strncat_test_3);
  tcase_add_test(tc, s21_strncat_1);
  tcase_add_test(tc, s21_strncat_2);
  tcase_add_test(tc, s21_strncat_3);
  tcase_add_test(tc, s21_strncat_4);
  tcase_add_test(tc, strncat_zero_char);
  tcase_add_test(tc, strncat_BIGFLOPPA4);
  tcase_add_test(tc, strncat_BIGFLOPPA3);
  tcase_add_test(tc, strncat_BIGFLOPPA2);
  tcase_add_test(tc, strncat_BIGFLOPPA);

  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_strchr() {
  Suite *s = suite_create("test_suite_s21_strchr");
  TCase *tc = tcase_create("test_case_s21_strchr");
  tcase_add_test(tc, s21_strchr_test_1);
  tcase_add_test(tc, s21_strchr_test_2);
  tcase_add_test(tc, s21_strchr_test_3);
  tcase_add_test(tc, s21_strchr_test_4);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_strncmp() {
  Suite *s = suite_create("test_suite_s21_strncmp");
  TCase *tc = tcase_create("test_case_s21_strncmp");
  tcase_add_test(tc, s21_strncmp_test_1);
  tcase_add_test(tc, s21_strncmp_test_2);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_strncpy() {
  Suite *s = suite_create("test_suite_s21_strncpy");
  TCase *tc = tcase_create("test_case_s21_strncpy");
  tcase_add_test(tc, s21_strncpy_test_1);
  tcase_add_test(tc, s21_strncpy_test_2);
  tcase_add_test(tc, s21_strncpy_test_3);
  tcase_add_test(tc, s21_strncpy_test_4);
  tcase_add_test(tc, s21_strncpy_test_5);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_strcspn() {
  Suite *s = suite_create("test_suite_s21_strcspn");
  TCase *tc = tcase_create("test_case_s21_strcspn");
  tcase_add_test(tc, s21_strcspn_test_1);
  tcase_add_test(tc, s21_strcspn_test_2);
  tcase_add_test(tc, s21_strcspn_test_3);
  tcase_add_test(tc, s21_strcspn_test_4);
  tcase_add_test(tc, s21_strcspn_test_5);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_strerror() {
  Suite *s = suite_create("test_suite_s21_strerror");
  TCase *tc = tcase_create("test_case_s21_strerror");
  tcase_add_test(tc, s21_strerror_test_1);
  tcase_add_test(tc, s21_strerror_test_2);
  tcase_add_test(tc, s21_strerror_test_3);
  tcase_add_test(tc, s21_strerror_test_4);
  tcase_add_test(tc, s21_strerror_test_5);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_strlen() {
  Suite *s = suite_create("test_suite_s21_strlen");
  TCase *tc = tcase_create("test_case_s21_strlen");
  tcase_add_test(tc, s21_strlen_test_1);
  tcase_add_test(tc, s21_strlen_test_2);
  tcase_add_test(tc, s21_strlen_test_3);
  tcase_add_test(tc, s21_strlen_test_4);
  tcase_add_test(tc, s21_strlen_test_5);
  tcase_add_test(tc, s21_strlen_test_6);
  tcase_add_test(tc, s21_strlen_test_7);
  tcase_add_test(tc, s21_strlen_test_8);
  tcase_add_test(tc, s21_strlen_test_9);
  tcase_add_test(tc, s21_strlen_test_10);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_strpbrk() {
  Suite *s = suite_create("test_suite_s21_strpbrk");
  TCase *tc = tcase_create("test_case_s21_strpbrk");
  tcase_add_test(tc, s21_strpbrk_test_1);
  tcase_add_test(tc, s21_strpbrk_test_2);
  tcase_add_test(tc, s21_strpbrk_test_3);
  tcase_add_test(tc, s21_strpbrk_test_4);
  tcase_add_test(tc, s21_strpbrk_test_5);
  tcase_add_test(tc, s21_strpbrk_test_6);
  tcase_add_test(tc, s21_strpbrk_test_7);
  tcase_add_test(tc, s21_strpbrk_test_8);
  tcase_add_test(tc, s21_strpbrk_test_9);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_strrchr() {
  Suite *s = suite_create("test_suite_s21_strrchr");
  TCase *tc = tcase_create("test_case_s21_strrchr");
  tcase_add_test(tc, s21_strrchr_test_1);
  tcase_add_test(tc, s21_strrchr_test_2);
  tcase_add_test(tc, s21_strrchr_test_3);
  tcase_add_test(tc, s21_strrchr_test_4);
  tcase_add_test(tc, s21_strrchr_test_5);
  tcase_add_test(tc, s21_strrchr_test_6);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_strstr() {
  Suite *s = suite_create("test_suite_s21_strstr");
  TCase *tc = tcase_create("test_case_s21_strstr");
  tcase_add_test(tc, s21_strstr_test_1);
  tcase_add_test(tc, s21_strstr_test_2);
  tcase_add_test(tc, s21_strstr_test_3);
  tcase_add_test(tc, s21_strstr_test_4);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_strtok() {
  Suite *s = suite_create("test_suite_s21_strtok");
  TCase *tc = tcase_create("test_suite_s21_strtok");
  tcase_add_test(tc, s21_strtok_test_1);
  tcase_add_test(tc, s21_strtok_test_2);
  tcase_add_test(tc, s21_strtok_test_3);
  tcase_add_test(tc, s21_strtok_test_4);
  tcase_add_test(tc, s21_strtok_test_5);
  tcase_add_test(tc, s21_strtok_test_6);
  tcase_add_test(tc, s21_strtok_test_7);
  tcase_add_test(tc, s21_strtok_test_8);
  tcase_add_test(tc, s21_strtok_test_9);
  tcase_add_test(tc, s21_strtok_test_10);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_to_upper() {
  Suite *s = suite_create("test_suite_s21_to_upper");
  TCase *tc = tcase_create("test_case_s21_to_upper");
  tcase_add_test(tc, s21_to_upper_test_1);
  tcase_add_test(tc, s21_to_upper_test_2);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_to_lower() {
  Suite *s = suite_create("test_suite_s21_to_lower");
  TCase *tc = tcase_create("test_case_s21_to_lower");
  tcase_add_test(tc, s21_to_lower_test_1);
  tcase_add_test(tc, s21_to_lower_test_2);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_insert() {
  Suite *s = suite_create("test_suite_s21_insert");
  TCase *tc = tcase_create("test_case_s21_insert");
  tcase_add_test(tc, s21_insert_test_1);
  tcase_add_test(tc, s21_insert_test_2);
  tcase_add_test(tc, s21_insert_test_3);
  tcase_add_test(tc, s21_insert_test_5);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_suite_s21_trim() {
  Suite *s = suite_create("test_suite_s21_trim");
  TCase *tc = tcase_create("test_case_s21_trim");
  tcase_add_test(tc, s21_trim_test_1);
  tcase_add_test(tc, s21_trim_test_2);
  tcase_add_test(tc, s21_trim_test_3);
  suite_add_tcase(s, tc);
  return s;
}

int main() {
  int no_failed = 0;
  Suite *test_suites[50] = {test_suite_s21_memchr(),
                            test_suite_s21_memcmp(),
                            test_suite_s21_memcpy(),
                            test_suite_s21_memset(),
                            test_suite_s21_strncat(),
                            test_suite_s21_strchr(),
                            test_suite_s21_strncmp(),
                            test_suite_s21_strncpy(),
                            test_suite_s21_strcspn(),
                            test_suite_s21_strerror(),
                            test_suite_s21_strlen(),
                            test_suite_s21_strpbrk(),
                            test_suite_s21_strrchr(),
                            test_suite_s21_strstr(),
                            test_suite_s21_strtok(),
                            test_suite_s21_to_upper(),
                            test_suite_s21_to_lower(),
                            test_suite_s21_insert(),
                            test_suite_s21_trim(),
                            test_suite_s21_sprintf(),

                            NULL};
  for (Suite **suite = test_suites; *suite != NULL; suite++) {
    SRunner *runner = srunner_create(*suite);
    srunner_run_all(runner, CK_NORMAL);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }
  return no_failed;
}
