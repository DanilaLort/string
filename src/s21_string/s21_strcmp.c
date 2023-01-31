#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
	s21_size_t i = 0;
	s21_size_t str1len = s21_strlen(str1);
	s21_size_t str2len = s21_strlen(str2);
	for(i = 0; (int)*str1 - (int)*str2 == 0 && i < str1len && i < str2len; (str1++), (str2++), i++);
	return *str1 - *str2;
}