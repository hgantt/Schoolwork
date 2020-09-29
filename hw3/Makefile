CXX      = clang++
CXXFLAGS = -g3  -std=c++11 -Wall -Wextra  -Wpedantic -Wshadow
LDFLAGS  = -g3


INCLUDES = $(shell echo *.h)
EXECS    = MetroSim

# Students will need to add other .o files
MetroSim: main.o MetroSim.o PassengerQueue.o
	${CXX} ${LDFLAGS} $^ -o $@


main.o: main.cpp PassengerQueue.h Passenger.h
MetroSim.o: Passenger.h PassengerQueue.h MetroSim.h MetroSim.cpp
PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h

# %.o: %.cpp ${INCLUDES}
#	${CXX} ${CXXFLAGS} -c -o $@ $<

.PHONY: clean
clean:
	rm -f ${EXECS} *.o *.dSYM./
