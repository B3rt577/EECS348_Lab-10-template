# Makefile for EECS348-Lab-7

# Set the build directory
BUILD_DIR = build

# The default target will be 'make all' which will build the project and tests
.PHONY: all build tests clean

# 'all' target: builds the project and tests
all: build tests

# 'build' target: generates and compiles the project
build:
	@echo "Building the project..."
	cmake -S . -B $(BUILD_DIR)  # Generate build files with CMake
	cmake --build $(BUILD_DIR)   # Build the project

# 'tests' target: runs the tests
tests:
	@echo "Running tests..."
	cd $(BUILD_DIR) && ./run_tests  # Run the tests executable

# 'clean' target: cleans up the build directory
clean:
	@echo "Cleaning up the build directory..."
	rm -rf $(BUILD_DIR)  # Remove the build directory

