
bin/fibo: fibo.c main.c
	gcc -o bin/fibo src/fibo.o src/main.o -Wall -lm

fibo.o: fibo.c
	gcc -c src/fibo.c -o fibo.o

main.o: main.c
	gcc -c src/main.c -o main.o


.PHONY: tmpclean clean

tmpclean:
	rm -f src/*~ *~
clean: tmpclean
	rm -f bin/fibo src/fibo.o src/fibo.c
	