#include "calculator.hpp"

double parse_number(const std::string &expression) {
    std::string sign = "+";
    std::string integerPart;
    std::string fractionalPart;
    size_t i = 0;

    // Step 1: Read sign
    if (expression[i] == '+' || expression[i] == '-') {
        sign = expression[i];
        ++i;
    }

    // Step 2: Extract integer part
    while (i < expression.size() && expression[i] != '.') {
        integerPart += expression[i++];
    }

    // Step 3: Extract fractional part if exists
    if (i < expression.size() && expression[i] == '.') {
        ++i;
        while (i < expression.size()) {
            fractionalPart += expression[i++];
        }
    }

    // Remove leading zeros in integer part
    size_t first_non_zero = integerPart.find_first_not_of('0');
    if (first_non_zero != std::string::npos) {
        integerPart = integerPart.substr(first_non_zero);
    } else {
        integerPart = "0";
    }

    // Convert integer part
    double result = 0.0;
    for (char c : integerPart) {
        result = result * 10 + (c - '0');
    }

    // Convert fractional part
    double frac = 0.0;
    double divisor = 10.0;
    for (char c : fractionalPart) {
        frac += (c - '0') / divisor;
        divisor *= 10;
    }

    result += frac;
    if (sign == "-") {
        result = -result;
    }

    return result;
}
