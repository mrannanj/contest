CPP_SOURCE := $(shell find -name '*.cpp')
C_SOURCE := $(shell find -name '*.c')

CPP_TARG := $(patsubst ./%.cpp, %, $(CPP_SOURCE))
C_TARG := $(patsubst ./%.c, %, $(C_SOURCE))
TARG := $(CPP_TARG) $(C_TARG)

W := -Wall -Wextra -Wno-unused

MAKEFLAGS := -j4

.PHONY: all clean ignore

all: $(TARG)

$(CPP_TARG):%: %.cpp
	$(CXX) $(W) -rdynamic -g3 -std=c++11 $^ -o $@

$(C_TARG):%: %.c
	$(CC) $(W) -rdynamic -g3 -std=c99 $^ -o $@

clean:
	$(RM) $(TARG)

ignore:
	@echo "$(TARG)" | sed -e 's:\s\+:\n:g'

