#include<iostream>
#include<climits>
using namespace std;

// O(n) Time Complexity
int bestBuySellStocks(int *prices, int n) {
    int bestBuy[100000]; // array size 10^5
    bestBuy[0] = INT_MAX;

    for(int i = 1; i < n; i++) {
        bestBuy[i] = min(bestBuy[i-1], prices[i - 1]);
    }

    int maxProfit = 0;
    for(int i = 0; i < n; i++) {
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }

    return maxProfit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);

    int result = bestBuySellStocks(prices, n);
    cout<<"Maximun Profit => "<<result<<endl;

    return 0;
}