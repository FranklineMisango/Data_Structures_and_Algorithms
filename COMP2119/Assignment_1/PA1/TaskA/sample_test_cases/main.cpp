#include <iostream>
#include <string>

using namespace std; 

string generate_Sn(int n) {
    if (n == 1) {
        return "1";
    } else {
        string prev_Sn = generate_Sn(n - 1);
        string inverted = prev_Sn;
        for (char &bit : inverted) {
            bit = (bit == '0') ? '1' : '0';
        }
        string reversed_inverted(inverted.rbegin(), inverted.rend());
        return reversed_inverted + "0" + prev_Sn;
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    string Sn = generate_Sn(n);

    if (k < 1 || k > Sn.length()) {
        cout << "Invalid value of k." << endl;
    } else {
        char kth_bit = Sn[k - 1]; 
        cout << kth_bit;
    }

    return 0;
}
