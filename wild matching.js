class Solution {
    public boolean isMatch(String s, String p) {
        int sIdx = 0, pIdx = 0, lastWildcardIdx = -1, sBacktrackIdx = -1;

        while (sIdx < s.length()) {
            // Case 1: Characters match or pattern has '?'
            if (pIdx < p.length() && (p.charAt(pIdx) == '?' || p.charAt(pIdx) == s.charAt(sIdx))) {
                sIdx++;
                pIdx++;
            } 
            // Case 2: Pattern has '*'
            else if (pIdx < p.length() && p.charAt(pIdx) == '*') {
                lastWildcardIdx = pIdx;
                sBacktrackIdx = sIdx;
                pIdx++; // Move pattern pointer, assume '*' matches empty sequence first
            } 
            // Case 3: No match, but we previously encountered a '*'
            else if (lastWildcardIdx != -1) {
                pIdx = lastWildcardIdx + 1; // Reset pattern to just after the last '*'
                sBacktrackIdx++; // Incremental match: '*' matches one more char in s
                sIdx = sBacktrackIdx;
            } 
            // Case 4: No match and no '*' to fall back on
            else {
                return false;
            }
        }

        // Check for remaining characters in pattern (only '*' can match empty end of string)
        while (pIdx < p.length() && p.charAt(pIdx) == '*') {
            pIdx++;
        }

        return pIdx == p.length();
    }
}
