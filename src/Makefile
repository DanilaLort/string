EXECUTABLE=string.a

CC=gcc
CFLAGS=-Wall -Wextra -Werror
TFLAGS=-Wall -Wextra -Werror -lcheck

OBJDIR	=	objs
SRCDIR	=	s21_string

SRC=s21_memcpy.c s21_strchr.c s21_strpbrk.c s21_to_lower.c\
	s21_convertor.c  s21_strcmp.c  s21_strlen.c   s21_strrchr.c \
	s21_to_upper.c  s21_insert.c  s21_memset.c  s21_strcpy.c\
	s21_strncat.c  s21_strspn.c  s21_trim.c  s21_memchr.c\
	s21_strcspn.c  s21_strncmp.c  s21_strstr.c  s21_memcmp.c\
	s21_strcat.c  s21_strncpy.c  s21_strncpy.c s21_strtok.c\
	s21_memmove.c
SRC		:=	$(addprefix $(SRCDIR)/, $(SRC))
OBJ		=	$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRC:.c=.o))

all: re test

s21_string.a: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	ar rcs $(EXECUTABLE) $?
	ranlib $(EXECUTABLE)

$(OBJ):		|$(OBJDIR)

$(OBJDIR):
			@mkdir $(OBJDIR)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c *.h
			$(CC) $(CFLAGS) -I ./includes -c $< -o $@

clean:
			@rm -rf $(OBJDIR) test
			@rm -f $(EXECUTABLE)

re: clean s21_string.a


test:re
	$(CC) $(TFLAGS) tests/*.c string.a -o test
	./test
