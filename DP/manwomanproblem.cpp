#include <iostream>
#include <vector>
using namespace std;

int f(int i, int mask, int n, vector<vector<int>> &dp, vector<vector<int>> &grid) {
    if (i == n) return 1;

    if (dp[i][mask] != -1) return dp[i][mask];

    int ways = 0;
    for (int j = 0; j < n; j++) {
        if (((1 << j) & mask) == 0 && grid[i][j] == 1) {
            ways += f(i + 1, mask | (1 << j), n, dp, grid);
        }
    }
    return dp[i][mask] = ways;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n, vector<int>((1 << n), -1));
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = f(0, 0, n, dp, grid);
    cout << ans << endl;
}
