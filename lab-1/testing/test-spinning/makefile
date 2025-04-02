# Detect the operating system
OS := $(shell uname -s)

# Set the MAKE and DELETE variable based on the OS
ifeq ($(OS),Linux)
    MAKE := make
		DELETE := rm -f
else ifeq ($(OS),Darwin)  # macOS is also Unix-based
    MAKE := make
		DELETE := rm -f
else ifeq ($(findstring MSYS_NT,$(OS)),MSYS_NT)  # Windows with MSYS/MinGW
    MAKE := mingw32-make
		DELETE := rm -f
else
    MAKE := mingw32-make
		DELETE := del
endif


all: test.o socio.o inscripcion.o dtFecha.o dtSocio.o dtClase.o dtSpinning.o clase.o spinning.o
	g++ test-spinning.o socio.o inscripcion.o dtFecha.o dtSocio.o dtClase.o dtSpinning.o spinning.o clase.o -o programa

test.o:
	g++ -c "test-spinning.cpp"

dtClase.o:
	g++ -c "../../dataStructures/dtClase.cpp"

dtSocio.o:
	g++ -c "../../dataStructures/dtSocio.cpp"

dtSpinning.o: dtClase.o
	g++ -c "../../dataStructures/dtSpinning.cpp"

dtFecha.o:
	g++ -c "../../dataStructures/dtFecha.cpp"


socio.o: dtSocio.o
	g++ -c "../../clases/socio.cpp"

inscripcion.o: socio.o dtFecha.o
	g++ -c "../../clases/inscripcion.cpp"

clase.o: dtClase.o inscripcion.o
	g++ -c "../../clases/clase.cpp"

spinning.o: dtSpinning.o clase.o
	g++ -c "../../clases/spinning.cpp"

clean:
	$(DELETE) *.o programa*

run:
	$(MAKE) clean
	$(MAKE) all
	./programa
	$(MAKE) clean