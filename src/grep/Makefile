CC_FLAGS = -Wall -Wextra -Werror -std=c11

all: s21_grep test clean

s21_grep: s21_grep.c functions.c s21_grep.h
	gcc $(CC_FLAGS) s21_grep.c functions.c -o s21_grep

clean:
	rm -rf s21_grep
	rm -f grep/*.o log_grep.txt .clang-format

style:
	cp ../../materials/linters/.clang-format ./
	clang-format -n *.c *.h
	clang-format -i *.c *.h
	
test:
	bash test_grep.sh

rebuild: clean all
