class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}
	int minSumOfLengths(vector<int>& arr, int target) {
		int left = 0, bestTillNow = INT_MAX, ans = INT_MAX, sum = 0, n = arr.size();
		vector<int> best(n, INT_MAX);
		for (int i = 0; i < n; ++i) {
			sum += arr[i];
			while (sum > target) {
				sum -= arr[left];
				left++;
			}
			if (sum == target) {
				if (left > 0 && best[left - 1] != INT_MAX) {
					ans = min(ans, best[left - 1] + i - left + 1);
				}
				bestTillNow = min(bestTillNow, i - left + 1);
			}
			best[i] = bestTillNow;
		}

		return ((ans == INT_MAX) ? (-1) : ans);
	}
};