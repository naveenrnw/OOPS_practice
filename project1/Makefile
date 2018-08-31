all:test

test:main.o function.o header.o
	g++ $^ -o $@
function.o: function.cpp function.h
	g++ function.cpp -c
header.o: header.cpp header.h
	g++ header.cpp -c
main.o: main.cpp header.h function.h
	g++ main.cpp -c
clean:
	rm -rf *.o test
run:
	./test
	
