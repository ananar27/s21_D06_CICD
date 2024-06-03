CC_FLAGS = -Wall -Wextra -Werror -std=c11

all: s21_cat test clean

s21_cat: s21_cat.c s21_cat.h
	gcc $(CC_FLAGS) s21_cat.c -o s21_cat

clean:
	rm -rf s21_cat
	rm -f cat/*.o log.txt .clang-format

style:
	cp ../../materials/linters/.clang-format ./	
	clang-format -n *.c *.h
	clang-format -i *.c *.h
test:
	bash t_cat.sh

rebuild: clean all