class Solution {
public:

	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int n;
	vector<vector<vector<int>>> dp;
	const int buffer = 1;
	int dis(int a, int b) {
		if (a == -1 || b == -1) return 0;
		int row1 = a / 6, row2 = b / 6;
		int col1 = a % 6, col2 = b % 6;

		int ans = (abs(row2 - row1) + abs(col2 - col1));
		return ans;
	}

	int get(string &word, int start, int pos1, int pos2) {
		if (start >= n) return 0;
		int curr = word[start] - 'A';

		int &ans = dp[start][pos1 + buffer][pos2 + buffer];
		if (ans != -1) return ans;

		int ans1 = dis(curr, pos1) + get(word, start + 1, word[start] - 'A', pos2);
		int ans2 = dis(curr, pos2) + get(word, start + 1, pos1, word[start] - 'A');

		return ans = min(ans1, ans2);
	}

	int minimumDistance(string wordd) {
		n = wordd.size();
		dp.resize(n, vector<vector<int>>(30, vector<int>(30, -1)));
		return get(wordd, 0, -1, -1);
	}
};