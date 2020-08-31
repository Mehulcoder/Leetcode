class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}


	vector<vector<int>> dp;
	vector<int> arr;
	int n;
	int get(int end, int state) {
		if (end == 0) return 1;

		int &ans = dp[end][state];
		if (ans != -1) return ans;

		ans = 1;
		if (state == 0) {
			if (arr[end] > arr[end - 1]) {
				ans = 1 + get(end - 1, 1);
			} else {
				ans = 1;
			}
		} else {
			if (arr[end] < arr[end - 1]) {
				ans = ans = 1 + get(end - 1, 0);
			} else {
				ans = 1;
			}
		}
		return ans;
	}


	/*
	* 0: this is greater
	* 1: this is smaller
	*/
	int maxTurbulenceSize(vector<int>& A) {
		arr = A; n = arr.size();
		int ans = 1;
		dp.resize(n, vector<int>(2, -1));
		for (int i = n - 1; i >= 0; --i) {
			ans = max({ans, get(i, 0), get(i, 1)});
		}
		return ans;
	}
};