class Solution {
public:

	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	const int N = 2e4 + 10;
	const int offset = 1e4 + 2;
	vector<int> arr, dp;
	vector<set<int>> index;
	// unordered_map<int, set<int>> index;
	int d;
	int get(int end) {
		if (end == 0) return 1;

		int &ans = dp[end];
		if (ans != -1) return ans;

		if (arr[end] - d < 0) return ans = 1;
		if (index[arr[end] - d].size() == 0) return ans = 1;
		auto it = index[arr[end] - d].lower_bound(end);
		if (it != index[arr[end] - d].begin()) it--;
		else return ans = 1;

		return ans = 1 + get(*it);
	}

	int longestSubsequence(vector<int>& a, int difference) {
		arr = a;
		int n = a.size();
		for (int i = 0; i < n; ++i) {
			arr[i] += offset;
		}
		d = difference;
		dp.resize(n, -1);
		index.resize(N);
		for (int i = 0; i < n; ++i) {
			index[arr[i]].insert(i);
		}

		for (int i = n - 1; i >= 0; --i) {
			if (dp[i] == -1) get(i);
		}

		return (*max_element(dp.begin(), dp.end()));
	}
};