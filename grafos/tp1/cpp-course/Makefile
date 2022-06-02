# build.sh
#!/bin/bash
build:
	g++ -std=c++11 -O2 main.cpp -o main

run: build
	./main

build-vectors:
	g++ -std=c++11 -O2 vectors.cpp -o vectors

run-vectors: build-vectors
	./vectors

build-matrix:
	g++ -std=c++11 -O2 matrix.cpp -o matrix
	
run-matrix: build-matrix
	./matrix


clean: 
	stty sane