class Solution {
public:
	int n;
	vector<vector<int>> dp;
	vector<int> num;
	int get(int start, int end) {
		if (start == end) return num[end];
		if (start > end) return 0;
		int &ans = dp[start][end];
		if (ans != -1) return ans;
		int temp = get(start + 1, end - 1);
		int op1 = num[start] + get(start + 2, end);
		int op2 = num[start] + temp;
		int op3 = num[end] + get(start, end - 2);
		int op4 = num[end] + temp;

		return ans = max(min(op1, op2), min(op3, op4));
	}

	bool PredictTheWinner(vector<int>& nums) {
		num = nums; n = nums.size();
		dp.resize(n + 1, vector<int>(n + 1, -1));
		int sum = 0;
		for (int i = 0; i < n; ++i) sum += nums[i];
		int firstScore = get(0, n - 1);
		return (firstScore >= sum - firstScore) ? 1 : 0;
	}
};