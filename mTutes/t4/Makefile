CC = g++ -std=c++14 -Wall -Werror

all: t4

t4: main.o book.o
	$(CC) main.o book.o -o t4

main.o : Main.cpp Book.hpp
	$(CC) -O2 -c Main.cpp

book.o : Book.cpp Book.hpp
	$(CC) -O2 -c Book.cpp

clean :
	rm *o t4