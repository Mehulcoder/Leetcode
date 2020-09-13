class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int n, m;
	vector<vector<bool>> visited;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	vector<vector<int>> mat;
	queue<pair<int, int>> q;
	bool found = 0;

	//Used for marking one of the island with some color, say '2'
	//This function also pushes them into the queue for expansion using BFS
	void dfs(vector<vector<int>> &A, int i, int j) {
		visited[i][j] = 1;
		mat[i][j] = 2;
		q.push({i, j});
		found = 1;

		for (int k = 0; k < 4; ++k) {
			int ni = dx[k] + i;
			int nj = dy[k] + j;

			if (ni >= 0 && nj >= 0 && ni < n && nj < m && !visited[ni][nj] && A[ni][nj] == 1) {
				dfs(A, ni, nj);
			}
		}

		return;
	}

	//This simply expands the members in our queue, and once any of their
	//neighbour encounters a memeber of other island, it returns the steps.
	int bfs() {
		int step = 0;
		while (!q.empty()) {
			//This amount of members will result in same steps
			int sz = q.size();
			while (sz--) {
				auto tp = q.front();
				int i = tp.first;
				int j = tp.second;

				q.pop();
				for (int k = 0; k < 4; ++k) {
					int ni = dx[k] + i;
					int nj = dy[k] + j;
					if (ni >= 0 && nj >= 0 && ni < n && nj < m && !visited[ni][nj]) {
						if (mat[ni][nj] == 1) return step;
						else {
							q.push({ni, nj});
							visited[ni][nj] = 1;
						}
					}

				}
			}
			step++;
		}

		return -1;
	}

	int shortestBridge(vector<vector<int>>& A) {
		n = A.size();
		m = A[0].size();
		mat = A;
		visited.resize(n, vector<bool>(m, 0));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (!visited[i][j] && A[i][j] == 1 && !found) {
					dfs(A, i, j);
				}
			}
		}

		return bfs();

	}
};