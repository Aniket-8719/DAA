#include <iostream>
#define MAX 10
using namespace std;

struct product {
    int product_num;
    int profit;
    int weight;
};

int main() {
    product P[MAX];
    int i, j, total_product, capacity;
    float value = 0;

    cout << "Enter the number of items: ";
    cin >> total_product;
    if (total_product > MAX) {
        cout << "Total products should be less than or equal to " << MAX << endl;
        return 1;
    }

    cout << "Enter capacity of the knapsack: ";
    cin >> capacity;
    cout << "\n";

    for (i = 0; i < total_product; ++i) {
        P[i].product_num = i + 1;
        cout << "Enter profit and weight of product " << i + 1 << ": ";
        cin >> P[i].profit >> P[i].weight;
    }
    int dp[MAX + 1][capacity + 1];

    for (i = 0; i <= total_product; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (P[i - 1].weight <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - P[i - 1].weight] + P[i - 1].profit);
            } else {
                dp[i][j] = dp[i - 1][j]; 
            }
        }
    }

    i = total_product;
    j = capacity;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            cout << "Take product " << P[i - 1].product_num << " : " << P[i - 1].weight << " UNITS" << endl;
            value += P[i - 1].profit;
            j -= P[i - 1].weight;
        }
        i--;
    }

    cout << "The knapsack value is: " << value << endl;

    return 0;
}