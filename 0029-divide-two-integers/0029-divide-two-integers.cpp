class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long long a = dividend;
        long long b = divisor;

        // Determine sign
        bool negative = (a < 0) ^ (b < 0);

        // Convert to positive
        a = llabs(a);
        b = llabs(b);

        long long quotient = 0;

        // Bit manipulation
        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            quotient += multiple;
        }

        // Apply sign
        if (negative) {
            quotient = -quotient;
        }

        return (int)quotient;
    }
};