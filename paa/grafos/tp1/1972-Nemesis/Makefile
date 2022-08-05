# build.sh
#!/bin/bash
build-main:
	g++ -std=c++11 -O2 main.cpp -o main

run: build
	./main < baby

test:
	./run.sh input output.txt
