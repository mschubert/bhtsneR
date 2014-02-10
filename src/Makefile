# Makefile for bh_tsne

TARGET = bhtsneR.so

CC = g++
CXXFLAGS = $(shell pkg-config --silence-errors --cflags cblas) -Wall -Wextra -I. -O3 -g -fPIC
LIBS = $(shell pkg-config --silence-errors --libs cblas)

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

