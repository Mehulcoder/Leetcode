class Solution {
public:
	vector<vector<int>> dp;
	int get(vector<int> &nums, int sum, int end) {
		if (sum < -1000 || sum > 1000 || end < 0) return 0;
		if (end == 0) return ((nums[end] == sum) + (nums[end] == -sum));
		int &ans = dp[1000 + sum][end];
		if (ans != -1) return ans;
		ans = get(nums, sum - nums[end], end - 1) + get(nums, sum + nums[end], end - 1);
		return ans;
	}
	int findTargetSumWays(vector<int>& nums, int S) {
		int n = S, m = nums.size();
		dp.resize(2005, vector<int>(25, -1));
		return get(nums, S, m - 1);
	}
};