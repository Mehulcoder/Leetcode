class Solution {
public:
	int n;
	vector<vector<int>> dp;
	int get(vector<int> &nums, int l, int r) {
		if (l + 1 == r) return 0;

		int &ans = dp[l + 1][r + 1];
		if (ans != -1) return ans;

		ans = 0;
		for (int k = l + 1; k < r; ++k) {
			int temp1 = (l < 0) ? 1 : nums[l];
			int temp2 = (r == n) ? 1 : nums[r];
			ans = max(ans, temp1 * nums[k] * temp2 + get(nums, l, k) + get(nums, k, r));
		}

		return ans;
	}

	int maxCoins(vector<int>& nums) {
		n = nums.size();
		dp.resize(n + 4, vector<int>(n + 4, -1));
		return get(nums, -1, n);
	}


};