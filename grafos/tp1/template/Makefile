# build.sh
#!/bin/bash
build:
	g++ -std=c++11 -O2 main.cpp -o main

run: build
	./main < input.txt

test:
	./run.sh input.txt output.txt # output vai ser gerado

#./build.sh # se der problema use chmod 777 build.sh
