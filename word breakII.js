import java.util.*;

class Solution {
    // Map to store memoized results for each substring starting index
    Map<Integer, List<String>> memo = new HashMap<>();

    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict);
        return backtrack(s, wordSet, 0);
    }

    private List<String> backtrack(String s, Set<String> wordSet, int start) {
        // If we have already calculated sentences for this index, return them
        if (memo.containsKey(start)) {
            return memo.get(start);
        }

        List<String> validSentences = new ArrayList<>();

        // Base case: if we reached the end of the string, return a list with an empty string
        if (start == s.length()) {
            validSentences.add("");
            return validSentences;
        }

        // Try every possible end index for the current word
        for (int end = start + 1; end <= s.length(); end++) {
            String word = s.substring(start, end);

            if (wordSet.contains(word)) {
                // Get all valid sentences that can be formed from the remaining substring
                List<String> nextSentences = backtrack(s, wordSet, end);

                for (String next : nextSentences) {
                    // If next is empty, it means we reached the end of the string
                    String space = next.isEmpty() ? "" : " ";
                    validSentences.add(word + space + next);
                }
            }
        }

        // Store result in memo and return
        memo.put(start, validSentences);
        return validSentences;
    }
}
