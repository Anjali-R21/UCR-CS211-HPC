CXX := g++
HEADERS := functions.h
OBJ := init.o
TARGETS := 1-p1

1-p1: 1.p1.main.o 1.p1.dgemm0.o 1.p1.dgemm1.o $(OBJ)
	$(CXX) -o $@ $^

%.o: %.c functions.h
	$(CXX) -c $< -o $@

.PHONY clean:
	rm -f *.o $(TARGETS)