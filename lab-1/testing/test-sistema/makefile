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


all: test.o dtSocio.o dtFecha.o dtEntrenamiento.o dtSpinning.o dtClase.o socio.o entrenamiento.o spinning.o clase.o inscripcion.o sistema.o
	g++ -o programa test-sistema.o dtSocio.o dtClase.o dtEntrenamiento.o dtSpinning.o entrenamiento.o spinning.o dtFecha.o socio.o clase.o inscripcion.o sistema.o

test.o:
	g++ -c "test-sistema.cpp"

entrenamiento.o: dtEntrenamiento.o
	g++ -c "../../clases/entrenamiento.cpp"

spinning.o: dtSpinning.o
	g++ -c "../../clases/spinning.cpp"

dtSocio.o:
	g++ -c "../../dataStructures/dtSocio.cpp"

dtEntrenamiento.o:
	g++ -c "../../dataStructures/dtEntrenamiento.cpp"

dtSpinning.o:
	g++ -c "../../dataStructures/dtSpinning.cpp"

dtClase.o:
	g++ -c "../../dataStructures/dtClase.cpp"

dtFecha.o:
	g++ -c "../../dataStructures/dtFecha.cpp"

socio.o: dtSocio.o
	g++ -c "../../clases/socio.cpp"

sistema.o: socio.o
	g++ -c "../../clases/sistema.cpp"

clase.o: dtClase.o
	g++ -c "../../clases/clase.cpp"

inscripcion.o: dtFecha.o 
	g++ -c "../../clases/inscripcion.cpp"

clean:
	$(DELETE) *.o programa*

run:
	$(MAKE) clean
	$(MAKE) all
	./programa
	$(MAKE) clean