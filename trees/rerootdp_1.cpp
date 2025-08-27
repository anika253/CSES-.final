// DISTANCE QUERIES 2


#include <iostream>
#include <vector>
using namespace std;

const int N = 200001;
int n;
vector<int> adj[N];
int subtree_size[N];
long long ans[N];

// First DFS: compute subtree sizes and ans[1]
void dfs1(int u, int p) {
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        subtree_size[u] += subtree_size[v];
        ans[1] += subtree_size[v];  // distance from root increases by size of subtree
    }
}

// Second DFS: rerooting
void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        ans[v] = ans[u] - subtree_size[v] + (n - subtree_size[v]);
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, 0);  // compute subtree sizes + ans[1]
    dfs2(1, 0);  // compute all other answers

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
