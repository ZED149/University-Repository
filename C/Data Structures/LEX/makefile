

CC=gcc


all: Lex.o List.o ListTest.o
	$(CC) -std=c17 Lex.o List.o ListTest.o -o out

Lex: Lex.c
	$(CC) -std=c17  -c Lex.c -o Lex.o	
	
List: List.c
	$(CC) -std=c17  -c List.c -o List.o

ListTest: ListTest.c
	$(CC) -std=c17  -c ListTest.c -o ListTest.o

clean:
	rm -rf *.o out
