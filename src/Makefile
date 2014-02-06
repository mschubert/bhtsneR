# Makefile for bh_tsne

CCFLAGS = -Wall -Wextra -I. -O3 -g -fPIC
LIBS = -lcblas
CC = g++

SOURCE = $(wildcard *.cpp)
OBJ = $(SOURCE:%.cpp=%.o)

.INTERMEDIATE: $(OBJ)

all: bh_tsne.so

bh_tsne.so: $(OBJ)
	$(CC) -shared -Wl,-soname,$@ $(LIBS) -o $@ $^

%.o: %.c include/%.h
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -f bh_tsne.so $(OBJ)

