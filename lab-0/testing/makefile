all: test.o
	g++ test.o -o programa

test.o:
	g++ -c "../test.cpp"

clean:
	rm -f "test.o" "programa"

run:
	make clean
	make
	./programa