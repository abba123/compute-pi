CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall -fopenmp -mavx
EXECUTABLE = \
	time_test_baseline time_test_openmp \
	time_test_avx time_test_avxunroll time_test_leibniz_2 \
	time_test_leibniz_2_openmp_4 time_test_wallis \
	time_test_wallis_openmp_4 benchmark_clock_gettime

default: computepi.o
	$(CC) $(CFLAGS) computepi.o time_test.c -DBASELINE -o time_test_baseline
	$(CC) $(CFLAGS) computepi.o time_test.c -DOPENMP -o time_test_openmp
	$(CC) $(CFLAGS) computepi.o time_test.c -DAVX -o time_test_avx
	$(CC) $(CFLAGS) computepi.o time_test.c -DAVXUNROLL -o time_test_avxunroll
	$(CC) $(CFLAGS) computepi.o time_test.c -DLEIBNIZ_2 -o time_test_leibniz_2
	$(CC) $(CFLAGS) computepi.o time_test.c -DLEIBNIZ_2_OMP -o time_test_leibniz_2_openmp_4
	$(CC) $(CFLAGS) computepi.o time_test.c -DWALLIS -o time_test_wallis
	$(CC) $(CFLAGS) computepi.o time_test.c -DWALLIS_OMP -o time_test_wallis_openmp_4
	$(CC) $(CFLAGS) computepi.o benchmark_clock_gettime.c -o benchmark_clock_gettime
.PHONY: clean default

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ 

check: default
	time ./time_test_baseline
	time ./time_test_openmp
	time ./time_test_avx
	time ./time_test_avxunroll
	time ./time_test_leibniz_2
	time ./time_test_leibniz_2_openmp_4
	time ./time_test_wallis
	time ./time_test_wallis_openmp_4

gencsv: default
	for i in `seq 1000 5000 10000000`; do \
		printf "%d " $$i;\
		./benchmark_clock_gettime $$i; \
	done > result_clock_gettime.csv	

clean:
	rm -f $(EXECUTABLE) *.o *.s result_clock_gettime.csv
