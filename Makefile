##
# Ash --- Another Shell
#
# @file
# @version 0.1

all: change-pos destroy elder emics print-file where

ash: src/main.cpp src/ash.cpp src/ash.hpp
	echo "TODO"

change-pos: src/change-pos.cpp src/ash.hpp
	echo "TODO"

destroy: src/destroy.cpp src/ash.hpp
	echo "TODO"

elder: src/elder.cpp src/ash.hpp
	echo "TODO"

emics: src/emics.cpp src/ash.hpp
	g++ -o bin/emics src/emics.cpp -lreadline

print-file: src/print-file.cpp src/ash.hpp
	echo "TODO"

where: src/where.c src/ash.hpp
	echo "TODO"

elder-pages: elder/*.man
	for e in elder/*.man; do \
	groff -man -Tutf8 "$$e" > "elder/"`basename -s .man $$e`".elder"; done

format:
	indent -kr src/*.{cpp,hpp}

# end
