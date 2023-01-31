#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
	s21_size_t i = 0;
	s21_size_t str1len = s21_strlen((char *)str1);
	s21_size_t str2len = s21_strlen((char *)str2);
	for(; (int)*(char *)str1 - (int)*(char *)str2 == 0 && i < n && i < str1len && i < str2len; ((char *)str1++), ((char *)str2++), i++);
	return *(char *)str1 - *(char *)str2;
}