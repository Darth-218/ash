##
# Ash --- Another Shell
#
# @file
# @version 0.1

all: change-pos destroy elder emics print-file where
	echo "Yo mistah White there's straight up nothing for me to compile.  \
	Go write some code, bitch."

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

format:
	indent -kr src/*.{cpp,hpp}

# end
