CXX := g++
HEADERS := functions.h
OBJ := init.o
TARGETS := 1-p1p2 1-p3 2-p3 2-p4-o0 2-p4-o1 2-p4-o2 2-p4-o3

1-p1p2: 1.p1p2.main.o 1.p1.dgemm0.o 1.p1.dgemm1.o 1.p2.dgemm2.o $(OBJ)
	$(CXX) -o $@ $^

1-p3: 1.p3.main.o 1.p1.dgemm0.o 1.p1.dgemm1.o 1.p2.dgemm2.o 1.p3.dgemm3.o $(OBJ)
	$(CXX) -o $@ $^

2-p3: 2.p3.main.o 2.algo.o $(OBJ)
	$(CXX) -o $@ $^

2-p4: 
	$(CXX) -c -o init.o init.cpp -O0
	$(CXX) -c -o 2.p4.main.o 2.p4.main.cpp -O0
	$(CXX) -o 2-p4-o0 2.p4.main.o init.o -O0
	rm init.o 2.p4.main.o
	$(CXX) -c -o init.o init.cpp -O1
	$(CXX) -c -o 2.p4.main.o 2.p4.main.cpp -O1
	$(CXX) -o 2-p4-o1 2.p4.main.o init.o -O1
	rm init.o 2.p4.main.o
	$(CXX) -c -o init.o init.cpp -O2
	$(CXX) -c -o 2.p4.main.o 2.p4.main.cpp -O2
	$(CXX) -o 2-p4-o2 2.p4.main.o init.o -O2
	rm init.o 2.p4.main.o
	$(CXX) -c -o init.o init.cpp -O3
	$(CXX) -c -o 2.p4.main.o 2.p4.main.cpp -O3
	$(CXX) -o 2-p4-o3 2.p4.main.o init.o -O3
	rm init.o 2.p4.main.o
	

%.o: %.cpp functions.h
	$(CXX) -c $< -o $@

.PHONY clean:
	rm -f *.o $(TARGETS)