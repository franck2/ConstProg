DEBUG=yes
EXEC=solver
ifeq (${DEBUG},yes)
	#debug
	CFLAGS=-W -Wall -Wextra -pedantic -O0 -g --std=c++0x
	LDFLAGS=
else
	#release
	CFLAGS=-O2 -std=c++0x
	LDFLAGS=
endif

SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)
ifeq ($(DEBUG),no)
	@echo "Clean project"
	@rm -rf *.o
endif

$(EXEC): $(OBJ)
	@echo "${CXX} $@"
	@$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp %.h
	@echo "${CXX} -o $@ -c $<"
	@$(CXX) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@echo "Clean object file"
	@rm -rf *.o

mrproper: clean
	@echo "Delete Binary"
	@rm -rf $(EXEC)

