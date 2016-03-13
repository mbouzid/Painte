CXX		= g++
CFLAGS		= -Wall
STD		= -std=c++11
INC		= -I/usr/include/qt4 -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui
LIB		= -lQtCore -lQtGui
LINK		= g++
RM		= rm
MOC		= moc
###### Files
SOURCES		= main.cpp
OBJECTS		= moc_draw_area.o main.o 
HEADERS		= main_window.hpp draw_area.hpp draw_widget.hpp
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

moc_draw_area.o: moc_draw_area.cpp
	$(CXX) -c $(CFLAG) $(INC) -o moc_draw_area.o moc_draw_area.cpp

##### MOC routine
moc_draw_area.cpp: draw_area.hpp
	$(MOC) $(INC) -o moc_draw_area.cpp draw_area.hpp
#### Cleaning routine
clean: $(OBJECTS)
	$(RM) $(OBJECTS)
