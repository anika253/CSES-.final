#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int dist(pair<int,int> a, pair<int,int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int n; cin >> n;
    vector<pair<int,int>> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;

    int N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n, 1e9));

    // Base case
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = 0;

    // DP transitions
    for (int mask = 0; mask < N; mask++) {
        for (int last = 0; last < n; last++) {
            if (!(mask & (1 << last))) continue;

            for (int next = 0; next < n; next++) {
                if (mask & (1 << next)) continue; // already visited

                int newMask = mask | (1 << next);
                int cost = dp[mask][last] + dist(pts[last], pts[next]);
                dp[newMask][next] = min(dp[newMask][next], cost);
            }
        }
    }

    int ans = INT_MAX;
    for (int last = 0; last < n; last++) {
        ans = min(ans, dp[(1 << n) - 1][last]);
    }
    cout << ans << "\n";
}
