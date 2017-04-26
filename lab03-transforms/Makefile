# C++ Compiler and target architecture
CC = clang++
ARCH = -arch x86_64

# Flags for the C++ compiler - C++11 standard, full warnings
CFLAGS = -c -std=c++11 -Wall -Wpedantic

# OpenCV Path
OCVDIR = /home/cshome/s/steven/Public/OpenCV

# Include path
INCFLAGS = -I$(OCVDIR)/include

# Flags for the linker
LDFLAGS = -L$(OCVDIR)/lib -lopencv_core -lopencv_highgui 

# Source files to compile
SOURCES = Display.cpp Matrix.cpp Vector.cpp transforms.cpp transformMain.cpp 

# Object files to build - a .o file for each .cpp file
OBJECTS = $(SOURCES:.cpp=.o)

# Executable to build
EXECUTABLE = transforms

# What to do to build particular things

# By default (make) clean up from last time and build the target
default: clean $(EXECUTABLE)

# To build an object file, compile the .cpp file
.cpp.o:
	$(CC) $(CFLAGS) $(INCFLAGS) $< -o $@

# To build the target link the object files together
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(ARCH) $(LDFLAGS) $(OBJECTS) -o $@

# To clean up, remove all object files, the executable, Emacs temporary files, and core dumps
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *~ core
