#include <iostream>
#include <fstream>
#include <string>

#include "calculator.hpp"

// Helper function to validate the string as a valid double
bool is_valid_double(const std::string& str) {
    size_t i = 0;
    bool has_decimal_point = false;

    // Step 1: Check if the string has a leading sign
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }

    // Step 2: Ensure we have at least one digit before the decimal point
    if (i < str.length() && (str[i] >= '0' && str[i] <= '9')) {
        i++;
    } else {
        return false;
    }

    // Step 3: Validate the integer part (digits before a decimal point)
    while (i < str.length() && (str[i] >= '0' && str[i] <= '9')) {
        i++;
    }

    // Step 4: Handle optional decimal point
    if (i < str.length() && str[i] == '.') {
        has_decimal_point = true;
        i++;
    }

    // Step 5: Ensure we have at least one digit after the decimal point if it's present
    if (has_decimal_point) {
        if (i < str.length() && (str[i] >= '0' && str[i] <= '9')) {
            i++;
        } else {
            return false;
        }
    }

    // Step 6: Ensure we only have digits and one optional decimal point
    while (i < str.length() && (str[i] >= '0' && str[i] <= '9')) {
        i++;
    }

    return i == str.length(); // Return true if all characters are processed
}

// String-based addition for validated double numbers
std::string add_strings(const std::string& a, const std::string& b) {
    // We can assume both a and b are valid doubles in string form here
    double num1 = parse_number(a);
    double num2 = parse_number(b);

    double result = num1 + num2;

    // Convert result back to string (assuming result can be formatted as a double string)
    std::string result_str = std::to_string(result);
    return result_str;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Failed to open file: " << argv[1] << "\n";
        return 1;
    }

    std::string line;
    const std::string fixedDouble = "-123.456";  // The number to add

    while (std::getline(infile, line)) {
        if (is_valid_double(line)) {
            std::string result = add_strings(line, fixedDouble);
            std::cout << line << " + " << fixedDouble << " = " << result << '\n';
        } else {
            std::cout << "Invalid double: " << line << '\n';
        }
    }

    return 0;
}
