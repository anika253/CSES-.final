#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MOD = 1'000'000'007;
 
int main() {
   
 
    int n;
    if (!(cin >> n)) return 0;
 
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (j <= i) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
