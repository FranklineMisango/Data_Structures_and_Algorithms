#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <vector>
using namespace std;


class Matrix {
private:

    int rows = 1000;
    int cols = 1000;
    // Access and modify elements
    //A[0][0] = 42;
    //int A[500][500];
    int n;
	int threshold;
	int count;
    vector<vector<int>> A;
public:
    // Constructor
    Matrix(int size) : A(size, vector<int>(size, 0)) {
        n = size;
        threshold = 3 * n;
        count = 0;
    }

    // Function to assign values to the array A
    void setElement(int i, int j, int value) {
        if (i >= 0 && i < n && j >= 0 && j < n) {
            A[i][j] = value;
        } else {
            std::cout << "Invalid indices!" << std::endl;
        }
    }

    // Function to access the value at array A[i][j]
    int getElement(int i, int j) {
		count++;
		if (n >= 850){
			if (count >= threshold){
				exit(-1);
			}
		}
		
        if (i >= 0 && i < n && j >= 0 && j < n) {
            return A[i][j];
        } else {
            std::cout << "Invalid indices!" << std::endl;
            return 0;
        }
    }

    // Function to access the value of n
    int getSize() {
        return n;
    }
};

struct Pair {
    int first;
    int second;
};

Pair find_value_indices(int n, int b, Matrix M);
#endif