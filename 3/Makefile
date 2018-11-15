CC := mpicc
TARGETS := sieve0 sieve1 sieve2 sieve3
LIBS := -lm

all: config $(TARGETS)

%: %.c
	$(CC) $< -o $@ $(LIBS)

.PHONY config:
	module load openmpi-3.0/gcc-4.8.5

.PHONY clean:
	rm -f $(TARGETS)