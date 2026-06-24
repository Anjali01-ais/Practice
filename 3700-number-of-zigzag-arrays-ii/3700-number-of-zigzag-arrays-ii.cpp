class Solution {
public:
     static const int MOD = 1e9 + 7;
     vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int size) {
        vector<vector<long long>> C(size, vector<long long>(size, 0));
        for (int i = 0; i < size; i++) {
            for (int k = 0; k < size; k++) {
                if (A[i][k] == 0) continue; 
                for (int j = 0; j < size; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
    vector<vector<long long>> power(vector<vector<long long>> A, long long p, int size) {
        vector<vector<long long>> res(size, vector<long long>(size, 0));
        for (int i = 0; i < size; i++) res[i][i] = 1; // Identity Matrix

        while (p > 0) {
            if (p & 1) res = multiply(res, A, size);
            A = multiply(A, A, size);
            p >>= 1;
        }
        return res;
    }
    int zigZagArrays(int n, int l, int r) {
    int m = r - l + 1;
        int size = 2 * m;
        vector<long long> baseVec(size);
        for (int j = 0; j < m; j++) {
            baseVec[j] = j;         // up[j]
            baseVec[m + j] = m - j - 1; // down[j]
        }
        vector<vector<long long>> T(size, vector<long long>(size, 0));
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < x; y++) {
                T[x][m + y] = 1;
            }
            for (int y = x + 1; y < m; y++) {
                T[m + x][y] = 1;
            }
        }
        T = power(T, n - 2, size);
        long long ans = 0;
        for (int i = 0; i < size; i++) {
            long long final_state_i = 0;
            for (int j = 0; j < size; j++) {
                final_state_i = (final_state_i + T[i][j] * baseVec[j]) % MOD;
            }
            ans = (ans + final_state_i) % MOD;
        }

        return ans;
    }
};