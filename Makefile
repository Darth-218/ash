##
# Ash --- Another Shell
#
# @file
# @version 0.1

all: ash afifi bullets mazen zein clean

ash: bin/ash
afifi: bin/view-file bin/print-file bin/history
bullets: bin/print-dir bin/where
mazen: bin/clone bin/punch
zein: bin/elder bin/emics bin/fun

clean:
	rm bin/*.o -f

bin/ash: src/main.cpp bin/ash.o
	g++ -o bin/ash bin/ash.o src/main.cpp

bin/ash.o: src/ash.cpp src/ash.hpp
	g++ -c -o bin/ash.o src/ash.cpp

bin/change-loc: src/change-loc.cpp src/ash.hpp
	g++ -o bin/change-loc src/change-loc.cpp

bin/clone: src/clone.cpp src/ash.hpp
	g++ -o bin/clone src/clone.cpp

bin/destroy: src/destroy.cpp src/ash.hpp
	g++ -o bin/destroy src/destroy.cpp

bin/elder: bin/ash.o src/elder.cpp src/ash.hpp
	g++ -o bin/elder bin/ash.o src/elder.cpp

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

bin/view-file: src/view-file.cpp src/ash.hpp
	g++ -o bin/view-file src/view-file.cpp -lncurses

bin/where: src/where.c src/ash.hpp
	gcc -o bin/where src/where.c

bin/history: src/history.hpp src/ash.hpp
	g++ -o bin/history src/history.hpp

elder-pages: elder/*.man
	for e in elder/*.man; do \
	groff -man -Tutf8 "$$e" > "elder/"`basename -s .man $$e`".elder"; done

# end
