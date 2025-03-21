all: main.o
	g++ main.o -o programa

main.o:
	g++ -c "../main.cpp"

clean:
	rm -f "main.o" "programa"

run:
	make clean
	make
	./programa