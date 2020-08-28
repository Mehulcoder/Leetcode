class Solution {
public:
	int n;
	static bool mySort(vector<int> &a, vector<int> &b) {
		return a[1] < b[1];
	}

	int findLongestChain(vector<vector<int>>& arr) {
		n = pairs.size();

		sort(arr.begin(), arr.end(), mySort);

		int ans = 1;
		int j = 0;
		for (int i = 1; i < n; ++i) {
			if (arr[i].first > arr[j].second) {
				ans++;
				j = i;
			}
		}

		return ans;
	}
};