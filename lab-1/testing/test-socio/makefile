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

all: test.o socio.o
	g++ test-socio.o socio.o -o programa

test.o:
	g++ -c "test-socio.cpp"

socio.o:
	g++ -c "../../clases/socio.cpp"

clean:
	rm -f *.o "programa"

run:
	$(MAKE) clean
	$(MAKE) all
	./programa
	$(MAKE) clean