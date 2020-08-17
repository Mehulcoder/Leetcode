class Solution {
public:

	vector<int> maxPos;
	vector<int> maxNeg;
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		maxPos.resize(n, 1);
		maxNeg.resize(n, 1);
		maxPos[0] = maxNeg[0] = nums[0];
		for (int i = 0; i < n; i++) {
			if (nums[i] >= 0) {
				maxPos[i] = max(nums[i], nums[i] * maxPos[i - 1]);
				maxNeg[i] = min(nums[i], nums[i] * maxNeg[i - 1]);
			} else {
				maxPos[i] = max(nums[i], nums[i] * maxNeg[i - 1]);
				maxNeg[i] = min(nums[i], nums[i] * maxPos[i - 1]);
			}
		}

		return *max_element(maxPos.begin(), maxPos.end());
	}
};