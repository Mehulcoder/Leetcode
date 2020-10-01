class Solution {
public:
	int n;
	int findMin(vector<int>& nums) {
		n = nums.size();

		int lo = 0;
		int hi = n - 1;
		int pivotIndex = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			pivotIndex = mid;

			bool ok = 1;
			if (mid > 0) {
				if (nums[mid - 1] < nums[mid]) ok = 0;
			}
			if (mid < n - 1) {
				if (nums[mid + 1] < nums[mid]) ok = 0;
			}
			if (ok) {
				pivotIndex = mid;
				return nums[pivotIndex];
			}


			if (nums[mid] >= nums[0]) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		return nums[0];
	}
};
