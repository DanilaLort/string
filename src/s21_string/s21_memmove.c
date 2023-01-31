#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
	void *answer = s21_NULL;
	char *temp = (char *)s21_NULL;
	if (dest != s21_NULL) {
		temp = (char *)malloc(s21_strlen((char *)src) + 1);
		if (temp) {
			s21_size_t i = 0;
			for (i; i < s21_strlen((char *)src); i++)
				temp[i] = ((char *)src)[i];
			temp[i] = '\0';
			answer = dest;
			i = 0;
			for(i; i < s21_strlen(src) && i < n; i++) {
				((char *)dest)[i] = temp[i];
			}
			for(i; i < s21_strlen((char *)dest); i++);
			((char *)dest)[i] = '\0';
			free(temp);
		}
	}
	return answer;
}