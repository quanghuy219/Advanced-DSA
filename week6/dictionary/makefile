CFLAG=-Wall -g
main: main.c
	gcc -o main main.c -Ibt/inc -Lbt/lib -lbt -D_FILE_OFFSET_BITS=64

test: test.c
	gcc -o test test.c -Ibt/inc -Lbt/lib -lbt -D_FILE_OFFSET_BITS=64