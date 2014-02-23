# Makefile for bh_tsne

CBLAS_LIBS = $(shell pkg-config --silence-errors --libs cblas)
CBLAS_LIBS ?= -lcblas
CBLAS_INCLUDE = $(shell pkg-config --silence-errors --cflags cblas)

TARGET = bhtsneR.so
CC = g++
CXXFLAGS = $(CBLAS_INCLUDE) -Wall -Wextra -I. -O3 -g -fPIC
LIBS = $(CBLAS_LIBS)

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

