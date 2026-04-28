class Solution {
    public boolean isNumber(String s) {
        // Trim whitespace from the string
        s = s.trim();
        
        boolean seenDigit = false;
        boolean seenDot = false;
        boolean seenE = false;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (Character.isDigit(c)) {
                seenDigit = true;
            } else if (c == '.') {
                // Dot is invalid if we've already seen another dot or an 'e'
                if (seenDot || seenE) return false;
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                // Exponent is invalid if we haven't seen a digit yet or have seen another 'e'
                if (seenE || !seenDigit) return false;
                seenE = true;
                // Reset seenDigit because we need at least one digit after 'e'
                seenDigit = false;
            } else if (c == '+' || c == '-') {
                // Sign is only valid at the start or immediately after an 'e'
                if (i > 0 && s.charAt(i - 1) != 'e' && s.charAt(i - 1) != 'E') return false;
            } else {
                // Any other character is invalid
                return false;
            }
        }
        
        return seenDigit;
    }
}
