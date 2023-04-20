.SUFFIXES : .cpp
CC = g++

CXXFLAGS = -g -std=c++11

OBJS = Water.o

TARGET = hw4

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<


clean:
	rm -f $(OBJS) $(TARGET) core

zipIt:
	zip -r Avila_R_HW4.zip Water.cpp README makefile