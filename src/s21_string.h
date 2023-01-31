#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define s21_size_t unsigned long long
#define s21_NULL (void*)0
#define S21_NULL (void*)0

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n); //1
char *s21_strcat(char *dest, const char *src); //1
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c); //1
int s21_strcmp(const char *str1, const char *str2); //1
int s21_strncmp(const char *str1, const char *str2, s21_size_t n); //1
char *s21_strcpy(char *dest, const char *src); //1
char *s21_strncpy(char *dest, const char *src, s21_size_t n); //1
s21_size_t s21_strcspn(const char *str1, const char *str2); //1
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str); //1
char *s21_strpbrk(const char *str1, const char *str2); //1
char *s21_strrchr(const char *str, int c); //1
s21_size_t s21_strspn(const char *str1, const char *str2); //1
char *s21_strstr(const char *haystack, const char *needle); //1
char *s21_strtok(char *str, const char *delim);

void *s21_convertor(const char *str, int funccmp1 (int), int funccmp2 (int), int decision (int));
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_strcpy_by_index(const char *src, s21_size_t index_start, s21_size_t index_end);
void s21_find_index_end(const char *src, const char *trim_chars, s21_size_t *pointer_end);
void s21_find_index_start(const char *src, const char *trim_chars, s21_size_t *pointer_start);

#endif  // SRC_S21_STRING_H_
