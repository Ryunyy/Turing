flags = g++ -std=c++14 -Wall -Werror -MP -MMD
bi = bin
bu = build
t = tests
s = src

all: clean1 folders $(bi)/main

$(bi)/main: $(bu)/main.o $(bu)/inst.o $(bu)/inrules.o $(bu)/instr.o
	$(flags) $^ -o $@

$(bu)/main.o: $(s)/main.cpp $(s)/incl.h
	$(flags) -c $< -o $@

$(bu)/inst.o: $(s)/inst.cpp $(s)/incl.h
	$(flags) -c $< -o $@

$(bu)/inrules.o: $(s)/inrules.cpp $(s)/incl.h
	$(flags) -c $< -o $@

$(bu)/instr.o: $(s)/instr.cpp $(s)/incl.h
	$(flags) -c $< -o $@

folders:
	mkdir -p $(bi)
	mkdir -p $(bu)

clean1:
	rm -rf $(bu)/*.o
	rm -rf $(bu)/*.d
