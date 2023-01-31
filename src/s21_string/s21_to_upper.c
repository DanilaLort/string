#include "../s21_string.h"

void *s21_to_upper(const char *str) {
	void *answer = s21_convertor(str, isalpha, islower, toupper);
	return answer;
}