# Detect the operating system
OS := $(shell uname -s)
DELETE := del
# Set the MAKE variable based on the OS
ifeq ($(OS),Linux)
    MAKE := make
else ifeq ($(OS),Darwin)  # macOS is also Unix-based
    MAKE := make
else ifeq ($(findstring MSYS_NT,$(OS)),MSYS_NT)  # Windows with MSYS/MinGW
    MAKE := mingw32-make
	DELETE := rm -f
else
    $(error Unsupported OS: $(OS))
endif

all: test.o spinning.o clase.o
	g++ testSpinning.o spinning.o clase.o -o programa

test.o:
	g++ -c "testSpinning.cpp"

spinning.o:
	g++ -c "../../clases/spinning.cpp"

clase.o:
	g++ -c "../../clases/clase.cpp"

clean:
	$(DELETE) test.o spinning.o programa

run:
	$(MAKE) clean
	$(MAKE) all
	./programa
	$(MAKE) clean