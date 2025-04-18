#include <gtest/gtest.h>

int main(int argc, char **argv) {
    // Initialize Google Test
    ::testing::InitGoogleTest(&argc, argv);

    // Run all the tests and return the result
    return RUN_ALL_TESTS();
}
