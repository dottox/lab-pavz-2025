all: test.o spinning.o clase.o
	g++ testSpinning.o spinning.o clase.o -o programa

test.o:
	g++ -c "testSpinning.cpp"

spinning.o:
	g++ -c "../../clases/spinning.cpp"

clase.o:
	g++ -c "../../clases/clase.cpp"

clean:
	del test.o spinning.o programa

run:
	mingw32-make clean
	mingw32-make all
	./programa
	mingw32-make clean