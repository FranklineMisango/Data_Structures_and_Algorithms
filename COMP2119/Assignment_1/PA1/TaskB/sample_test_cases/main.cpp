#include <iostream>
#include "function.h"


Pair find_value_indices(int n, int b, Matrix M) {
    int row = 0;
    int col = n - 1;
    Pair result = {-1, -1};

    while (row < n && col >= 0) {
        int current = M.getElement(row, col);
        if (current == b) {
            result.first = row + 1;
            result.second = col + 1;
            break;
        } else if (current < b) {
            row++;
        } else {
            col--;
        }
    }

    return result;
}
int main() {
    int n, b;
    std::cin >> n >> b;

    Matrix M(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = 0;
            std::cin >> x;
            M.setElement(i, j, x);
        }
    }
    Pair indices = find_value_indices(n, b, M);
    std::cout << indices.first << std::endl;
    std::cout << indices.second << std::endl;
    return 0;
}