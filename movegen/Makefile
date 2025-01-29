all:
	g++  -Wall -Wextra -Wpedantic -Wshadow -O3 main.cpp attacks.cpp -o null.exe

test:
	g++ -g3 -fsanitize=leak main.cpp attacks.cpp -o null.exe
