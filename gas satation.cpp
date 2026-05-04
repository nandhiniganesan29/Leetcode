int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int total_gas = 0;
    int total_cost = 0;
    int current_tank = 0;
    int start_index = 0;

    for (int i = 0; i < gasSize; i++) {
        total_gas += gas[i];
        total_cost += cost[i];
        
        current_tank += gas[i] - cost[i];

        // If current tank drops below 0, we cannot start at or before index i
        if (current_tank < 0) {
            // Reset start index to the next station
            start_index = i + 1;
            // Reset tank for the new start point
            current_tank = 0;
        }
    }

    // If total gas is less than total cost, completion is impossible
    if (total_gas < total_cost) {
        return -1;
    }

    return start_index;
}
