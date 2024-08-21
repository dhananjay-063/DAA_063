#include <iostream>
using namespace std;


int maxProfit(int*  prices, int numDays) {
    int totalProfit = 0;
    int currentDay = numDays - 1;

    
    while (currentDay > 0) {
        int previousDay = currentDay - 1;

       
        while (previousDay >= 0 && prices[currentDay] > prices[previousDay]) {
            totalProfit += (prices[currentDay] - prices[previousDay]);
            previousDay--;
        }

        
        currentDay = previousDay;
    }

    
    return totalProfit;
}


int main() {
    
    int stockPrices[] = { 2, 3, 5 };
    int numDays = sizeof(stockPrices) / sizeof(stockPrices[0]);

    
    cout << "Maximum Profit: " << maxProfit(stockPrices, numDays) << endl;

    return 0;
}
