#include <iostream>
#include <vector>
using namespace std;

const int N = 200001, M = 20;
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
        if (x != p) dfs(x, curr);
    }
}

int kthParent(int u, int k) {
    for (int i = M - 1; i >= 0; i--) {
        if (k & (1 << i)) {
            u = par[u][i];
            if (u == 0) break;
        }
    }
    return u;
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);

    // Bring u up to the same depth as v
    int diff = dep[u] - dep[v];
    u = kthParent(u, diff);

    if (u == v) return u;

    // Lift both until just below LCA
    for (int i = M - 1; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }

    // Their parent is the LCA
    return par[u][0];
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
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

    return 0;
}
