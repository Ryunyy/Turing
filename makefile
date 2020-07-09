flags = g++ -std=c++14 -Wall -Werror -MP -MMD
bi = bin
bu = build
t = tests
s = src

all: clean folders $(bu)/inst.o

$(bu)/inst.o: $(s)/inst.cpp $(s)/incl.h
	$(flags) -c $< -o $@

folders:
	mkdir -p $(bi)
	mkdir -p $(bu)

clean:
	rm -rf $(bu)/*.o
