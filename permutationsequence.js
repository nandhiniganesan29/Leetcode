import java.util.ArrayList;
import java.util.List;

class Solution {
    public String getPermutation(int n, int k) {
        List<Integer> numbers = new ArrayList<>();
        int[] factorial = new int[n + 1];
        StringBuilder sb = new StringBuilder();

        // 1. Create a list of numbers to use: [1, 2, 3, ..., n]
        // 2. Precompute factorial values
        int sum = 1;
        factorial[0] = 1;
        for (int i = 1; i <= n; i++) {
            sum *= i;
            factorial[i] = sum;
            numbers.add(i);
        }

        // Adjust k to be 0-indexed for easier math
        k--;

        // Build the string digit by digit
        for (int i = 1; i <= n; i++) {
            // Determine the index of the next digit
            int index = k / factorial[n - i];
            sb.append(numbers.get(index));
            
            // Remove the used digit from the list
            numbers.remove(index);
            
            // Update k for the next iteration
            k %= factorial[n - i];
        }

        return sb.toString();
    }
}
