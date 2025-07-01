#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

struct Matrix {
    vector<vector<int>> mat;
    int rows, cols;

    Matrix(int r, int c) : rows(r), cols(c) {
        mat.assign(r, vector<int>(c, 0));
    }

    // Identity matrix of size n x n
    static Matrix identity(int n) {
        Matrix I(n, n);
        for (int i = 0; i < n; ++i)
            I.mat[i][i] = 1;
        return I;
    }

    // Matrix multiplication
    Matrix operator*(const Matrix &other) const {
        assert(cols == other.rows);
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.mat[i][j] = (result.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
        return result;
    }

    // Fast exponentiation (only for square matrices)
    Matrix power(int exp) const {
        assert(rows == cols);
        Matrix result = identity(rows);
        Matrix base = *this;
        while (exp > 0) {
            if (exp & 1)
                result = result * base;
            base = base * base;
            exp >>= 1;
        }
        return result;
    }

    // Print matrix (for debugging)
    void print() const {
        for (auto &row : mat) {
            for (auto &val : row)
                cout << val << " ";
            cout << "\n";
        }
    }
};

int32_t main() {
    int n = 2;
    Matrix A(n, n);
    
    // Example matrix: M = [[2, 1], [1, 0]]
    A.mat = {{2, 1}, {1, 0}};

    int exponent = 5;
    Matrix result = A.power(exponent);

    cout << "Matrix raised to power " << exponent << ":\n";
    result.print();

    return 0;
}
