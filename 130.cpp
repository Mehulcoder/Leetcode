class Solution {
public:
	int n, m;
	vector<vector<bool>> visited;
	void get(int i, int j, vector<vector<char>> &board) {

	}

	void solve(vector<vector<char>>& board) {
		n = board.size();
		m = board[0].size();
		visited.resize(n, vector<bool>(m, 0));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (!visited[i][j] && board[i][j] == 'X') {
					get(i, j, board);
				}
			}
		}

	}
};