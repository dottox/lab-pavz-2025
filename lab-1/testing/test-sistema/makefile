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


all: test.o dtSocio.o dtFecha.o socio.o dtSpinning.o dtEntrenamiento.o entrenamiento.o spinning.o dtClase.o sistema.o clase.o inscripcion.o
	g++ test-sistema.o dtFecha.o dtSocio.o socio.o dtSpinning.o dtEntrenamiento.o entrenamiento.o spinning.o dtClase.o clase.o sistema.o inscripcion.o -o programa -Wall

test.o: sistema.o
	g++ -c "test-sistema.cpp"

dtSocio.o: 
	g++ -c "../../dataStructures/dtSocio.cpp"

dtFecha.o:
	g++ -c "../../dataStructures/dtFecha.cpp"

socio.o: dtSocio.o 
	g++ -c "../../clases/socio.cpp"

dtSpinning.o: dtClase.o
	g++ -c "../../dataStructures/dtSpinning.cpp"

dtEntrenamiento.o: dtClase.o
	g++ -c "../../dataStructures/dtEntrenamiento.cpp"

entrenamiento.o: dtEntrenamiento.o clase.o
	g++ -c "../../clases/entrenamiento.cpp"

spinning.o: dtSpinning.o clase.o
	g++ -c "../../clases/spinning.cpp"

dtClase.o:
	g++ -c "../../dataStructures/dtClase.cpp"

sistema.o: socio.o spinning.o entrenamiento.o clase.o inscripcion.o
	g++ -c "../../clases/sistema.cpp"

clase.o: dtClase.o
	g++ -c "../../clases/clase.cpp"

inscripcion.o: socio.o dtFecha.o
	g++ -c "../../clases/inscripcion.cpp"


clean:
	$(DELETE) *.o programa*

run: 
	$(MAKE) clean
	$(MAKE) all
	./programa.exe
	$(MAKE) clean