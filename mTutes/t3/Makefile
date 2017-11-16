all: t3

t3 : t3main.o t3.o
	g++ -std=c++11 -Wall -Werror t3main.o t3.o -o t3

t3main.o : t3main.cpp t3.hpp 
	g++ -std=c++11 -Wall -Werror -O2 -c t3main.cpp
t3.o : t3.cpp t3.hpp
	g++ -std=c++11 -Wall -Werror -O2 -c t3.cpp

clean:
	rm *o t3