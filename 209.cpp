class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		vector<int> pre(n + 1, 0);
		for (int i = 1; i < n + 1; ++i) {
			pre[i] = nums[i - 1];
			pre[i] += pre[i - 1];
		}

		int mini = n + 3;
		int i = 0, j = 1;
		while (j < n + 1) {
			if (pre[j] >= pre[i] + s) {
				mini = min(mini, j - i);
				i++;
			} else {
				j++;
			}
		}
		return (mini == n + 3 ? 0 : mini);

	}
};