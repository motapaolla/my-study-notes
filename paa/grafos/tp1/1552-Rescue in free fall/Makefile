build:
	g++ -std=c++11 -O2 main.cpp -o main

run: build
	./main

run-baby: build
	./main < baby.txt

run-full: build
	./main < input.txt

test:
	./run.sh input.txt output.txt # output vai ser gerado
