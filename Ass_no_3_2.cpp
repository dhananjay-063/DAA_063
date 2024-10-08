#include <iostream>
using namespace std;

// Returns true if there is a subset of element[]
// with sum equal to the targetSum
bool isSubsetWithSum(int element[], int n, int targetSum)
{
    // table[i][j] will be true if there is a subset of element[0..i-1]
    // with sum equal to j
    bool table[n + 1][targetSum + 1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        table[i][0] = true;

    // If targetSum is not 0 and the set is empty, then answer is false
    for (int i = 1; i <= targetSum; i++)
        table[0][i] = false;

    // Fill the table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= targetSum; j++) {
            if (j < element[i - 1])
                table[i][j] = table[i - 1][j];
            else
                table[i][j] = table[i - 1][j] || table[i - 1][j - element[i - 1]];
        }
    }

    return table[n][targetSum];
}

// Driver code
int main()
{
    int element[] = { 1, 2, 3 };
    int targetSum = 3;
    int n = sizeof(element) / sizeof(element[0]);

    if (isSubsetWithSum(element, n, targetSum))
        cout << "Found a subset with the given sum";
    else
        cout << "No subset with the given sum";

    return 0;
}
