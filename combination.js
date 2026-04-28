import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), 1, n, k);
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> current, int start, int n, int k) {
        // Base case: if current combination is the target size k
        if (current.size() == k) {
            result.add(new ArrayList<>(current));
            return;
        }

        // Optimization: only loop while there are enough numbers left to reach size k
        // i <= n - (k - current.size()) + 1
        for (int i = start; i <= n; i++) {
            current.add(i);            // Choose the number
            backtrack(result, current, i + 1, n, k); // Recurse with next number
            current.remove(current.size() - 1); // Undo choice (backtrack)
        }
    }
}
