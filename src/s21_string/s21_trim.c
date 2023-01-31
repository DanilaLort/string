#include "s21_string.h"

void s21_find_index_start(const char *src, const char *trim_chars, s21_size_t *pointer_start) {
	s21_size_t i = 0;
	s21_size_t j = 0;
	int flag = 0;
	for(; i < s21_strlen(src); i++) {
		for(j = 0; j < s21_strlen(trim_chars); j++) {
			if (src[i] == trim_chars[j]) {
				flag = 1;
			}
		}
		if (flag == 0) {
			*pointer_start = i;
			break;
		}
		flag = 0;
	}
}

void s21_find_index_end(const char *src, const char *trim_chars, s21_size_t *pointer_end) {
	s21_size_t i = s21_strlen(src) - 1;
	s21_size_t j = 0;
	int flag = 0;
	for(; (int)i >= 0; i--) {
		for(j = 0; j < s21_strlen(trim_chars); j++) {
			if (src[i] == trim_chars[j]) {
				flag = 1;
			}
		}
		if (flag == 0) {
			*pointer_end = i;
			break;
		}
		flag = 0;
	}
}

char *s21_strcpy_by_index(const char *src, int index_start, int index_end) {
	char *answer = (char *)s21_NULL;
	if (index_start <= index_end + 1) {
		answer = (char *)malloc(index_end - index_start + 2);
		if (answer) {
			for(int i = 0; i < index_end - index_start + 1; i++) {
				answer[i] = src[i + index_start];
			}
			answer[index_end - index_start + 1] = '\0';
		}
	}
	return answer;
}

void *s21_trim(const char *src, const char *trim_chars) {
	char *answer = (char *)s21_NULL;
	if (src) {
		if (trim_chars && s21_strlen(trim_chars) != 0) {
			s21_size_t index_start = 0;
			s21_size_t index_end = s21_strlen(src);
			s21_find_index_start(src, trim_chars, &index_start);
			s21_find_index_end(src, trim_chars, &index_end);
			answer = s21_strcpy_by_index(src, index_start, index_end);
		} else {
			answer = (char *)malloc(s21_strlen(src) + 1);
			if (answer) {
				s21_strcpy(answer, src);
				answer[s21_strlen(src)] = '\0';
			}
		}
	}
	return (void *)answer;
}