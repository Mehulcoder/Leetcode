class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxEndingHere = nums[0], maxTillNow = nums[0], n = nums.size();
		if (nums.size() == 0) return 0;
		for (int i = 1; i < n; ++i) {
			maxEndingHere = max(nums[i], nums[i] + maxEndingHere);
			maxTillNow = max(maxEndingHere, maxTillNow);
		}

		return maxTillNow;
	}
};