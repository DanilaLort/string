#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
	static char* pointer;
	char *answer = (char *)s21_NULL;
	if (!str) {
		str = pointer;
	}

	if (str) {
		answer = str;

		s21_size_t i = 0;
		s21_size_t j = 0;
		int flag = -1;
		for(str, j; *str && answer && str; str++, j++) {
			for(i = 0; i < s21_strlen(delim); i++) {
				if(*str == delim[i]) {
					*str = '\0';
					str++;
					pointer = str;
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		if(*str == '\0')
			pointer = (char *)s21_NULL;
		if(flag == 1 && j == 0)
			answer = (char *)s21_NULL;
	}
	return answer;
}