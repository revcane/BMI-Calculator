# BMI Calculator – CSE 4283/6283 Assignment 2

## Test-Driven Development in C++

## Prerequisites

- **OS:** Windows 10 or Linux/macOS
- **Compiler:** g++ with C++17 support

## Usage

### Build all

```bash
make all
```

### Run the app

```bash
make run
# or run directly:
./build/bmi_app
build\bmi_app.exe
```

### Run unit tests

```bash
make run_tests
# or run directly:
./build/test_runner
```

### Run buggy app unit tests

```bash
make run_tests_buggy
# or directly:
./build/test_runner_buggy
```

## BMI Formula

```
BMI = (weight_lbs / height_inches^2) * 703
```

Source: http://extoxnet.orst.edu/faqs/dietcancer/web2/twohowto.html

### BMI Categories

| BMI         | Category      |
| ----------- | ------------- |
| < 18.5      | Underweight   |
| 18.5 – 24.9 | Normal weight |
| 25.0 – 29.9 | Overweight    |
| => 30.0     | Obese         |
