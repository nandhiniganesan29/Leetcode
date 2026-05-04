import java.util.*;

class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> res = new ArrayList<>();
        Set<String> dict = new HashSet<>(wordList);
        if (!dict.contains(endWord)) return res;

        // BFS to find the shortest distance to each word
        Map<String, Integer> distances = new HashMap<>();
        Map<String, List<String>> adj = new HashMap<>();
        bfs(beginWord, endWord, dict, distances, adj);

        // DFS to collect all shortest paths
        List<String> path = new ArrayList<>();
        path.add(beginWord);
        dfs(beginWord, endWord, adj, distances, path, res);

        return res;
    }

    private void bfs(String begin, String end, Set<String> dict, Map<String, Integer> distances, Map<String, List<String>> adj) {
        Queue<String> queue = new LinkedList<>();
        queue.offer(begin);
        distances.put(begin, 0);

        boolean found = false;
        while (!queue.isEmpty() && !found) {
            int size = queue.size();
            // To ensure we find all paths of the same shortest length, process by level
            Set<String> visitedThisLevel = new HashSet<>();
            for (int i = 0; i < size; i++) {
                String curr = queue.poll();
                int currDist = distances.get(curr);

                List<String> neighbors = getNeighbors(curr, dict);
                for (String neighbor : neighbors) {
                    if (!distances.containsKey(neighbor)) {
                        distances.put(neighbor, currDist + 1);
                        queue.offer(neighbor);
                        visitedThisLevel.add(neighbor);
                    }
                    
                    // Build the adjacency list for the shortest path graph
                    if (distances.get(neighbor) == currDist + 1) {
                        adj.computeIfAbsent(curr, k -> new ArrayList<>()).add(neighbor);
                        if (neighbor.equals(end)) found = true;
                    }
                }
            }
        }
    }

    private List<String> getNeighbors(String word, Set<String> dict) {
        List<String> neighbors = new ArrayList<>();
        char[] chars = word.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            char old = chars[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == old) continue;
                chars[i] = c;
                String next = new String(chars);
                if (dict.contains(next)) neighbors.add(next);
            }
            chars[i] = old;
        }
        return neighbors;
    }

    private void dfs(String curr, String end, Map<String, List<String>> adj, Map<String, Integer> distances, List<String> path, List<List<String>> res) {
        if (curr.equals(end)) {
            res.add(new ArrayList<>(path));
            return;
        }
        if (!adj.containsKey(curr)) return;

        for (String next : adj.get(curr)) {
            path.add(next);
            dfs(next, end, adj, distances, path, res);
            path.remove(path.size() - 1); // backtrack
        }
    }
}
