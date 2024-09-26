CC=gcc
CFLAGS=-c -std=c11
SOURCE = $(wildcard s21_*.c)
O_FILES = $(SOURCE:.c=.o)

all: s21_string.a

s21_string.a: $(O_FILES)
	ar r s21_string.a $(O_FILES)
	ranlib s21_string.a

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

test: test.o s21_string.a
	$(CC) test.o s21_string.a -o test -lcheck
	./test

gcov_report: 
	$(CC) --coverage $(SOURCE) test.c -o s21_test -lcheck
	./s21_test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

test.o: test.c
	$(CC) $(CFLAGS) test.c -o test.o


clang:
	clang-format --style=Google -i *.c *.h

clean: 
	rm -rf *.o *.gcda *.gcno test s21_string.a report s21_test s21_test.info