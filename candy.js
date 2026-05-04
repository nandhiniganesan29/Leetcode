class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        if (n <= 1) return n;

        int[] candies = new int[n];
        
        // Step 1: Every child starts with 1 candy
        for (int i = 0; i < n; i++) {
            candies[i] = 1;
        }

        // Step 2: Left-to-Right Pass
        // Ensure child i has more than child i-1 if rating is higher
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 3: Right-to-Left Pass
        // Ensure child i has more than child i+1 if rating is higher
        // We take the max to satisfy both left and right constraints
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = Math.max(candies[i], candies[i + 1] + 1);
            }
        }

        // Step 4: Sum up the candies
        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
}
