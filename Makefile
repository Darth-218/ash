##
# Ash --- Another Shell
#
# @file
# @version 0.1

all: bin/destroy bin/elder bin/emics bin/print-file bin/where bin/fun clean

clean:
	rm bin/*.o -f

bin/ash: src/main.cpp bin/ash.o
	g++ -o bin/ash bin/ash.o src/main.cpp

bin/ash.o: src/ash.cpp src/ash.hpp
	g++ -c -o bin/ash.o src/ash.cpp

bin/destroy: src/destroy.cpp src/ash.hpp
	g++ -o bin/destroy src/destroy.cpp

bin/elder: src/elder.cpp src/ash.hpp
	g++ -o bin/elder src/elder.cpp

bin/emics: src/emics.cpp src/ash.hpp
	g++ -o bin/emics src/emics.cpp -lreadline

bin/print-file: src/print-file.cpp src/ash.hpp
	g++ -o bin/print-file src/print-file.cpp

bin/where: src/where.c src/ash.hpp
	gcc -o bin/where src/where.c

bin/fun: src/fun.cpp src/ash.hpp
	g++ -o bin/fun src/fun.cpp

elder-pages: elder/*.man
	for e in elder/*.man; do \
	groff -man -Tutf8 "$$e" > "elder/"`basename -s .man $$e`".elder"; done

format:
	indent -kr src/*.{cpp,hpp}

# end
