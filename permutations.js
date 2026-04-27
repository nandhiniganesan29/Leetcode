import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), nums);
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> tempList, int[] nums) {
        // Base case: if the current list size matches the array length, we found a permutation
        if (tempList.size() == nums.length) {
            result.add(new ArrayList<>(tempList));
        } else {
            for (int i = 0; i < nums.length; i++) {
                // If the element is already used, skip it
                if (tempList.contains(nums[i])) continue;
                
                // Add the element and move to the next step
                tempList.add(nums[i]);
                backtrack(result, tempList, nums);
                
                // Remove the last element to backtrack and try the next possibility
                tempList.remove(tempList.size() - 1);
            }
        }
    }
}
