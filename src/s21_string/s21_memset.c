#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
	void *answer = s21_NULL;
	if (str != s21_NULL) {
		answer = str;
		s21_size_t i;
		for(i = 0; i < s21_strlen((char *)str) && i < n; i++) 
			((char *)str)[i] = c;
	}
	return answer;
}