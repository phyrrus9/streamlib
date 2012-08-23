all:
	@echo "Cleaning old files"
	@make clean
	@echo "Building objects.."
	@make objects
	@echo "Creating archive"
	@make archive
	@echo "Done!"
archive:
	@ar rvs stream.a *.o > archive.log
	@rm *.o
	@rm *.log
objects:
	@g++ -c streams.cpp -o streams.o
	@g++ -c strings.cpp -o strings.o
	@g++ -c temperatures.cpp -o temperatures.o
clean:
	@rm -rf build/ *.o *.a *.out
