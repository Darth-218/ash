##
# Ash --- Another Shell
#
# @file
# @version 0.1

all: bin/ash afifi bullets mazen zein clean

afifi: bin/view-file bin/print-file
bullets: bin/print-dir bin/where
mazen: bin/cpfile bin/punch
zein: bin/elder bin/emics bin/fun

clean:
	rm bin/*.o -f

bin/ash: src/main.cpp bin/ash.o
	g++ -o bin/ash bin/ash.o src/main.cpp

bin/ash.o: src/ash.cpp src/ash.hpp
	g++ -c -o bin/ash.o src/ash.cpp

bin/change-loc: src/change-loc.cpp src/ash.hpp
	g++ -o bin/change-loc src/change-loc.cpp

bin/cpfile: src/cpfile.c++ src/ash.hpp
	g++ -o bin/cpfile src/cpfile.c++

bin/destroy: src/destroy.cpp src/ash.hpp
	g++ -o bin/destroy src/destroy.cpp

bin/elder: src/elder.cpp src/ash.hpp
	g++ -o bin/elder src/elder.cpp

bin/emics: src/emics.cpp src/ash.hpp
	g++ -o bin/emics src/emics.cpp -lreadline

bin/fun: src/fun.cpp src/ash.hpp
	g++ -o bin/fun src/fun.cpp

bin/print-dir: src/print-dir.c
	g++ -o bin/print-dir src/print-dir.c

bin/print-file: src/print-file.cpp src/ash.hpp
	g++ -o bin/print-file src/print-file.cpp

bin/punch: src/punch.cpp src/ash.hpp
	g++ -o bin/punch src/punch.cpp

bin/view-file:
	echo "TODO"

bin/where: src/where.c src/ash.hpp
	gcc -o bin/where src/where.c

elder-pages: elder/*.man
	for e in elder/*.man; do \
	groff -man -Tutf8 "$$e" > "elder/"`basename -s .man $$e`".elder"; done

format:
	indent -kr src/*.{cpp,hpp}

# end
