import java.util.Stack;

class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        stack.push(-1); // Sentinel value to handle the left boundary
        int maxArea = 0;

        for (int i = 0; i < heights.length; i++) {
            // While current height is smaller than the height at stack top
            while (stack.peek() != -1 && heights[stack.peek()] >= heights[i]) {
                int currentHeight = heights[stack.pop()];
                int currentWidth = i - stack.peek() - 1;
                maxArea = Math.max(maxArea, currentHeight * currentWidth);
            }
            stack.push(i);
        }

        // Process remaining bars in the stack
        while (stack.peek() != -1) {
            int currentHeight = heights[stack.pop()];
            int currentWidth = heights.length - stack.peek() - 1;
            maxArea = Math.max(maxArea, currentHeight * currentWidth);
        }

        return maxArea;
    }
}
