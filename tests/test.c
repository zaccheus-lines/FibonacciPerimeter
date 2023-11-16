#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "../perimeter.h"

// Custom assert function that prints an error message before asserting.
void assertWithMessage(int condition, const char* message) {
    if (!condition) {
        fprintf(stderr, "Error: %s\n", message);
        assert(condition);  // Terminate the program if condition false.
    }
}

// Function to run regression tests,
// comparing the actual output of perimeter()
// with expected results.
void runRegTest(int n, ull expr) {
    ull act = perimeter(n);

    // Print the expected and actual results.
    printf("For numbers: %d Expected: %llu Got: %llu\n", n, expr, act);
    if (act != expr) {
        // Print a detailed error message.
        printf("Expected %llu, got %llu\n", expr, act);
    }
    // Assert with a message if the test fails.
    assertWithMessage(act == expr, "Regression Test Failed.");


// Function to run property tests on the perimeter function.
void runPropTests(int n) {
    // Calculate the perimeter for n.
    ull act = perimeter(n);

    // Check that the result is non-negative.
    assertWithMessage(act >= 0, "Positivity Test Failed");

    // Check that the result is divisible by 4.
    assertWithMessage(act % 4 == 0, "Divisibility Test Failed");

    // Check that the perimeter is strictly increasing.
    assertWithMessage(
        perimeter(n+1) > perimeter(n), "Monotonicity Test Failed");

    // Check that calling perimeter again gives the same result.
    assertWithMessage(act == perimeter(n), "Consistency Test Failed");
}



// Function to generate a random number within a specified range.
int random_n() {
    // Seed the random number generator with the current time.
    srand(time(NULL));

    int min = 2;  // Minimum value for the random number.
    int max = 10000;   // Maximum value for the random number.

    // Generate the random number.
    int rand_int = min + rand_r() % (max - min + 1);

    // Generate the random number.
    return rand_int;
}

// Main function to run all tests.
int main() {
    // Run regression tests with various values of n and expected results.
    runRegTest(-1, 0);
    runRegTest(0, 4);
    runRegTest(1, 8);
    runRegTest(5, 80);
    runRegTest(7, 216);
    runRegTest(20, 114624);
    runRegTest(30, 14098308);
    // Run property tests 10 times with random values of n.
    for (int i = 0; i <= 10; i++)  {
            runPropTests(random_n());
        }

    // Run regression tests with various values of n and expected results.
    printf("Property tests passed");

    return 0;  // Return 0 to indicate successful completion of the program.
}

