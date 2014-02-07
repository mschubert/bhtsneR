# Makefile for bh_tsne

TARGET = bhtsneR.so

CC = g++
CXXFLAGS = -Wall -Wextra -I. -O3 -g -fPIC
LIBS = -lcblas

SOURCE = $(wildcard *.cpp)
OBJ = $(SOURCE:%.cpp=%.o)

.INTERMEDIATE: $(OBJ)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -shared -Wl,-soname,$@ $(LIBS) -o $@ $^

%.o: %.c %.h
	$(CC) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJ)

