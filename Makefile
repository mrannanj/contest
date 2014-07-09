CPP_SOURCE := $(shell find -name '*.cpp')
C_SOURCE := $(shell find -name '*.c')

CPP_TARG := $(patsubst ./%.cpp, %, $(CPP_SOURCE))
C_TARG := $(patsubst ./%.c, %, $(C_SOURCE))
TARG := $(CPP_TARG) $(C_TARG)

W := -Wextra -Wall -Wno-unused -Wno-unused-result

MAKEFLAGS := -j4

.PHONY: all clean ignore

all: $(TARG)

$(CPP_TARG):%: %.cpp
	$(CXX) $(W) -O2 -g -std=gnu++11 $^ -o $@

$(C_TARG):%: %.c
	$(CC) $(W) -O2 -g -std=c99 $^ -o $@

clean:
	$(RM) $(TARG)

ignore:
	@echo "$(TARG)" | sed -e 's:\s\+:\n:g'

