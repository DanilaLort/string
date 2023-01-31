#include "../s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
	s21_size_t answer = 0;
	s21_size_t temp1 = 0;
	s21_size_t temp2 = 0;
	int lenstr = s21_strlen(str2);
	for (; *str1; (str1++)) {
		temp1 = 0;
		for (int i = 0; i < lenstr; i++) {
			if (*str1 == *(str2 + i)) {
				temp1 = 1;
				break;
			}
		}
		
		if (temp1 == 1) {
			temp2 += 1;
		} else {
			if (temp2 > answer) {
				answer = temp2;
			}
			temp2 = 0;
		} 			
	}
	return answer;
}