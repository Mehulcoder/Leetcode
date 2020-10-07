class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		int i = 0, jumps = 0, currMax = 0, newMax = 0;

		while (i < n - 1) {
			newMax = max(newMax, i + nums[i]);
			if (i == currMax) {
				jumps++;
				if (currMax == newMax) return -1;
				currMax = newMax;
			}
			i++;
		}
		return jumps;
	}

	int minTaps(int n, vector<int>& ranges) {
		n = n + 1;
		vector<int> jumps(n, 0);
		for (int i = 0; i < n; ++i) {
			int l = max(0, i - ranges[i]);
			int r = min(n, i + ranges[i]);
			jumps[l] = max(jumps[l], r - l);
		}

		return jump(jumps);
	}
};