class Solution {
public:
        Solution() {
                ios::sync_with_stdio(false);
                cin.tie(NULL);
                cout.tie(NULL);
        }

        int dx[4] = { -1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int maxDistance(vector<vector<int>>& grid) {

                int n = grid.size();
                int m = grid[0].size();
                int ans[n][m];
                bool vis[n][m];

                memset(ans, -1,  sizeof(ans));
                memset(vis, 0, sizeof(vis));


                queue<vector<int>> q;
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                                if (grid[i][j] == 1) {
                                        q.push({i, j, 0});
                                        vis[i][j] = 1;
                                        ans[i][j] = -1;
                                }
                        }
                }

                int anss = -1;
                while (!q.empty()) {
                        auto tp = q.front();
                        q.pop();

                        int i = tp[0];
                        int j = tp[1];
                        int dis = tp[2];

                        if (ans[i][j] == -1) {
                                ans[i][j] = dis;
                                anss = max(anss, ans[i][j]);
                        } else {
                                continue;
                        }

                        for (int k = 0; k < 4; k++) {
                                int ni = i + dx[k];
                                int nj = j + dy[k];

                                if (ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj] && ans[ni][nj] == -1) {
                                        q.push({ni, nj, dis + 1});
                                        vis[ni][nj] = 1;
                                }
                        }
                }


                return (anss == 0 ? -1 : anss);


        }
};