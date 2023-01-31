#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
	char *answer = (char *)s21_NULL;
	//if (str2 != (char *)s21_NULL && str1 != (char *)s21_NULL) {
	for (; *str1; (str1++)) {
		for (s21_size_t i = 0; i < s21_strlen(str2); i++) {
			if (*str1 == *(str2 + i) && answer == (char *)s21_NULL) {
				answer = (char *)str1;
			}
		}
	}
	//}
	return answer;
}