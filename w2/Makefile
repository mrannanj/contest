SOURCE := $(shell find -name '*.c' -o -name '*.cpp')
TARGET := $(patsubst ./%.cpp, %, $(SOURCE))
.PHONY: all clean ignore

all: $(TARGET)

%: %.cpp
	g++ -Wall -Wextra -Wno-unused-variable -std=c++11 $< -o $@

clean:
	rm -f $(TARGET)

ignore:
	@echo $(TARGET) | sed -e 's: :\n:g'

