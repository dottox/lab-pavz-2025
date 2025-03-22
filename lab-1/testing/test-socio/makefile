# Detect the operating system
OS := $(shell uname -s)

# Set the MAKE variable based on the OS
ifeq ($(OS),Linux)
    MAKE := make
else ifeq ($(OS),Darwin)  # macOS is also Unix-based
    MAKE := make
else ifeq ($(findstring MSYS_NT,$(OS)),MSYS_NT)  # Windows with MSYS/MinGW
    MAKE := mingw32-make
else
    $(error Unsupported OS: $(OS))
endif

all: test.o socio.o
	g++ testSocio.o socio.o -o programa

test.o:
	g++ -c "testSocio.cpp"

socio.o:
	g++ -c "../../clases/socio.cpp"

clean:
	rm -f *.o "programa"

run:
	$(MAKE) clean
	$(MAKE) all
	./programa
	$(MAKE) clean