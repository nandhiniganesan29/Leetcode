import java.util.*;

class Solution {
    public String minWindow(String s, String t) {
        if (s == null || t == null || s.length() < t.length()) return "";

        // Map to store frequency of characters in t
        int[] map = new int[128];
        for (char c : t.toCharArray()) map[c]++;

        int start = 0, end = 0, minStart = 0, minLen = Integer.MAX_VALUE;
        int counter = t.length(); // Number of characters in t still needed

        while (end < s.length()) {
            char cEnd = s.charAt(end);
            if (map[cEnd] > 0) counter--; // Found a required character
            map[cEnd]--; // Decrease frequency (can go negative for non-t chars)
            end++;

            // When the window contains all characters from t
            while (counter == 0) {
                // Update minimum window
                if (end - start < minLen) {
                    minLen = end - start;
                    minStart = start;
                }

                char cStart = s.charAt(start);
                map[cStart]++; // Put character back into the requirement map
                // If it's a character from t and map is positive, we need it again
                if (map[cStart] > 0) counter++; 
                
                start++; // Shrink the window from the left
            }
        }

        return minLen == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLen);
    }
}
