CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
GTEST    = -lgtest -lgtest_main -lpthread

SRC_DIR  = src
TEST_DIR = tests
BUILD    = build

.PHONY: tests clean run_tests

$(BUILD):
	mkdir -p $(BUILD)

tests: $(BUILD) $(SRC_DIR)/bmi.cpp $(TEST_DIR)/test_bmi.cpp
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/bmi.cpp $(TEST_DIR)/test_bmi.cpp -o $(BUILD)/test_runner $(GTEST)

run_tests: tests
	./$(BUILD)/test_runner

clean:
	rm -rf $(BUILD)