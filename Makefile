default: *.cc 
	mkdir -p bin

	clang++ -Werror -o bin/lightning-bolt lightning-bolt.cc
	./bin/lightning-bolt

	g++ -Werror -o bin/lightning-bolt-gcc lightning-bolt.cc