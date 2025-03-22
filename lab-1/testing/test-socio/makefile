all: test.o socio.o
	g++ test.o socio.o -o programa

test.o:
	g++ -c "testSocio.cpp"

socio.o:
	g++ -c "../clases/socio.cpp"

clean:
	rm -f *.o "programa"

run:
	make clean
	make all
	./programa
	make clean