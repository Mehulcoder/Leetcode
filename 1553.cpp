class Solution {
public:
	map<int, int> dp;
	int get(int n) {
		if (n <= 1) return n;
		if (dp.find(n) != dp.end()) return dp[n];

		int ans1 = n % 2 + get(n / 2);
		int ans2 = n % 3 + get(n / 3);
		return dp[n] = 1 + min(ans1, ans2);
	}

	int minDays(int n) {
		return get(n);
	}
};