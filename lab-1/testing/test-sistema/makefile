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


all: test.o dtSocio.o socio.o sistema.o
	g++ -o programa test-sistema.o dtSocio.o socio.o sistema.o

test.o:
	g++ -c "test-sistema.cpp"

dtSocio.o:
	g++ -c "../../dataStructures/dtSocio.cpp"

socio.o: dtSocio.o
	g++ -c "../../clases/socio.cpp"

sistema.o: socio.o
	g++ -c "../../clases/sistema.cpp"

clean:
	$(DELETE) *.o programa*

run:
	$(MAKE) clean
	$(MAKE) all
	./programa
	$(MAKE) clean