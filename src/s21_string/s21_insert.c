#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
	char *answer = (char *)s21_NULL;
	if (src && str && s21_strlen(src) >= start_index) {
		s21_size_t lanswer = start_index + s21_strlen(str);
		if(lanswer < s21_strlen(src))
			lanswer = s21_strlen(src);
		answer = (char *)malloc(lanswer + 1);
		if (answer) {
			s21_size_t i = 0;
			for(i = 0; i < start_index; i++) {
				answer[i] = src[i];
			}
			for(i = 0; i < s21_strlen(str); i++) {
				answer[i + start_index] = str[i];
			}
			for(i = start_index + s21_strlen(str); i < s21_strlen(src); i++) {
				answer[i] = src[i];	
			}
			answer[lanswer] = '\0';
		}
	}
	return (void *)answer;
}