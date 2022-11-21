CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=return-type -Werror=uninitialized

OBJECTS = main.o passserver.o
TESTS = test-1-hashtable test-2-hashtable test-3-hashtable test-4-hashtable \
		test-5-passserver
CATCH = test/catch/catch.o

main: $(OBJECTS)
	$(CXX) -o $@ $^

test-run: main
	./main < test/input.txt

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf *.dSYM test/*.dSYM
	rm -f *.o *.gc* test/*.o test/*.gc* main $(TESTS) $(CATCH)

$(TESTS): $(CATCH)
	$(CXX) -o $@ $^
	./$@

test-all: $(TESTS)
test-1-hashtable: test/test-1-hashtable.o
test-2-hashtable: test/test-2-hashtable.o
test-3-hashtable: test/test-3-hashtable.o
test-4-hashtable: test/test-4-hashtable.o
test-5-passserver: test/test-5-passserver.o passserver.o

