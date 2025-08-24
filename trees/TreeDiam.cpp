#include <iostream>
#include <vector>
using namespace std;

const int N = 200001;
vector<int> adj[N];
int farthestNode, maxDist;

void dfs(int u, int p, int dist) {
    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = u;
    }
    for (auto v : adj[u]) {
        if (v != p) dfs(v, u, dist + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // First DFS: from arbitrary node (1)
    maxDist = -1;
    dfs(1, 0, 0);
    int A = farthestNode;

    // Second DFS: from A
    maxDist = -1;
    dfs(A, 0, 0);
    int B = farthestNode;

    cout << "Diameter length: " << maxDist << "\n";
    cout << "Diameter endpoints: " << A << " " << B << "\n";

    return 0;
}
