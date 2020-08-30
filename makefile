flags = g++ -std=c++14 -Wall -Werror -MP -MMD
bi = bin
bu = build
t = test
s = src

all: clean1 folders $(bi)/main $(bi)/turing_test

$(bi)/main: $(bu)/main.o $(bu)/inst.o $(bu)/r.o $(bu)/s.o $(bu)/string_processing.o $(bu)/replacement_letters.o $(bu)/move.o $(bu)/pointer.o $(bu)/r-inspection.o $(bu)/check_row.o
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

$(bu)/pointer.o: $(s)/pointer.cpp $(s)/incl.h
	$(flags) -c $< -o $@

$(bu)/r-inspection.o: $(s)/r-inspection.cpp $(s)/incl.h
	$(flags) -c $< -o $@

$(bu)/check_row.o: $(s)/check_row.cpp $(s)/incl.h
	$(flags) -c $< -o $@

$(bi)/turing_test: $(bu)/move_test.o $(bu)/turing_test.o $(bu)/check_row_test.o $(bu)/replacement_letters_test.cpp
	$(flags) $^ -o $@

$(bu)/turing_test.o: $(t)/turing_test.cpp $(t)/incl_test.h
	$(flags) -I $(t)/catch -c $< -o $@

$(bu)/move_test.o: $(t)/move_test.cpp $(t)/incl_test.h
	$(flags) -I $(t)/catch -c $< -o $@

$(bu)/check_row_test.o: $(t)/check_row_test.cpp $(t)/incl_test.h
	$(flags) -I $(t)/catch -c $< -o $@

$(bu)/replacement_letters_test.o: $(t)/replacement_letters_test.cpp $(t)/incl_test.h
	$(flags) -I $(t)/catch -c $< -o $@

run-app:$(bi)/main
	$(bi)/main

run-test:$(bi)/turing_test
	$(bi)/turing_test

folders:
	mkdir -p $(bi)
	mkdir -p $(bu)

clean1:
	rm -rf $(bu)/*.o
	rm -rf $(bu)/*.d
