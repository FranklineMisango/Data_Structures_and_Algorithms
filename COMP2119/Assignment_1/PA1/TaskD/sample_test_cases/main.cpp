#include <iostream>
#include <vector>
#include <algorithm>  // Include the algorithm header
using namespace std;

int countValidInsertions(int n, string s, int k) {
    vector<int> balance(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '(') {
            balance[i] = balance[i - 1] + 1;
        } else {
            balance[i] = balance[i - 1] - 1;
        }
    }

    int maxBalance = *max_element(balance.begin(), balance.end());
    int minBalance = *min_element(balance.begin(), balance.end());

    int validInsertions = 0;

    for (int i = 0; i <= n; i++) {
        int newBalance = balance[i] + 1;

        if (0 <= newBalance && newBalance <= k && newBalance >= minBalance && newBalance <= maxBalance) {
            validInsertions++;
        }
    }

    return validInsertions;
}

int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;

    int validInsertions = countValidInsertions(n, s, k);
    cout << validInsertions << endl;

    return 0;
}
