CFLAGS=-Wall -std=c99
CC=gcc
SOURCE=src/
TEST=tests/

all: check

clean:
	rm -f *.a *.o rpn test_suite

check: clean check_to_rpn.o testRunner.o rpn.o
	gcc -o test_suite check_to_rpn.o converter.o testRunner.o -lcheck -pthread -lcheck_pic -lrt -lm -L. -lrpn
	./test_suite

rpn.o: converter.o
	${CC} ${CFLAGS} -c ${SOURCE}rpn.c -o rpn.o
	ar rcs librpn.a rpn.o

converter.o:
	${CC} ${CFLAGS} -c ${SOURCE}converter.c -o converter.o

check_to_rpn.o:
	${CC} ${CFLAGS} -c ${TEST}check_to_rpn.c -o check_to_rpn.o

testRunner.o:
	${CC} ${CFLAGS} -c ${TEST}testRunner.c -o testRunner.o

valgrind:
	valgrind ./${SOURCE}rpn
