main: main.cpp Book
	g++ -std=c++14 -Wall -Werror -o main main.cpp Book.o

Book: Book.hpp Book.cpp
	g++ -std=c++14 -Wall -Werror -c -o Book.o Book.cpp

clean:
	rm -f *.o *~ main a.out
