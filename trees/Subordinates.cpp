#include <iostream>
#include <vector>
using namespace std;

int dfs(int node, vector<vector<int>>& adj, vector<int>& subtree) {
    int total = 0;
    for (int v : adj[node]) {
        total += dfs(v, adj, subtree) + 1;
    }
    subtree[node] = total;
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;  
    vector<vector<int>> adj(n + 1);
    vector<int> subtree(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }

    dfs(1, adj, subtree);

    for (int i = 1; i <= n; i++) {
        cout << subtree[i] << (i < n ? ' ' : '\n');
    }

    return 0;
}
