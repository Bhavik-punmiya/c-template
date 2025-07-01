#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

struct Matrix {
    vector<vector<int>> mat;
    int size;

    Matrix(int n) {
        size = n;
        mat.assign(n, vector<int>(n, 0));
    }

    static Matrix identity(int n) {
        Matrix I(n);
        for (int i = 0; i < n; i++)
            I.mat[i][i] = 1;
        return I;
    }

    Matrix operator*(const Matrix &other) const {
        Matrix result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                for (int k = 0; k < size; ++k)
                    result.mat[i][j] = (result.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
        return result;
    }

    Matrix power(int exp) const {
        Matrix result = identity(size);
        Matrix base = *this;
        while (exp > 0) {
            if (exp & 1)
                result = result * base;
            base = base * base;
            exp >>= 1;
        }
        return result;
    }
};

// Fibonacci using matrix exponentiation
int fib(int n) {
    if (n == 0) return 0;
    Matrix M(2);
    M.mat = {{1, 1}, {1, 0}};
    M = M.power(n - 1);
    return M.mat[0][0]; // F(n)
}

int32_t main() {
    int n;
    cin >> n;
    cout << "F(" << n << ") = " << fib(n) << "\n";
    return 0;
}
