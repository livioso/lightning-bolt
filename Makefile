default: *.cc *.h
	mkdir -p bin

	clang++ -Werror -std=c++1y -o bin/lightning-bolt powerplugconnector.cc lightning-bolt.cc
	./bin/lightning-bolt

	g++ -Werror -std=c++1y -o bin/lightning-bolt-gcc powerplugconnector.cc lightning-bolt.cc