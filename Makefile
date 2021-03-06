DEBUG=no
EXEC=solver
ifeq (${DEBUG},yes)
	#debug
	CXXFLAGS=-O0 -g --std=c++11 -fopenmp
	LDFLAGS=-fopenmp
else
	#release
	CXXFLAGS=-O2 -std=c++11 -fopenmp
	LDFLAGS=-fopenmp
endif

SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)
ifeq ($(DEBUG),no)
	rm -rf *.o
endif

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)


.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

