#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
	s21_size_t answer = 0;
	for (; *str; (str++)) {
		answer += 1;
	}
	return answer;
}