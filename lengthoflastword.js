class Solution {
    public int lengthOfLastWord(String s) {
        // Trim trailing spaces and split by spaces
        s = s.trim();
        
        // Find the index of the last space
        int lastSpaceIndex = s.lastIndexOf(' ');
        
        // The length is the difference between the string length and the last space position
        return s.length() - lastSpaceIndex - 1;
    }
}
