.PHONY: all
all: simpson_rule

simpson_rule.o: simpson_rule.cpp simpson_rule.hpp
				c++ -c simpson_rule.cpp

main.o: main.cpp simpson_rule.hpp
		c++ -c main.cpp

simpson_rule: main.o simpson_rule.o
			  c++ -o simpson_rule main.o simpson_rule.o
library: simpson_rule.cpp
		ar -crs libintegrate.a simpson.o

.PHONY: clean
clean: 
		rm *.o simpson_rule result.txt
