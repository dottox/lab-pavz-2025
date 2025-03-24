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


all: test.o entrenamiento.o clase.o
	g++ test-entrenamiento.o entrenamiento.o clase.o -o programa

test.o:
	g++ -c "test-entrenamiento.cpp"

entrenamiento.o:
	g++ -c "../../clases/entrenamiento.cpp"

clase.o:
	g++ -c "../../clases/clase.cpp"

clean:
	$(DELETE) *.o programa

run:
	$(MAKE) clean
	$(MAKE) all
	./programa
	$(MAKE) clean