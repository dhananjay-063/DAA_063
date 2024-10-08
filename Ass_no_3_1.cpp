#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// This code calculates the number of ways to make a sum
int findCombinations(int coins[], int n, int targetSum)
{
    // dpArray[i] will store the number of ways to get the sum i
    int dpArray[targetSum + 1];

    // Initialize all dpArray values as 0
    memset(dpArray, 0, sizeof(dpArray));

    // Base case (If the targetSum is 0)
    dpArray[0] = 1;

    // Iterate through all coins and update dpArray
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= targetSum; j++)
            dpArray[j] += dpArray[j - coins[i]];
            
    return dpArray[targetSum];
}

// Driver Code
int main()
{
    int coins[] = { 1, 2, 3 };
    int n = sizeof(coins) / sizeof(coins[0]);
    int targetSum = 5;
    cout << findCombinations(coins, n, targetSum);
    return 0;
}
