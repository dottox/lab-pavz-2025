all: test.o spinning.o
	g++ testSpinning.o spinning.o -o programa

test.o:
	g++ -c "testSpinning.cpp"

spinning.o:
	g++ -c "../../clases/spinning.cpp"

clean:
	rm -f *.o "programa"

run:
	make clean
	make all
	./programa
	make clean