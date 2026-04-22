import java.util.*;

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        
        Arrays.sort(candidates); // Sort to handle duplicates
        backtrack(candidates, target, 0, new ArrayList<>(), result);
        
        return result;
    }

    private void backtrack(int[] candidates, int target, int start,
                           List<Integer> current, List<List<Integer>> result) {
        
        if (target == 0) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int i = start; i < candidates.length; i++) {

            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Stop if element exceeds target
            if (candidates[i] > target) {
                break;
            }

            // Choose element
            current.add(candidates[i]);

            // Move forward (i+1 → use once)
            backtrack(candidates, target - candidates[i], i + 1, current, result);

            // Backtrack
            current.remove(current.size() - 1);
        }
    }
}
