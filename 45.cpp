class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		int i = 0, jumps = 0, currMax = 0, newMax = 0;

		while (i < n - 1) {
			newMax = max(newMax, i + nums[i]);
			if (i == currMax) {
				jumps++;
				currMax = newMax;
			}
			i++;
		}

		return jumps;

	}
};