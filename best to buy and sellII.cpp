#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    // We track the minimum cost (negative profit) and maximum profit for both trades
    int buy1 = INT_MIN, sell1 = 0;
    int buy2 = INT_MIN, sell2 = 0;

    for (int i = 0; i < pricesSize; i++) {
        // First transaction: minimize the cost to buy
        if (buy1 < -prices[i]) buy1 = -prices[i];
        
        // First transaction: maximize profit if we sell today
        if (sell1 < buy1 + prices[i]) sell1 = buy1 + prices[i];
        
        // Second transaction: use profit from sell1 to offset cost of buy2
        if (buy2 < sell1 - prices[i]) buy2 = sell1 - prices[i];
        
        // Second transaction: maximize final profit if we sell today
        if (sell2 < buy2 + prices[i]) sell2 = buy2 + prices[i];
    }

    return sell2;
}
