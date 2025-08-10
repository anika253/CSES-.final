#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> dp(n + 1, 1e9); // dp[i] = min steps to reduce i to 0
    dp[0] = 0; // 0 already requires 0 steps
    
    for (int i = 1; i <= n; i++) {
        string str = to_string(i);
        for (char c : str) {
            int d = c - '0';
            if (d > 0) { // can't remove 0
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
        }
    }
    
    cout << dp[n] << "\n";
    return 0;
}
