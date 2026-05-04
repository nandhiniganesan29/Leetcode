import java.util.*;

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        // Convert list to set for O(1) lookup
        Set<String> dict = new HashSet<>(wordList);
        if (!dict.contains(endWord)) return 0;

        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);
        
        int level = 1; // Start with level 1 (the beginWord itself)

        while (!queue.isEmpty()) {
            int size = queue.size();
            
            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                String curr = queue.poll();
                
                // If we reached the endWord, return the current length
                if (curr.equals(endWord)) return level;

                // Try changing every character of the current word
                char[] chars = curr.toCharArray();
                for (int j = 0; j < chars.length; j++) {
                    char originalChar = chars[j];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        
                        chars[j] = c;
                        String nextWord = new String(chars);
                        
                        // If the new word is in the dictionary, add to queue and remove from dict
                        if (dict.contains(nextWord)) {
                            queue.offer(nextWord);
                            dict.remove(nextWord); // Acts as "visited" set
                        }
                    }
                    // Restore character for the next position's transformation
                    chars[j] = originalChar;
                }
            }
            level++;
        }

        return 0; // No path found
    }
}
