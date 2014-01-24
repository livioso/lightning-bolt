default: *.cc *.h
	mkdir -p bin

	# Temporary fix on 24.01.2014: Using C++11 instead of C++1y for clang because of this bug:
	# http://stackoverflow.com/questions/17775390/clang-3-3-in-c1y-mode-cannot-parse-cstdio-header
	clang++ -Werror -std=c++11 -o bin/lightning-bolt powerplugconnector.cc lightning-bolt.cc
	./bin/lightning-bolt

	g++ -Werror -std=c++1y -o bin/lightning-bolt-gcc powerplugconnector.cc lightning-bolt.cc
	./bin/lightning-bolt-gcc