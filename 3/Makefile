CC := mpicc
TARGETS := sieve0 sieve1 sieve2 sieve3
LIBS := -lm

all: $(TARGETS)

%: %.c
	$(CC) $< -o $@ $(LIBS)

.PHONY clean:
	rm -f $(TARGETS)