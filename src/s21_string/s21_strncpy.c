#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
	char *answer = (char *)s21_NULL;
	char *temp = (char *)s21_NULL;
	if (dest != (char *)s21_NULL) {
		temp = (char *)malloc(s21_strlen((char *)src) + 1);
		if (temp) {
			s21_size_t i = 0;
			for (; i < s21_strlen((char *)src); i++)
				temp[i] = src[i];
			temp[i] = '\0';
			answer = dest;
			i = 0;
			for(; i < s21_strlen(src) && i < n; i++) {
				dest[i] = temp[i];
			}
			for(; i < s21_strlen(dest); i++);
			dest[i] = '\0';
			free(temp);
		}
	}
	return answer;
}