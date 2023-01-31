#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
	char *answer = (char *)s21_NULL;
	for(;*haystack;(haystack++)) {
		if(s21_strncmp((char*)haystack, needle, s21_strlen(needle)) == 0) {
			answer = (char *)haystack;
			break;
		}
	}
	return answer;
}