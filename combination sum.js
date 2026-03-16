import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), candidates, target, 0);
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> tempList, int[] candidates, int remain, int start) {
        if (remain < 0) return; // Base case: exceeded the target
        else if (remain == 0) result.add(new ArrayList<>(tempList)); // Target reached
        else {
            for (int i = start; i < candidates.length; i++) {
                tempList.add(candidates[i]);
                // We pass 'i' as the start index because we can reuse the same element
                backtrack(result, tempList, candidates, remain - candidates[i], i);
                // Backtrack: remove the last element to try other combinations
                tempList.remove(tempList.size() - 1);
            }
        }
    }
}
