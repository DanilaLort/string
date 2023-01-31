#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
	char *answer = (char *)s21_NULL;
	for (; *str; (str++)) {
		if (*str == c) {
			answer = (char *)str;
		}
	}
	return answer;
}
