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


all: test.o entrenamiento.o clase.o dtClase.o dtEntrenamiento.o inscripcion.o socio.o dtFecha.o dtSocio.o
	g++ test-entrenamiento.o entrenamiento.o clase.o dtClase.o dtEntrenamiento.o inscripcion.o socio.o dtFecha.o dtSocio.o -o programa

test.o:
	g++ -c "test-entrenamiento.cpp"

entrenamiento.o: dtEntrenamiento.o clase.o
	g++ -c "../../clases/entrenamiento.cpp"

clase.o: dtClase.o inscripcion.o 
	g++ -c "../../clases/clase.cpp"

dtClase.o:
	g++ -c "../../dataStructures/dtClase.cpp"

dtEntrenamiento.o: dtClase.o
	g++ -c "../../dataStructures/dtEntrenamiento.cpp"

inscripcion.o: socio.o dtFecha.o
	g++ -c "../../clases/inscripcion.cpp"

socio.o: dtSocio.o
	g++ -c "../../clases/socio.cpp"

dtSocio.o:
	g++ -c "../../dataStructures/dtSocio.cpp"

dtFecha.o:
	g++ -c "../../dataStructures/dtFecha.cpp"

clean:
	$(DELETE) *.o programa*

run:
	$(MAKE) clean
	$(MAKE) all
	./programa
	$(MAKE) clean