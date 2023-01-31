#include "s21_string.h"

void *s21_convertor(const char *str, int funccmp1 (int), int funccmp2 (int), int decision (int)) {
	char *answer = (char *)s21_NULL;
	if (str) {
		answer = (char *)malloc(s21_strlen(str) + 1);
		if (answer) {
			s21_size_t i = 0;
			for(; *str; str++, i++)
				answer[i] = funccmp1(*str) && funccmp2(*str) ? decision(*str) : *str;
			answer[i] = '\0';
		}
	}
	return (void *)answer;
}