
CXX			= g++
CFLAGS			= -Wall
STD			= -std=c++11
INC			= -I/usr/include/qt4 -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui
LIB			= -lQtCore -lQtGui
LINK			= g++
RM			= rm
###### Files
SOURCES		= main.cpp
OBJECTS		= main.o
HEADERS		= draw_area.hpp draw_widget.hpp
TARGET		= Painte

##### Building rules
all: $(TARGET) clean
	@echo "Building complete."

##### Linking
$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS) $(LIB)

##### Compiling
main.o: main.cpp
	$(CXX) -c $(CFLAGS) $(INC) -o main.o main.cpp

#### Cleaning routine
clean: $(OBJECTS)
	$(RM) $(OBJECTS)

