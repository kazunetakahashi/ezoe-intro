gcc_options = -std=c++17 -Wall --pedantic-error

program : hello.cpp all.h all.h.gch
	g++-9 $(gcc_options) -include all.h $< -o $@

all.h.gch : all.h
	g++-9 $(gcc_options) -x c++-header -o $@ $<

run : program
	./program

clean :
	rm -f ./program
	rm -f ./all.h.gch

.PHONY : run clean
