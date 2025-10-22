#include <iostream>
#include <vector>   
using namespace std;

int n = 5;

int generate(int index, int mask, vector<int>& curr) {
    if (index == n) {
        for (int x : curr) cout << x << " ";
        cout << "\n";
        return 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) { // if i not used yet
            curr.push_back(i);
            count += generate(index + 1, mask | (1 << i), curr);
            curr.pop_back(); // backtrack
        }
    }
    return count;
}

int main() {
    vector<int> curr;
    int total = generate(0, 0, curr);
    cout << "Total permutations: " << total << "\n";
    return 0;
}
