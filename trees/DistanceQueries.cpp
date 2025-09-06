#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5+1;
const int LOG = 18;

vector<vector<int>> up(MAXN+1, vector<int>(LOG+1, -1));
vector<int> depth(MAXN+1);
vector<vector<int>> adj(MAXN+1);

void dfs(int v, int p) {
    up[v][0] = p;
    for(int j = 1; j <= LOG; j++) {
        if(up[v][j-1] != -1)
            up[v][j] = up[up[v][j-1]][j-1];
        else
            up[v][j] = -1;
    }
    for(int u : adj[v]) {
        if(u == p) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
}

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    int diff = depth[a] - depth[b];
    for(int j = LOG; j >= 0; j--) {
        if((diff >> j) & 1)
            a = up[a][j];
        if(a == b) return a;
    }

    for(int j = LOG; j >= 0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0];
}

int distance(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n-1; i++) {  // tree has n-1 edges
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // up is already initialized with -1, but can also reset if needed
    depth[1] = 0;
    dfs(1, -1);

    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << distance(a, b) << "\n";
    }

    return 0;
}
