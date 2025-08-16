#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
 
    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
 
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
 
    // Base case: first book
    for (int tar = 0; tar <= x; tar++) {
        if (prices[0] <= tar) dp[0][tar] = pages[0];
    }
 
    // Fill the rest
    for (int i = 1; i < n; i++) {
        for (int tar = 0; tar <= x; tar++) {
            int notTake = dp[i - 1][tar]; 
            int take = 0;
            if (tar >= prices[i]) {
                take = pages[i] + dp[i - 1][tar - prices[i]];
            }
            dp[i][tar] = max(notTake, take);
        }
    }
 
    cout << dp[n - 1][x] << endl;
    return 0;
}
