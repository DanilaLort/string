#include "s21_string.h"

void *s21_to_lower(const char *str) {
	void *answer = s21_convertor(str, isalpha, isupper, tolower);
	return answer;
}

