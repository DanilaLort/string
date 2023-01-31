#include "../s21_string.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH "Lfh"
#define SPEC_SYMBOL "cdieEfgGosuxXpn%"

typedef struct specificator {
	int sign;
	int star;
	int width;
	char length;
	char spec_symbol;
} spec;

spec spec_initialize_zero (spec format) {
	format.sign = 0;
	format.star = 0;
	format.width = -1;
	format.length = '\0';
	format.spec_symbol = '\0';
	return format;
}

void print_spec(spec format) {
	if (format.sign == 1) {
		char c = '%';
		printf("%c", c);
	}
	if (format.star == 1)
		printf("*");
	if (format.width != -1)
		printf("%d", format.width);
	if (format.length)
		printf("%c", format.length);
	if (format.spec_symbol)
		printf("%c", format.spec_symbol);
	printf("\n");
}

spec spec_initialize_from_str (char **str, spec format, int *flag_error) {
	*flag_error = 0;

	while (**str == ' ') {
		(*str)++;
	}

	if (**str == '%') {
		format.sign = 1;
		(*str)++;
	} else {
		*flag_error = 1;
		//printf("a");
	}

	if (**str == '*' && !(*flag_error)) {
		format.star = 1;
		(*str)++;
	} else {
		while (**str >= '0' && **str <= '9' && !(*flag_error)) {
			if (format.width == -1) {
				format.width = **str - '0';
				(*str)++;
			} else {
				format.width = **str - '0' + 10 * format.width;
				(*str)++;
			}
		}
	}

	if (strchr(LENGTH, **str) && !(*flag_error)) {
		format.length = **str;
		(*str)++;
	}

	if (strchr(SPEC_SYMBOL, **str) && !(*flag_error)) {
		format.spec_symbol = **str;
		(*str)++;
	} else {
		*flag_error = 1;
		//printf("a");
	}

	while (**str == ' ') {
		(*str)++;
	}

	return format;
}

int spec_validation (spec format) {
	int answer = 0;

	if (format.sign == 0)
		answer = 1;

	if (format.star == 1 && format.width > -1)
		answer = 1;

	if (format.width == 0)
		answer = 1;

	if (!format.spec_symbol)
		answer = 1;

	if (format.length == 'h' && strchr("idouxX", format.spec_symbol) == s21_NULL)
		answer = 1;

	if (format.length == 'l' && strchr("idouxXcs", format.spec_symbol) == s21_NULL)
		answer = 1;

	if (format.length == 'L' && strchr("eEfgG", format.spec_symbol) == s21_NULL)
		answer = 1;

	return answer;
}

long long int value_src_d (spec *format, char **src, int *flag_error) {
	long long int answer = 0;
	int flag_minus = 0;
	*flag_error = 0;

	while(*src && **src == ' ')
		(*src)++;

	if (*src && strchr("+-", **src)) {
		if (**src == '-')
			flag_minus = 1;
		(*src)++;
	} else {
		*flag_error = 1;
	}

	while (*src && **src >= '0' && **src <= '9' && format->width != 0 && !(*flag_error)) {
		answer = answer == 0 ? **src : 10 * answer + **src;
		if (format->width > 0)
			format->width--;
		(*src)++;
	}

	answer = flag_minus ? -answer : answer;
	return answer;
}

long long int value_src_hex (spec *format, char **src, int *flag_error) {
	long long int answer = 0;
	int flag_minus = 0;
	*flag_error = 0;

	while(*src && **src == ' ')
		(*src)++;

	if (*src && strchr("+-", **src) && !(*flag_error)) {
		if (**src == '-')
			flag_minus = 1;
		(*src)++;
	} else {
		*flag_error = 1;
	}


	if (*src && strchr("xX", **src) && !(*flag_error)) {
		(*src)++;
	} else {
		*flag_error = 1;
	}

	long long int power = -1;
	while ((*src && (**src >= '0' && **src <= '9') 	
			|| (*src && **src >= 'a' && **src <= 'f')
			|| (*src && **src >= 'A' && **src <= 'F')
			) && format->width != 0 && !(*flag_error)) {
		if (format->width > 0)
			format->width--;
		power++;
		(*src)++;
	}

	if(power == -1)
		*flag_error = 1;

	(*src) -= power + 1;
	while (power >= 0 && !(*flag_error)) {
		int temp = 0;
		if (**src >= '0' && **src <= '9') temp = **src - '0';
		if (**src >= 'a' && **src <= 'f') temp = **src - 'a' + 10;
		if (**src >= 'A' && **src <= 'F') temp = **src - 'A' + 10;
		answer += temp * powl(16, power);
		power--;
		(*src)++;
	}

	answer = flag_minus ? -answer : answer;
	return answer;
}


int main () {
/* test parser and valid
	char str[100] = " %Ld %100s %*he";
	char *str1 = str;

	printf("%s\n", str1);

	spec format;
	format = spec_initialize_zero(format);
	
	int flag_error = 0;
	while(!flag_error && *str1) {
		format = spec_initialize_from_str (&str1, format, &flag_error);
		print_spec (format);
		printf("valid:%d flg_error:%d\n", spec_validation(format), flag_error);
		format = spec_initialize_zero(format);
	}
*/
	
/* test original function */
	const char str[100] = "0x3a50 0x3a5";
	int aa;
	int aaa;
	char q;
	int a;
	int b;
	char str2[100];

	printf("%d\n", sscanf(str, "%4n%x", &aaa, &aa));
	printf("%d\n", aaa);
	printf("%d\n", aa);
//	printf("%c\n", q);
//	printf("%d\n", a);
//	printf("%s\n", str2);

	return 0;
}