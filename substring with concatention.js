import java.util.*;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        
        List<Integer> result = new ArrayList<>();
        if (s == null || s.length() == 0 || words.length == 0) {
            return result;
        }

        int wordLen = words[0].length();
        int wordCount = words.length;
        int totalLen = wordLen * wordCount;

        Map<String, Integer> wordMap = new HashMap<>();

        for (String word : words) {
            wordMap.put(word, wordMap.getOrDefault(word, 0) + 1);
        }

        for (int i = 0; i <= s.length() - totalLen; i++) {

            Map<String, Integer> seen = new HashMap<>();
            int j = 0;

            while (j < wordCount) {
                int start = i + j * wordLen;
                String part = s.substring(start, start + wordLen);

                if (!wordMap.containsKey(part)) {
                    break;
                }

                seen.put(part, seen.getOrDefault(part, 0) + 1);

                if (seen.get(part) > wordMap.get(part)) {
                    break;
                }

                j++;
            }

            if (j == wordCount) {
                result.add(i);
            }
        }

        return result;
    }
}
