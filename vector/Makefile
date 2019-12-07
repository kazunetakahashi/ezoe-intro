gcc_options = -std=c++2a -Wall --pedantic-error

program : main.cpp ../all.h ../all.h.gch vector.h vector_impl.h
	g++-9 $(gcc_options) -include ../all.h $< -o $@

../all.h.gch : ../all.h
	g++-9 $(gcc_options) -x c++-header -o $@ $<

run : program
	./program

clean :
	rm -f ./program
	rm -f ./all.h.gch

.PHONY : run clean
