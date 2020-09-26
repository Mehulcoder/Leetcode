class Solution {
public:
	int n;
	int dp[505][505];
	int get(string &s, int i, int j) {
		if (i == j) return 1;
		if (i > j) return 0;

		int &ans = dp[i][j];
		if (ans != -1) return ans;

		if (s[i] == s[j]) {
			return ans = 2 + get(s, i + 1, j - 1);
		} else {
			return ans = max(get(s, i + 1, j), get(s, i, j - 1));
		}
	}

	int get2(string &s, int i, int j) {
		if (i >= j) return 0;

		int &ans = dp[i][j];
		if (ans != -1) return ans;

		if (s[i] == s[j]) {
			return ans = get2(s, i + 1, j - 1);
		} else {
			return ans = 1 + min(get2(s, i + 1, j), get2(s, i, j - 1));
		}
	}

	int minInsertions(string s) {
		//We have to find the longest palindromic subsequence
		n = s.size();
		memset(dp, -1, sizeof(dp));
		// return n - get(s, 0, n - 1);
		return get2(s, 0, n - 1);
	}
};