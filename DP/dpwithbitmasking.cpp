#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5;

    auto f = [&](int index, int mask, vector<int> v, auto &&F) -> int {
        if (index == n) {
            for (auto &i : v) {
                cout << i << " ";
            }
            cout << "\n";
            return 1; // Count this permutation
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                v.push_back(i);
                count += F(index + 1, mask | (1 << i), v, F);
                v.pop_back();
            }
        }

        return count;
    };

    int total_permutations = f(0, 0, {}, f);
    cout << "Total permutations: " << total_permutations << "\n";

    return 0;
}
