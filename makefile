flags = g++ -std=c++14 -Wall -Werror -MP -MMD
bi = bin
bu = build
t = tests
s = src

all: clean1 folders $(bi)/main

$(bi)/main: $(bu)/main.o $(bu)/inst.o $(bu)/r.o $(bu)/s.o $(bu)/string_processing.o $(bu)/replacement_letters.o $(bu)/move.o
	$(flags) $^ -o $@

$(bu)/main.o: $(s)/main.cpp $(s)/incl.h
	$(flags) -c $< -o $@

$(bu)/inst.o: $(s)/inst.cpp $(s)/incl.h
	$(flags) -c $< -o $@

$(bu)/s.o: $(s)/s.cpp $(s)/incl.h
	$(flags) -c $< -o $@

$(bu)/r.o: $(s)/r.cpp $(s)/incl.h
	$(flags) -c $< -o $@

$(bu)/string_processing.o: $(s)/string_processing.cpp $(s)/incl.h
	$(flags) -c $< -o $@

$(bu)/replacement_letters.o: $(s)/replacement_letters.cpp $(s)/incl.h
	$(flags) -c $< -o $@

$(bu)/move.o: $(s)/move.cpp $(s)/incl.h
	$(flags) -c $< -o $@

folders:
	mkdir -p $(bi)
	mkdir -p $(bu)

clean1:
	rm -rf $(bu)/*.o
	rm -rf $(bu)/*.d
