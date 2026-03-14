/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    let maxLen = 0;
    let stack = [-1]; // Initialize with -1 to handle the base case

    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            stack.push(i); // Push the index of the opening bracket
        } else {
            stack.pop(); // Pop the matching opening bracket
            
            if (stack.length === 0) {
                // If stack is empty, this ')' is a new boundary
                stack.push(i);
            } else {
                // Current index minus the index of the previous boundary
                maxLen = Math.max(maxLen, i - stack[stack.length - 1]);
            }
        }
    }

    return maxLen;
};
