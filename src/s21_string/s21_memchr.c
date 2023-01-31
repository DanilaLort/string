#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
	void *answer = s21_NULL;
	s21_size_t lstr = s21_strlen((char *)str);
	for (int i = 0; i < (int)lstr && i < (int)n; i++) {
		if (((char *)str)[i] == c && answer == s21_NULL) {
			answer = (void *)&((char *)str)[i];
		}
	}
	return answer;
}
