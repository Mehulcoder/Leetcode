class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}
	int totalHammingDistance(vector<int>& nums) {
		int n = nums.size(), ans = 0;
		for (int i = 0; i < 32; ++i) {
			int oneCount = 0;
			for (int j = 0; j < n; ++j) {
				if (((1 << i) & (nums[j])) != 0)oneCount++;
			}

			ans += (oneCount * (n - oneCount));
		}

		return ans;
	}
};