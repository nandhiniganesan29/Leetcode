int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        // Update the minimum price found so far
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } 
        // Calculate profit if we sold today and update maxProfit
        else {
            int currentProfit = prices[i] - minPrice;
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
        }
    }

    return maxProfit;
}
