class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int n = A.size();
		if (n < 3) return 0;
		vector<int> diff, diffCount;
		for (int i = 1; i < n; ++i) diff.push_back(A[i] - A[i - 1]);

		int prevDiff = INT_MAX, count = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (prevDiff != diff[i]) {
				prevDiff = diff[i];
				diffCount.push_back(count);
				count = 0;
			}
			count++;
		}

		int ans = 0;
		diffCount.push_back(count);
		for (int i = 0; i < diffCount.size(); ++i) {
			if (diffCount[i] >= 2) ans += ((diffCount[i]) * (diffCount[i] - 1)) / 2;

		}

		return ans;
	}
};