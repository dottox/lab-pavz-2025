all: test.o spinning.o clase.o
	g++ testSpinning.o spinning.o clase.o -o programa

test.o:
	g++ -c "testSpinning.cpp"

spinning.o:
	g++ -c "../../clases/spinning.cpp"

clase.o:
	g++ -c ../../clases/clase.cpp

clean:
	rm -f *.o "programa"

run:
	make clean
	make all
	./programa
	make clean