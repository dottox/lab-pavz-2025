all: test.o spinning.o
<<<<<<< HEAD
	g++ test.o socio.o -o programa
=======
	g++ testSpinning.o spinning.o -o programa
>>>>>>> b7c13e9e5c62b27a99c5e6cdce1c5e897793f84e

test.o:
	g++ -c "testSpinning.cpp"

spinning.o:
<<<<<<< HEAD
	g++ -c "../clases/spinning.cpp"
=======
	g++ -c "../../clases/spinning.cpp"
>>>>>>> b7c13e9e5c62b27a99c5e6cdce1c5e897793f84e

clean:
	rm -f *.o "programa"

run:
	make clean
	make all
	./programa
	make clean