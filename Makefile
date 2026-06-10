CXX := clang++
MODULE_CXX := /opt/homebrew/opt/llvm/bin/clang++

CXXFLAGS := -std=c++20 -Wall -Wextra -Werror -pedantic -O2 -g -fsanitize=address

BIN_DIR := bin
BUILD_DIR := build

PROGRAMS := aggregates loops unicode bindings constants booleans \
            lambda attributes enums println formatting concepts \
			comparisons orderings utilities algorithms_ranges pipelines \
			subroutines concurrency

.PHONY: all clean format

all: $(PROGRAMS) basic_math

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

%: %.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $(BIN_DIR)/$@

basic_math: | $(BUILD_DIR) $(BIN_DIR)
	$(MODULE_CXX) -std=c++20 -x c++-module --precompile basic_math.ixx -o build/basic_math.pcm
	$(MODULE_CXX) -std=c++20 -c basic_math.cpp -fmodule-file=basic_math=build/basic_math.pcm -o build/basic_math.o
	$(MODULE_CXX) -std=c++20 main.cpp build/basic_math.o -fmodule-file=basic_math=build/basic_math.pcm -o $(BIN_DIR)/basic_math

format:
	/Library/Developer/CommandLineTools/usr/bin/clang-format -i *.cpp *.ixx

clean:
	rm -rf $(BIN_DIR) $(BUILD_DIR) *.o *.pcm
