build_gcc:
	gcc -o main.out -fopenmp main.c
build:
	gcc -o main2.out -fopenmp main2.c
build3:
	gcc -o main3.out -fopenmp main3.c
build_pi:
	gcc -o pi.out -fopenmp ./Taller2_OpenMP/codigos/pi.c
test_pi:
	./pi.out 500

build_loop:
	gcc -o pi_loop.out -fopenmp ./Taller2_OpenMP/codigos/pi_loop.c
test_pi_loop:
	./pi_loop.out 500

build_SAXPY_serial:
	gcc -o saxpy_serial.out -fopenmp ./Taller2_OpenMP/codigos/saxpy_serial.c
test_SAXPY_serial:
	./saxpy_serial.out 500000000

build_SAXPY_parallel:
	gcc -o saxpy_parallel.out -fopenmp ./Taller2_OpenMP/codigos/saxpy_parallel.c
test_SAXPY_parallel:
	./saxpy_parallel.out 50000

build_EULER_parallel:
	gcc -o euler.out -fopenmp ./Taller2_OpenMP/codigos/euler.c
test_EULER_parallel:

	./euler.out 3
	./euler.out 4
	./euler.out 5
	./euler.out 10
	./euler.out 20
	./euler.out 100
	./euler.out 200
	./euler.out 1000
	./euler.out 2000
	./euler.out 10000
	./euler.out 20000
plot: 
	python3 ./Taller2_OpenMP/codigos/plot.py
