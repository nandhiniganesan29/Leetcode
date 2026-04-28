import java.util.*;

class Solution {
    public String simplifyPath(String path) {
        Deque<String> stack = new LinkedList<>();
        String[] components = path.split("/");

        for (String directory : components) {
            if (directory.equals(".") || directory.isEmpty()) {
                // Ignore current directory '.' and empty strings from '//'
                continue;
            } else if (directory.equals("..")) {
                // Move up one level by popping from stack
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            } else {
                // It's a valid directory name
                stack.push(directory);
            }
        }

        // Build the result from the bottom of the stack
        StringBuilder result = new StringBuilder();
        if (stack.isEmpty()) return "/";
        
        while (!stack.isEmpty()) {
            result.append("/").append(stack.pollLast());
        }

        return result.toString();
    }
}
