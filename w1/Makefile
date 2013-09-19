CPP_SOURCE := $(shell find -name '*.cpp')
C_SOURCE := $(shell find -name '*.c')

CPP_TARG := $(patsubst ./%.cpp, %, $(CPP_SOURCE))
C_TARG := $(patsubst ./%.c, %, $(C_SOURCE))

.PHONY: all clean ignore

all: $(CPP_TARG) $(C_TARG)

$(CPP_TARG):%: %.cpp
	g++ -Wall -Wextra -Wno-unused-variable -std=c++11 $< -o $@

$(C_TARG):%: %.c
	gcc -Wall -Wextra -Wno-unused-variable -std=c99 $< -o $@ -lm

clean:
	rm -f $(C_TARG) $(CPP_TARG)

ignore:
	@echo $(CPP_TARG) $(C_TARG) | sed -e 's: :\n:g'

