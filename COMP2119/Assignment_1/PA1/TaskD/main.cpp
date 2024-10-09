#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countValidInsertions(int n, string s, int k) {
    vector<int> balance(n, 0);

    int leftBrackets = 0;  
    int rightBrackets = 0;
    int validInsertions = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            leftBrackets++;
        } else {
            rightBrackets++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            balance[i] = 1;
        } else {
            balance[i] = -1;
        }

        if (leftBrackets > rightBrackets) {
            int newBalance = 0;
            int toPop = (leftBrackets - rightBrackets) + 1;
            
            for (int j = i; j < n; j++) {
                newBalance += balance[j];

                if (s[j] == '(') {
                    toPop--;
                }

                if (toPop == 0 && newBalance == 0 && s[j] != '(') {
                    validInsertions++;
                }

                if (toPop <= 0) {
                    break;
                }
            }
        }

        if (s[i] == '(') {
            leftBrackets--;
        } else {
            rightBrackets--;
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
