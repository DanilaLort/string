#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
	char *answer = (char *)s21_NULL;
	if(dest != (char *)s21_NULL) {
		answer = dest;
		s21_size_t i = 0;
		s21_size_t ldest = s21_strlen(dest);
		for(; i < s21_strlen(src) && i < n; i++) {
			dest[i + ldest] = src[i];
		}
		dest[i + ldest] = '\0';
	}
	return answer;
}