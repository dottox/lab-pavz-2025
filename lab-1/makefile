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


all: dtSocio.o dtFecha.o dtClase.o dtSpinning.o dtEntrenamiento.o socio.o inscripcion.o clase.o spinning.o entrenamiento.o main.o
	g++ dtSocio.o dtFecha.o dtClase.o dtSpinning.o dtEntrenamiento.o socio.o inscripcion.o clase.o spinning.o entrenamiento.o main.o -o programa

################### Data structures ##################

dtSocio.o:
	g++ -c "dataStructures/dtSocio.cpp"

dtFecha.o:
	g++ -c "dataStructures/dtFecha.cpp"

dtClase.o:
	g++ -c "dataStructures/dtClase.cpp"

dtSpinning.o: dtClase.o
	g++ -c "dataStructures/dtSpinning.cpp"

dtEntrenamiento.o: dtClase.o
	g++ -c "dataStructures/dtEntrenamiento.cpp"

######################################################


################### Clases ###########################


socio.o: dtSocio.o
	g++ -c "clases/socio.cpp"

inscripcion.o: socio.o dtFecha.o
	g++ -c "clases/inscripcion.cpp"

clase.o: dtClase.o inscripcion.o
	g++ -c "clases/clase.cpp"

spinning.o: clase.o dtSpinning.o
	g++ -c "clases/spinning.cpp"

entrenamiento.o: clase.o dtEntrenamiento.o
	g++ -c "clases/entrenamiento.cpp"

######################################################


main.o:
	g++ -c "main.cpp"


clean:
	$(DELETE) *.o programa

run:
	$(MAKE) clean
	$(MAKE) all
	./programa
	$(MAKE) clean