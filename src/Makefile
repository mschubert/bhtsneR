# Makefile for bh_tsne

CC = g++
CXXFLAGS = -Wall -Wextra -I. -O3 -g -fPIC
LIBS = -lcblas

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

