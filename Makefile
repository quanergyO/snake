CC := gcc
CFLAGS := -std=c11 -Wall -Werror -Wextra
TEST_FLAGS := -lcheck
GCOV = -fprofile-arcs -ftest-coverage -fPIC
FILES := brick_game/tetris/figures/*.c brick_game/tetris/*.c gui/cli/frontend/*.c

all:
	make install
	./tetris

install:
	$(CC) $(CFLAGS) ${FILES} gui/cli/main.c -o tetris -lncurses

uninstall:
	rm tetris

debug:
	$(CC) $(CFLAGS) ${FILES} -o debug -g -lncurses

test: clean
	${CC} tests/tests_tetris.c -c -o obj/tests_tetris.o -I/opt/homebrew/Cellar/check/0.15.2/include
	${CC} ${CFLAGS} ${TEST_FLAGS} ${GCOV} ${FILES} obj/tests_tetris.o -o test -L/opt/homebrew/Cellar/check/0.15.2/lib -lncurses
	./test

gcov_report: test
	lcov -t "tetris" -o tetris.info -c -d .
	genhtml -o report tetris.info
	open report/index.html

dvi:
	doxygen Doxyfile
	open html/index.html

dist:
	mkdir Tetris/
	mkdir Tetris/src
	cp -rf * Tetris/src/
	tar cvzf Tetris.tgz Tetris/
	rm -rf Tetris/

clean:
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a tests_s21_matrix *.css *.html vgcore* report *.info *.gz *.log obj/*.o tetris

clang-format:
	clang-format --style=file:../materials/linters/.clang-format -i $(find . -type f -name "*.c")
	clang-format --style=file:../materials/linters/.clang-format -i $(find . -type f -name "*.h")

.PHONY: all install uninstall debug test gcov_report dvi dist clean clang-format
