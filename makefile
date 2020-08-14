flags = g++ -std=c++14 -Wall -Werror -MP -MMD
bi = bin
bu = build
t = tests
s = src

all: clean1 folders $(bi)/main

<<<<<<< HEAD
$(bi)/main: $(bu)/main.o $(bu)/inst.o $(bu)/r.o $(bu)/s.o
=======
$(bi)/main: $(bu)/main.o $(bu)/inst.o $(bu)/s.o $(bu)/string_processing.o
>>>>>>> iss3
	$(flags) $^ -o $@

$(bu)/main.o: $(s)/main.cpp $(s)/incl.h $(s)/st.h
	$(flags) -c $< -o $@

$(bu)/inst.o: $(s)/inst.cpp $(s)/incl.h
	$(flags) -c $< -o $@

$(bu)/s.o: $(s)/s.cpp $(s)/incl.h
	$(flags) -c $< -o $@

<<<<<<< HEAD
$(bu)/r.o: $(s)/r.cpp $(s)/incl.h $(s)/st.h
=======
$(bu)/string_processing.o: $(s)/string_processing.cpp $(s)/incl.h
>>>>>>> iss3
	$(flags) -c $< -o $@

folders:
	mkdir -p $(bi)
	mkdir -p $(bu)

clean1:
	rm -rf $(bu)/*.o
	rm -rf $(bu)/*.d
