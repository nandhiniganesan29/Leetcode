class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, pair<int, int>>> events;

        // Create start and end events
        for (auto& b : buildings) {
            int left = b[0];
            int right = b[1];
            int height = b[2];

            // Start event: negative height
            events.push_back({left, {-height, right}});

            // End event: positive height
            events.push_back({right, {height, 0}});
        }

        // Sort events by x-coordinate
        sort(events.begin(), events.end());

        // {height, ending_x}
        priority_queue<pair<int, int>> pq;

        // Ground level
        pq.push({0, INT_MAX});

        vector<vector<int>> result;
        int previousHeight = 0;

        for (auto& event : events) {
            int x = event.first;
            int height = event.second.first;
            int right = event.second.second;

            if (height < 0) {
                // Building starts
                pq.push({-height, right});
            }

            // Remove buildings that have ended
            while (!pq.empty() && pq.top().second <= x) {
                pq.pop();
            }

            // Current maximum height
            int currentHeight = pq.top().first;

            // Skyline changes
            if (currentHeight != previousHeight) {
                result.push_back({x, currentHeight});
                previousHeight = currentHeight;
            }

            // For end event, we don't need to explicitly
            // add anything because expired buildings are removed
        }

        return result;
    }
};
