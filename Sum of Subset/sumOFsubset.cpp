#include <bits/stdc++.h>
using namespace std;
bool subsetSum(vector<int> arr, int n, int sum)
{
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= sum)
    {
        dp[0][arr[0]] = true;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool take = false;
            if (arr[i] <= j)
            {
                take = dp[i - 1][j - arr[i]];
            }
            bool notTake = dp[i - 1][j];
            dp[i][j] = take || notTake;
        }
    }
    return dp[n - 1][sum];
}
int main()
{
    cout << "Enter array size: " << endl;
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the sum value: " << endl;
    int sum;
    cin >> sum;
    bool ans = subsetSum(arr, n, sum);
    if (ans)
    {
        cout << "Subset with sum " << sum << " exits" << endl;
    }
    else
    {
        cout << "Subset with sum " << sum << " does not exits" << endl;
    }
    return 0;
}
