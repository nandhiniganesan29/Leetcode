class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> dp(cols + 1, 0);
        int maxSide = 0;
        int prev = 0;

        for (int i = 1; i <= rows; i++) {
            prev = 0;

            for (int j = 1; j <= cols; j++) {
                int temp = dp[j];

                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min({
                        dp[j],       // top
                        dp[j - 1],   // left
                        prev         // top-left
                    }) + 1;

                    maxSide = max(maxSide, dp[j]);
                }
                else {
                    dp[j] = 0;
                }

                prev = temp;
            }
        }

        return maxSide * maxSide;
    }
};
