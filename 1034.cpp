class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int r1, c1, col, m, n, prevCol;
	vector<vector<int>> gridd;
	vector<vector<bool>> visited;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	void fil(int i, int j, vector<vector<int>>& grid) {
		for (int k = 0; k < 4; ++k) {
			int ni = dx[k] + i;
			int nj = dy[k] + j;

			if (ni >= n || ni < 0 || nj < 0 || nj >= m  || prevCol != grid[ni][nj]) {
				gridd[i][j] = col;
				return;
			}

		}

		return;
	}

	void dfs(int i, int j, vector<vector<int>>& grid) {
		visited[i][j] = 1;
		fil(i, j, grid);

		for (int k = 0; k < 4; ++k) {
			int ni = dx[k] + i;
			int nj = dy[k] + j;

			if (ni < n && ni >= 0 && nj >= 0 && nj < m && !visited[ni][nj] && prevCol == gridd[ni][nj]) {
				dfs(ni, nj, grid);
			}
		}

		return;
	}

	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
		r1 = r0;
		c1 = c0;
		n = grid.size();
		if (n == 0) return {};

		m = grid[0].size();
		col = color;
		gridd = grid;
		prevCol = grid[r0][c0];
		visited.resize(n, vector<bool>(m, 0));
		dfs(r0, c0, grid);

		return gridd;
	}
};