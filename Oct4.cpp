class Solution {
public:
	static bool mySort(vector<int> &a, vector<int> &b) {
		if (a[1] > b[1]) return 1;
		if (a[1] == b[1]) return a[0] < b[0];
		return 0;
	}

	int removeCoveredIntervals(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), mySort);
		int n = intervals.size();

		int minLeft = INT_MAX, ans = n;
		for (int i = 0; i < n; ++i) {
			int left = intervals[i][0];
			int right = intervals[i][1];

			if (left >= minLeft) ans--;
			minLeft = min(left, minLeft);
		}

		return ans;
	}
};