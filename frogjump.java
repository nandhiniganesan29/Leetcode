import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Solution {
    public boolean canCross(int[] stones) {
        // Base case: The first jump must be exactly 1 unit.
        // If the second stone is not at position 1, the frog cannot even make the first jump.
        if (stones[1] != 1) {
            return false;
        }

        // Map to store the stone position and a set of possible jump sizes that can reach it
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for (int stone : stones) {
            map.put(stone, new HashSet<>());
        }

        // Starting point: On the first stone (0), the initial jump size is 0
        map.get(0).add(0);

        // Process each stone sequentially
        for (int i = 0; i < stones.length; i++) {
            int currentStone = stones[i];
            Set<Integer> jumps = map.get(currentStone);

            for (int k : jumps) {
                // The frog can choose to jump k - 1, k, or k + 1 units next
                for (int nextJump = k - 1; nextJump <= k + 1; nextJump++) {
                    if (nextJump > 0) { // Frog can only move forward
                        int nextStone = currentStone + nextJump;
                        
                        // If the target position has a stone, record the jump size used to reach it
                        if (map.containsKey(nextStone)) {
                            map.get(nextStone).add(nextJump);
                        }
                    }
                }
            }
        }

        // If the last stone's set is not empty, it means the frog reached the end
        return !map.get(stones[stones.length - 1]).isEmpty();
    }
}
