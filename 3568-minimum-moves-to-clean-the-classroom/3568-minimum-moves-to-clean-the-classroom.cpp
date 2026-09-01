class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
     int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        int litterCount = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        if (litterCount == 0)
            return 0;

        int masks = 1 << litterCount;
        int fullMask = masks - 1;
        int E = energy + 1;

        long long totalStates = 1LL * m * n * masks * E;
        vector<bool> visited(totalStates, false);

        auto getId = [&](int r, int c, int mask, int e) {
            return (((long long)r * n + c) * masks + mask) * E + e;
        };

        queue<array<int, 4>> q;
        q.push({sr, sc, 0, energy});
        visited[getId(sr, sc, 0, energy)] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, currEnergy] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    if (currEnergy == 0)
                        continue;

                    int newEnergy = currEnergy - 1;
                    int newMask = mask;

                    if (classroom[nr][nc] == 'L')
                        newMask |= (1 << id[nr][nc]);

                    if (classroom[nr][nc] == 'R')
                        newEnergy = energy;

                    long long stateId = getId(nr, nc, newMask, newEnergy);

                    if (!visited[stateId]) {
                        visited[stateId] = true;
                        q.push({nr, nc, newMask, newEnergy});
                    }
                }
            }

            moves++;
        }

        return -1;   
    }
};