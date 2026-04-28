import java.util.*;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        int index = 0;

        while (index < words.length) {
            int count = words[index].length();
            int last = index + 1;
            
            // Step 1: Greedily find how many words fit in the current line
            while (last < words.length) {
                if (count + 1 + words[last].length() > maxWidth) break;
                count += 1 + words[last].length();
                last++;
            }

            StringBuilder sb = new StringBuilder();
            int diff = last - index - 1; // Number of gaps between words

            // Step 2: Handle the special cases: last line or only one word in the line
            if (last == words.length || diff == 0) {
                for (int i = index; i < last; i++) {
                    sb.append(words[i]);
                    if (i < last - 1) sb.append(" ");
                }
                // Right-pad the remaining spaces
                while (sb.length() < maxWidth) sb.append(" ");
            } else {
                // Step 3: Distribute spaces for fully-justified lines
                int totalSpaces = maxWidth - (count - diff); // Total space characters needed
                int spacesPerGap = totalSpaces / diff;
                int extraSpaces = totalSpaces % diff; // Leftmost gaps get an extra space

                for (int i = index; i < last; i++) {
                    sb.append(words[i]);
                    if (i < last - 1) {
                        int spacesToApply = spacesPerGap + (i - index < extraSpaces ? 1 : 0);
                        for (int s = 0; s < spacesToApply; s++) sb.append(" ");
                    }
                }
            }

            result.add(sb.toString());
            index = last;
        }

        return result;
    }
}
