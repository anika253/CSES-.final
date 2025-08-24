#include <iostream>
#include <vector>
using namespace std;

const int N = 200001, M = 20; // 2e5+1 and ~log2(2e5)
vector<int> adj[N];
int dep[N];
int par[N][M];

void dfs(int curr, int p) {
    dep[curr] = dep[p] + 1;
    par[curr][0] = p;

    for (int j = 1; j < M; j++) {
        par[curr][j] = par[par[curr][j - 1]][j - 1];
    }

    for (auto x : adj[curr]) {
        if (x != p) {
            dfs(x, curr);
        }
    }
}

int kthParent(int u, int k) {
    for (int i = M - 1; i >= 0; i--) {
        if (k & (1 << i)) {
            u = par[u][i];
            if (u == 0) break; // no parent exists
        }
    }
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    dfs(1, 0);

    while (q--) {
        int u, k;
        cin >> u >> k;
        int parent = kthParent(u, k);
        cout << (parent == 0 ? -1 : parent) << "\n";
    }

    return 0;
}
