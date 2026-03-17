CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
GTEST    = -lgtest -lgtest_main -lpthread

SRC_DIR  = src
TEST_DIR = tests
BUILD    = build

.PHONY: app run tests tests_buggy clean run_tests run_tests_buggy

$(BUILD):
	mkdir -p $(BUILD)

app: $(BUILD) $(SRC_DIR)/bmi.cpp $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/bmi.cpp $(SRC_DIR)/main.cpp -o $(BUILD)/bmi_app

run: app
	./$(BUILD)/bmi_app

tests: $(BUILD) $(SRC_DIR)/bmi.cpp $(TEST_DIR)/test_bmi.cpp
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/bmi.cpp $(TEST_DIR)/test_bmi.cpp -o $(BUILD)/test_runner $(GTEST)

run_tests: tests
	./$(BUILD)/test_runner

tests_buggy: $(BUILD) $(SRC_DIR)/bmi_bshift.cpp $(TEST_DIR)/test_bmi.cpp
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/bmi_bshift.cpp $(TEST_DIR)/test_bmi.cpp -o $(BUILD)/test_runner_buggy $(GTEST)

run_tests_buggy: tests_buggy
	./$(BUILD)/test_runner_buggy

clean:
	rm -rf $(BUILD)