class Solution {
public:
      static const int MOD = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> prevUp(m, 0), prevDown(m, 0);

        // base case: length = 2
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(i < j) prevUp[j]++;
                else if(i > j) prevDown[j]++;
            }
        }

        // build from length = 3 to n
        for(int len = 3; len <= n; len++){
            vector<int> currUp(m, 0), currDown(m, 0);

            vector<int> prefUp(m+1, 0), prefDown(m+1, 0);

            for(int i = 0; i < m; i++){
                prefUp[i+1] = (prefUp[i] + prevUp[i]) % MOD;
                prefDown[i+1] = (prefDown[i] + prevDown[i]) % MOD;
            }

            for(int x = 0; x < m; x++){
                // from DOWN → need smaller
                currUp[x] = prefDown[x];

                // from UP → need larger
                currDown[x] = (prefUp[m] - prefUp[x+1] + MOD) % MOD;
            }

            prevUp = currUp;
            prevDown = currDown;
        }

        long long ans = 0;
        for(int i = 0; i < m; i++){
            ans = (ans + prevUp[i] + prevDown[i]) % MOD;
        }

        return ans;
    }
};