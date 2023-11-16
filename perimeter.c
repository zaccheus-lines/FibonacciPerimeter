#include "perimeter.h"
#include <stdio.h>
#include "perimeter.h"

// Function to calculate the total perimeter of
// Fibonacci squares up to the (n+1)-th square.
// The perimeter of each square is 4 times its
// side length, which is a Fibonacci number.

ull perimeter(int n) {
    // If n is negative, perimeter is 0.
    if (n < 0) return 0;

    // If n is 0, the perimeter is 4 (the first square).
    if (n == 0) return 4;

    // Initialise the first two Fibonacci numbers.
    ull fib1 = 1, fib2 = 1;

    // Initialise the sum and fib3.
    ull sum = 0;
    ull fib3 = fib1 + fib2;

    // Calculate the perimeter of the remaining squares up to the (n+1)-th.
    for (int i = 0; i < n; i++) {
        // Add the perimeter of the current square to the sum.
        sum += 4 * fib3;

        // Calculate the next Fibonacci number.
        fib3 = fib1 + fib2;

        // Update the previous two Fibonacci numbers.
        fib1 = fib2;
        fib2 = fib3;
    }
    return sum;
}

