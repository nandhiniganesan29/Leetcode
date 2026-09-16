import java.util.*;

class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> result = new ArrayList<>();
        if (s == null) return result;

        // Queue for BFS and Set to avoid processing duplicate strings
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        queue.add(s);
        visited.add(s);

        boolean foundValidAtThisLevel = false;

        while (!queue.isEmpty()) {
            String current = queue.poll();

            // If a valid string is found, add it to our results
            if (isValid(current)) {
                result.add(current);
                foundValidAtThisLevel = true;
            }

            // If we already found a valid string at this level, 
            // we don't need to generate further states (shorter strings)
            if (foundValidAtThisLevel) continue;

            // Generate all possible states by removing one parenthesis
            for (int i = 0; i < current.length(); i++) {
                char c = current.charAt(i);
                if (c != '(' && c != ')') continue; // Skip non-parentheses characters

                // Create a new string missing the character at index i
                String nextState = current.substring(0, i) + current.substring(i + 1);

                if (!visited.contains(nextState)) {
                    queue.add(nextState);
                    visited.add(nextState);
                }
            }
        }

        return result;
    }

    // Helper method to check if a string has valid parentheses
    private boolean isValid(String str) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c == '(') count++;
            if (c == ')') {
                count--;
                if (count < 0) return false; // More closing than opening
            }
        }
        return count == 0;
    }
}
