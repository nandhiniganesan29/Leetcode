import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> result = new ArrayList<>();
        if (num == null || num.length() == 0) {
            return result;
        }
        // Kick off backtracking from index 0
        backtrack(result, new StringBuilder(), num, target, 0, 0, 0);
        return result;
    }

    private void backtrack(List<String> result, StringBuilder path, String num, int target, 
                           int index, long currentVal, long prevEvaluated) {
        
        // Base case: If we have reached the end of the string
        if (index == num.length()) {
            if (currentVal == target) {
                result.add(path.toString());
            }
            return;
        }

        // Try extracting numbers starting from 'index' to the end of the string
        for (int i = index; i < num.length(); i++) {
            // Corner case: Multi-digit numbers cannot start with a leading '0'
            if (i > index && num.charAt(index) == '0') {
                break;
            }

            // Extract the current operand
            String partStr = num.substring(index, i + 1);
            long currNum = Long.parseLong(partStr);
            int len = path.length();

            // Position 0: The first number cannot have a preceding operator
            if (index == 0) {
                path.append(partStr);
                backtrack(result, path, num, target, i + 1, currNum, currNum);
                path.setLength(len); // Backtrack
            } else {
                // Scenario 1: Addition '+'
                path.append("+").append(partStr);
                backtrack(result, path, num, target, i + 1, currentVal + currNum, currNum);
                path.setLength(len); // Backtrack

                // Scenario 2: Subtraction '-'
                path.append("-").append(partStr);
                backtrack(result, path, num, target, i + 1, currentVal - currNum, -currNum);
                path.setLength(len); // Backtrack

                // Scenario 3: Multiplication '*'
                // Precedence trick: Subtract the previously added value, multiply it, and add it back
                path.append("*").append(partStr);
                backtrack(result, path, num, target, i + 1, 
                          (currentVal - prevEvaluated) + (prevEvaluated * currNum), 
                          prevEvaluated * currNum);
                path.setLength(len); // Backtrack
            }
        }
    }
}
