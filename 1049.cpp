class Solution {
public:

	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int s = 0;
	int sum = 0;
	int n = 0;
	int ans = 0;
	vector<vector<int>> dp;
	vector<int> stones;

	int get(int maxSum, int pos) {
		if (maxSum < 0) return 0;
		if (pos == 0) {
			if (maxSum == stones[pos] || maxSum == 0) return 1;
			else return 0;
		}

		int &anss = dp[maxSum][pos];
		if (anss != -1) return anss;

		return anss = (get(maxSum - stones[pos], pos - 1) || get(maxSum, pos - 1));
	}

	int lastStoneWeightII(vector<int>& stone) {
		stones = stone;

		//Choose the elements so that the sum <= s/2
		n =  stones.size();
		for (int i = 0; i < n; ++i) {
			s += stones[i];
			sum += stones[i];
		}

		s /= 2;

		dp.resize(s + 5, vector<int>(n + 1, -1));

		for (int i = 0; i <= s; ++i) {
			if (get(i, n - 1)) {
				ans = max(ans, i);
			}
		}

		return sum - 2 * ans;
	}
};