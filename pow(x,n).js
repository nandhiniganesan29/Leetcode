class Solution {
    public double myPow(double x, int n) {
        // Handle negative exponent
        // Use a long to prevent overflow when n = Integer.MIN_VALUE
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        double currentProduct = x;

        // Binary Exponentiation logic
        while (N > 0) {
            // If the current exponent is odd, multiply the result by currentProduct
            if (N % 2 == 1) {
                result *= currentProduct;
            }
            // Square the base and halve the exponent
            currentProduct *= currentProduct;
            N /= 2;
        }

        return result;
    }
}
