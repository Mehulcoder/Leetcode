class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};

	int shortestPath(vector<vector<int>>& grid, int k) {
		int n = grid.size();
		int m = grid[0].size();
		queue<vector<int>> q;
		q.push({0, 0, 0, 0});

		int seen[45][45];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				seen[i][j] = INT_MAX;
			}
		}
		while (!q.empty()) {
			vector<int> temp = q.front();
			q.pop();

			if (temp[0] == n - 1 && temp[1] == m - 1 && temp[2] <= k) {
				return temp[3];
			}


			for (int kk = 0; kk < 4; ++kk) {
				int ni = dx[kk] + temp[0];
				int nj = dy[kk] + temp[1];
				if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
					int dis = temp[3] + 1;
					int thorn = temp[2] + (grid[ni][nj] == 1);
					if (thorn >= seen[ni][nj] || thorn > k) continue;
					seen[ni][nj] = thorn;
					q.push({ni, nj, thorn, dis});
				}

			}

		}
		return -1;
	}

};