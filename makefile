all:
	g++ -c streams.cpp -o streams.o
	ar rvs stream.a streams.o
	rm streams.o
clean:
	rm -rf build/ *.o *.a *.out
